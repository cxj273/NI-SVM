function [z, r, ub] = prox_iso(g, w, eta, lambda, gamma, ind)
%GOAL   ub = min_z  <z-w, g> + 1/2/eta*|z-w|^2 + ...
%                     lambda*|z|_{iso} + [gamma*|z|_1 or gamma*|z|_2^2]
%       r = lambda*|z|_{iso} + [gamma*|z|_1 or gamma*|z|_2^2]
%       vector ind indicates which method we are using
%				ind(1) > 0: NISVM_1,     ind(1) < 0: NISVM_2
%				ind(2) > 0: 2-norm,      ind(2) < 0: 1-norm
%				ind(3) > 0: sign,        ind(3) < 0: nonnegative
%               ind(4) = 1: iso_i      ind(4) = -1: iso_a
%               ind(4) = 0: iso_+        ind(4) = -2: iso_tv

if nargin < 2,  error('prox_iso needs at least 2 inputs'); end
if ~exist('eta',   'var')   || isempty(eta),   eta     = 1; end
if ~exist('ind',   'var')  || isempty(ind),    ind    = [1 1 1 1]; end
if ~exist('gamma', 'var')  || isempty(gamma),  gamma  = 0; end
if ~exist('lambda', 'var') || isempty(lambda), lambda = 1; end


z = w - eta*g; % gradient step

d = size(w, 1);

eta = eta * lambda; % combine the two for brevity

r = 0;
if ind(1) > 0
    % NISVM_1
    for jj = 1:d
        [z(jj,:), r_cur] = prox(z(jj,:), eta, gamma*eta, ind);
        r = r + r_cur;
    end
else
    % NISVM_2
    zvec_old = sqrt(sum(z.^2, 1));
    [zvec, r_cur] = prox(zvec_old, eta, gamma*eta, ind);
    z = z .* repmat(zvec./(zvec_old+eps), d, 1);
    r = r + r_cur;
end
r = lambda * r;
if ind(2) > 0
    r = r + gamma*norm(z(:),2)^2;
else
    r = r + gamma*norm(z(:),1);
end

tmp = z - w; tmp = tmp(:);
ub = r + tmp'*(g(:)+.5/eta*tmp);


end

function [w, r] = prox(w, eta, gamma, ind)

% to nonnegative, only for iso_i or iso_a when sign is on
if ind(3) > 0 && (ind(4) == 1 || ind(4) == -1)
    s = sign(w);
    w = abs(w);
end

% prox of h, only for iso_i and iso_+
if ind(4) == 1 && ind(4) == 0
    eta = eta / 2;
    w(1) = w(1) + eta;
    w(end) = w(end) - eta;
end

% prox of tv
n = length(w);
if n > 1
    w = flsa(w, zeros(n-1,1), 0, eta, n, 50, 1e-10, 1, 6);
end

% prox of kappa
if ind(3) < 0 || ind(4) == 1 || ind(4) == -1
    w = max(w, 0);
end

% prox of additional 1-norm or 2-norm
if ind(2) > 0
    w = w / (1+2*gamma); % 2-norm
else
    w = sign(w) .* max(abs(w)-gamma, 0); % 1-norm
end

if ind(4) == 1 || ind(4) == 0
    % iso_i or iso_a
    r = sum(max( diff(w),  0));
else
    r = sum(abs( diff(w) ) );
end

% recover the sign, only for iso_our and iso_yang when sign is on
if ind(3) > 0 && (ind(4) == 1 || ind(4) == -1)
    w = s .* w;
end
end
