function [ap] = aprec(truth, score)
% calculate the average precision

	n = length(score);
	if n ~= length(truth), error('sizes do not match!'); end

	[dump, idx] = sort(score, 'descend');

	truth = truth(idx); % permute the truth accordingly
	pos_idx = find(truth > 0); % only relevant ones
	pos_idx = pos_idx(:);
    prec = (1:length(pos_idx))' ./ pos_idx;
    ap = mean(prec);

end