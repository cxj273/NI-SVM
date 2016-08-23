function ap = nisvm(fea, y, lambda, gamma, ind, fea_te, y_te)
% fea: C by S by N matrix
% C: number of concept detectors
% S: number of shots
% N: number of videos
% y: N by 1 vector

% lambda: total variation norm [0.001 0.01 0.1 1]
% gamma: squared l2 norm [0.001 0.01 0.1 1]
% ind: nonnegative W?

[C, S, N] = size(fea);

loss = @(w)       loss_shinge(fea, y, w);
prox = @(g,w,eta) prox_iso(g, w, eta, lambda, gamma, ind);
perf = @(w) perf_aprec(w, fea, y);

fea_Te = reshape(fea_te, C*S, N);
%opt.init_eta = N / svds(x*x', 1);
%opt.stepsize_rule = '';
opt.acc = 0;

w0 = randn(C, S);
w = FISTA(loss, prox, perf, w0, opt);

ap = perf_aprec(w, fea_Te, y_te);

end
