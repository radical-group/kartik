from confluent_kafka import Consumer, KafkaError
from pandas import DataFrame
#import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
import random
import numpy as np
from time import time
import timeit
import sys
import time
import json

settings = {
    'bootstrap.servers': '149.165.171.25:9092',
    'group.id': 'mygroup',
    'client.id': 'client-1',
    'enable.auto.commit': True,
    'session.timeout.ms': 6000,
    'default.topic.config': {'auto.offset.reset': 'smallest'}
}

c = Consumer(settings)
c.subscribe(['mytopic'])
number_of_clusters=int(sys.argv[1])

try:
    while True:
        msg = c.poll(0.1)
        if msg is None:
            continue
        elif not msg.error():
            #print('end time:'  + str(time.time()))
            s=msg.value()
            #print(s)
            #s = s.decode("utf-8")
            #js=json.dumps(s)
            #print(type(s))
            s2 = np.loads(s)
            #print(s2)
            #print(type(s2))
            kmeans = KMeans(n_clusters=number_of_clusters,n_jobs=-1).fit(s2)
            print('Clustering ends at:' + str(time.time()))
            centroids = kmeans.cluster_centers_
            print(centroids)
        elif msg.error().code() == KafkaError._PARTITION_EOF:
            print('End of partition reached {0}/{1}'
                  .format(msg.topic(), msg.partition()))
        else:
            print('Error occured: {0}'.format(msg.error().str()))

except KeyboardInterrupt:
    pass

finally:
    c.close()
