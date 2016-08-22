function [f, g] = loss_l2(X, y, w)

sz = size(w);
N = length(y);

X = reshape(X, [], N);
res = X'*w(:) - y;

% normalized loss
f = .5 * (res'*res) / N; 
g = reshape(X*res, sz) / N;