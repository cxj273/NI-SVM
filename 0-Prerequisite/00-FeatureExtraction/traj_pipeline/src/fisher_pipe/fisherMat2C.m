function fisherMat2C(codebook_mat, pca_mat, codebook_out, pca_out)
	load(codebook_mat);
	load(pca_mat);
	fid = fopen(codebook_out, 'w');
	output(fid, codebook.mean);
	output(fid, codebook.variance);
	output(fid, codebook.coef);
	fclose(fid);
	fid = fopen(pca_out, 'w');
	output(fid, pca_proj);
	fclose(fid);
end

function output(fid, matrix)
	fprintf(fid, '%d ', size(matrix));
	fprintf(fid, '\n');
	fprintf(fid, '%d ', matrix(:));
	fprintf(fid, '\n');
end
