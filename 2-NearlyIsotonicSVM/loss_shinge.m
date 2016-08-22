function [f, g] = loss_shinge(X, y, w, rho)
% squared hinge loss (rho - yx'*w)_+^2

if nargin == 3, rho = []; end
if isempty(rho), rho = 1; end

sz = size(w);
N = length(y);

X = reshape(X, [], N);
% here comes the margin
res = max(rho - y.*(X'*w(:)),  0);

% normalized loss
f = .5 * (res'*res) / N; 
g = -reshape(X*(res.*y), sz) / N;