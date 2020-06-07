from pandas import DataFrame
#import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
import random
import numpy as np
from time import time
import timeit
import sys
import time

number_of_data_points=int(sys.argv[1])
number_of_clusters=int(sys.argv[2])
def get_random_cluster_points(number_points, number_dim):
    mu = np.random.randn()
    sigma = np.random.randn()
    p = sigma * np.random.randn(number_points, number_dim) + mu
    return p

p = get_random_cluster_points(number_of_data_points, 2)

print(time.time())
kmeans = KMeans(n_clusters=number_of_clusters,n_jobs=-1).fit(p)
print(time.time())
centroids = kmeans.cluster_centers_
