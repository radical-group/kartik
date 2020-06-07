from confluent_kafka import Producer
import sys
from pandas import DataFrame
from sklearn.cluster import KMeans
import random
import numpy as np
from time import time
import timeit
import time
import json

number_of_data_points=int(sys.argv[1])
#number_of_clusters=int(sys.argv[2])

def get_random_cluster_points(number_points, number_dim):
    mu = np.random.randn()
    sigma = np.random.randn()
    data_send = sigma * np.random.randn(number_points, number_dim) + mu
    return data_send

data_send = get_random_cluster_points(number_of_data_points, 2)
#print(type(data_send))
#data_send = data_send.tolist()
#print(type(data_send))

data_send_strlist = data_send.dumps()

def acked(err, msg):
    if err is not None:
        print("Failed to deliver message: {0}: {1}"
              .format(msg.value(), err.str()))
    else:
        print("Message produced")

p = Producer({'bootstrap.servers': 'localhost:9092'})
#print(type(format(data_send)))
#print(type(data_send))

#Using dumps, send the data as byte format in the produce function
try:
    print('Message produced at:' + str(time.time()))
    p.produce('mytopic', data_send_strlist, callback=acked)
    p.poll(0.5)

except KeyboardInterrupt:
    pass

p.flush(30)
