function [mf1, M, prec, rec, f1] = perf_confusion(W, X, Y, P)
% returning the confusion matrix on the test data (X, Y)
	% W: d x m x k weight matrix
    % X: d x (m*n) test data matrix
	% Y: n x k labels
	% P: (m*n) x k permutation matrix
	%
	% M: confusion matrix, true x pred
	% prec: precision, k x 1
	% rec : recall,    k x 1
	% f1  : f1 measure,k x 1

n = size(Y, 1);
[d, m, k] = size(W);

W = reshape(W, [], k);

Pred = zeros(n, k);
for e = 1:k
	% permute the data wrt the current event
	Xe = X(:, P(:,e));
	Xe = reshape(Xe, d*m, n);
	% prediction matrix n x k
	Pred(:, e) = Xe' * W(:, e);
end

[junk, pred] = max(Pred, [], 2);

Yhat = sparse(1:n, pred, ones(1,n));

M = Y' * Yhat;
prec = diag(M) ./ (sum(M, 1)'+eps);
rec = diag(M) ./ (sum(M, 2) + eps);
f1 = harmmean([prec, rec], 2);
mf1 = mean(f1);