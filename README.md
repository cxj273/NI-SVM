# Nearly-Isotonic-SVM

This package implements the approach described in paper ``Semantic Pooling for Complex Event Analysis in Untrimmed Videos''. It depends on Caffe, gensim, vlfeat, and SLEP.

## Usage

+ First, pre-train concept detectors based on improved dense trajectories features. In this paper, we use the following datasets: Trecvid SIN dataset (346 classes), Google Sports(478 classes), UCF101 dataset (101 classes) and YFCC dataset (609 classes). We first extract improved dense trajectory feautres with the code in [0-Prerequisite/00-FeatureExtraction/traj_pipeline] and encode with the Fisher vector representation [70]. Then, on top of the extracted low-level features, the cascade SVM was trained for each semantic concept. The code is located at [0-Prerequisite/01-TrainConceptDetection/distributed-svm/cascade-svm-mr]. Similarly, we extract the IDT features on all shots of each video in the evaluation datasets and apply the concept detectors to derive their semantic representations.

+ To learn the concept relevance, we train a skip-gram model using the English Wikipedia dump. For short phrases consisting of multiple words, we aggregate the word embeddings using Fisher vectors. We use vlfeat to generate the Fisher vector for each phrase. After normalizing the length of respective vector representations, we compute the cosine distance between the event description and each concept name, which measures the relevance of the concept to the event of interest.

+ Semantic Pooling. We define the semantic saliency score of each video shot as a weighted combination of the concept probability vector and the concept relevance vector. We conduct semantic pooling using the semantic scores, using the code in [1-SemanticSaliency].

```matlab
function ori_pooling =  ss_pooling(ori, cd, rel)
```

+ NI-SVM

```matlab
function ap = nisvm(fea, y, lambda, gamma, ind, fea_te, y_te)
% fea: C by S by N matrix
% C: number of concept detectors
% S: number of shots
% N: number of videos
% y: N by 1 vector

% lambda: total variation norm [0.001 0.01 0.1 1]
% gamma: squared l2 norm [0.001 0.01 0.1 1]
% ind: nonnegative W
``` 

+ Multi-class NI-SVM

```matlab
function mf1 = nisvm_m(fea, Y, S, lambda, gamma, ind, mu, fea_te, Y_te, Ste)
% fea: d by m by n matrix
% d: # of CNN features
% m: # of shots
% n: # of videos
% k: # of events
% S: saliency score, m by n by k matrix
% lambda: total variation norm
% gamma: squared l2 norm
% ind: nonnegative W?
% mu: smoothing parameter
```

# References
+ Xiaojun Chang, Yi Yang, Eric P. Xing and Yao-Liang Yu, **Complex Event Detection using Semantic Saliency and Nearly-Isotonic SVM**, International Conference on Machine Learning 2015.
+ Xiaojun Chang, Yao-Liang Yu, Yi Yang and Eric P. Xing, **Semantic Pooling for Complex Event Analysis in Untrimmed Videos**, IEEE Transactions on Pattern Analysis and Machine Intelligence 2016. [Under Minor Revision]
