# Language Model Training

# Prerequisite

+ Python 2.7
+ gensim
+ Download English wikipedia 

# Language Model Training

```python
model = Word2Vec(sentences, size=100, window=5, min_count=5, workers=4)
```

# Feature Encoding using Fisher Vectors
## Prerequisite
+ vlfeat 0.9.20 http://www.vlfeat.org/
## Encoding
```matlab
[means, covariance, priors] = vl_gmm(data_sample, numCluster);
rep = vl_fisher(data, means, covariance, priors);
```
