function [Z, r, ub] = prox_iso_m(G, W, eta, lambda, gamma, ind)
%GOAL    This is the multiclass version of prox_iso.m

if nargin < 2,  error('prox_iso_m needs at least 2 inputs'); end
if ~exist('eta',   'var')   || isempty(eta),   eta     = 1; end
if ~exist('ind',   'var')  || isempty(ind),    ind    = [1 1 1 1]; end
if ~exist('gamma', 'var')  || isempty(gamma),  gamma  = 0; end
if ~exist('lambda', 'var') || isempty(lambda), lambda = 1; end

Z = zeros(size(W));
r = 0; 
ub = 0;
for ii = 1:size(W, 3)
    g = G(:,:,ii); 
    w = W(:,:,ii);
    [Z(:,:,ii), ri, ubi] = prox_iso(g, w, eta, lambda, gamma, ind);
    r = r + ri; 
    ub = ub + ubi;
end