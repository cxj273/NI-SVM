function result = perf_aprec(w, X, y)
% returning the average precision on the test data (X, y)
%   w   :  the classifier we evaluating
%   X   :  test covariates, last dim stackes different samples
%   y   :  test labers (binary)

w = w(:);
x = reshape(X, [], length(y));
result = aprec(y, x'*w);
