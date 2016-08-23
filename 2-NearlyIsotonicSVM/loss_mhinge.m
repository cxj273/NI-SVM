function [f, G] = loss_mhinge(X, Y, W, P, mu)
	% X: d x (m*n) data matrix
	% Y: n x k labels
	% W: d x m x k weight matrix
	% P: (m*n) x k permutation matrix
    % mu: smoothing parameter mu

	% f: objective value, scalar
	% G: gradient, d x m x k tensor

if nargin == 4, mu = 1; end	

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

margin = (Pred - Y) / mu;
% % shift for numerical stability
% mm = max(margin, [], 2);
% exp_margin = exp( margin - repmat(mm, 1, k) );
%margin = min(max(margin, -30), 30);
exp_margin = exp( margin );
% objective
f = mu * mean( log( sum( exp_margin, 2) ) ) - mean( sum(Pred .* Y, 2) );
%f = f + mu * (mean(mm) + log(k));

% gradient, use for-loop to save space
G = zeros(d*m, k);
Q = exp_margin ./ repmat(sum(exp_margin, 2), 1, k);
for e = 1:k
	% permute the data wrt the current event
	Xe = X(:, P(:,e));
	Xe = reshape(Xe, d*m, n);
	G(:,e) = Xe * (Q(:,e) - Y(:,e)) / n;
end
G = reshape(G, d, m, k);
