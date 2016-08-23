function opt = get_options(opts_in, opt)

	names = fieldnames(opts_in);
	for ii = 1:length(names)
		opt.(names{ii}) = opts_in.(names{ii});
	end
end