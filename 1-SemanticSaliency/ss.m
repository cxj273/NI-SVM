function ori_pooling =  ss_pooling(ori, cd, rel)
    % ori: original feature matrix (d by m)
    % d: feature dimension, m: number of shots
    % cd: concept detection score matrix (c by m)
    % c: number of concepts
    % rel: relevance vector (c by 1)
    [d, m] = size(ori);
    [c, junk] = size(cd);
    
    ss = cd' * rel; % m by 1 vector
    [junk, idx] = sort(ss, 'descend');
    ori_pooling = [];
    
    for ii = 1:m
        ori_pooling = [ori_pooling ori(:, idx(ii))];
    end

end

