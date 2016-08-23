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

[d, m, n] = size(fea);
[junk, k] = size(Y);
for ii = 1:n
    fea(:,:,ii) = fea(:,:,ii) ./ norm(fea(:,:,ii), 'fro');
end
fea = reshape(fea, d, m*n);
Y = ( Y == repmat(max(Y, [], 2) ,1 ,k) );

% permutation, each column corresponds to an event
[Sd, P] = sort(S, 1, 'descend');
inc = 0:m:m*(n-1);
P = P + repmat(inc, [m, 1, k]);
P = reshape(P, m*n, k);

loss = @(W)         loss_mhinge(fea, Y, W, P, mu);
prox = @(G, W, eta) prox_iso_m(G, W, eta, lambda, gamma, ind);
perf = @(W)         perf_confusion(W, fea, Y, P);

%x = reshape(X, d*m, n);
%opt.init_eta = N / svds(x*x', 1);
%opt.stepsize_rule = '';
opt.acc = 0; 
opt.init_eta = 1;
opt.verbose = 0;
opt.stepsize_rule = 'ls';


W0 = randn(d, m, k);
W = FISTA(loss, prox, perf, W0, opt);


%====== test data ========
% n: total number of test videos
for ii = 1:n
    fea_te(:,:,ii) = fea_te(:,:,ii) ./ norm(fea_te(:,:,ii), 'fro');
end
fea_te = reshape(fea_te, d, m*n);
Y_te = ( Y_te == repmat(max(Y_te, [], 2) ,1 ,k) );

[Sd, Pte] = sort(Ste, 1, 'descend');
inc = 0:m:m*(n-1);
Pte = Pte + repmat(inc, m, 1, k);
Pte = reshape(Pte, m*n, k);

[mf1, M, prec, rec, f1] = perf_confusion(W, fea_te, Y_te, Pte);
end
