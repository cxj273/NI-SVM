function [z, F, msg] = FISTA(loss, prox, perf, w, opts_in)
%GOAL             min_{w}  loss(w) + reg(w)
%   F      : contains all intermediate objective values     
%
%   loss   : function handle,  [f, g] = loss(w)
%               returns the function value f and gradient g
%   prox   : function handle,  [z, r, ub] = prox(g, w, eta)
%               returns a minimizer z, value r = reg(z), and 
%                ub = min_{z} <z-w, g> + 1/eta*div(z, w) + reg(z)
%               ususally, div(z, w) = .5*|z - w|^2 
%   perf   : function handle, evaluates the performance of w
%   w      : initial point, must be specified
%   opts_in: structure, default values below
%               opt.max_iter      = 3000; max # of iteration
%               opt.max_ls        = 30;   max # of line search
%               opt.inc           = 1.2;  increment of step size
%               opt.dec           = 0.5;  decrement of step size
%               opt.fval_tol      = 1e-8; stopping tolerance (function value)
%               opt.init_eta      = 1;    initial step size
%               opt.verbose       = 0;    debugging output
%               opt.acc           = 0;    accelerated?
%               opt.mon           = 0;    monotone?
%               opt.perf          = 1;    evaluate performance?
%               opt.freq          = 100;  frequency to call perf
%               opt.stepsize_rule = 'ls'; step size rule

if nargin < 4
    error('FISTA requires at least 4 arguments');
elseif nargin == 4 || isempty(opts_in)
    opts_in = struct([]);
end


% Default option values
opt.max_iter      = 3000;
opt.max_ls        = 30;
opt.inc           = 1;
opt.dec           = 0.8;
opt.fval_tol      = 1e-8;
opt.min_tol       = 1e-3;
opt.init_eta      = 1;
opt.verbose       = 0;
opt.acc           = 0;
opt.mon           = 0;
opt.perf          = 0;
opt.freq          = 100;
opt.stepsize_rule = 'ls';

opt = get_options(opts_in, opt);

zold = w; fold = inf;
t = 1;  msg = '';   eta = opt.init_eta;
TOL = opt.fval_tol; F = zeros(opt.max_iter, 1);

time = cputime; 
for k = 1 : opt.max_iter
    
    [ellw, gw] = loss(w);

    switch opt.stepsize_rule
        case 'ls' % line search
            for ii = 1 : opt.max_ls
                [z, rz, ub] = prox(gw, w, eta);
                f = loss(z) + rz;
                q = ellw + ub;        
                if f <= q, eta = eta * opt.inc; break;  end
                eta = eta * opt.dec;
            end
            if ii == opt.max_ls
                msg = [msg 'max line search reached at iter ' num2str(k) '\n'];
            end
        case 'ld' % linear diminishing
            eta = opt.init_eta / k;
            [z, rz] = prox(gw, w, eta);
            f = loss(z) + rz;
        case 'sd' % square root diminishing
            eta = opt.init_eta / sqrt(k);
            [z, rz] = prox(gw, w, eta);
            f = loss(z) + rz;
        otherwise % constant step size
            [z, rz] = prox(gw, w, eta);
            f = loss(z) + rz;
    end

    ztemp = z; % backup, for later use
%     if f > fold && opt.acc
%         t = 1; fold = f;           % restarting
%     elseif
    if  norm(zold-z, 'fro') <= opt.min_tol*norm(z,'fro'); % approximately converged
        break;
    elseif f > fold && opt.mon 
        z = zold; f = fold;        % enforce monotonicity
    else
        fold = f;                  % next iteration
    end
    F(k) = f;
    
    if ~opt.verbose
        fprintf('FISTA: iter = %d: loss = %g, obj = %g, time = %g, eta=%g\n', k, f-rz, f, cputime-time, eta);
    end

    if opt.perf && mod(k, opt.freq) == 0
        fprintf('iter = %d, perf = %g, time = %g \n', k, perf(z), cputime-time)
    end
    
    if opt.acc % Nesterov or not
        t_new = (1+sqrt(1+4*t^2))/2;
        w = z + (t-1)/t_new*(z - zold) + t/t_new*(ztemp-z);
        zold = z;  t = t_new;
    else
        w = z; zold = z;
    end

end

if k == opt.max_iter
    msg = [msg 'max iter reached'];
end
end
