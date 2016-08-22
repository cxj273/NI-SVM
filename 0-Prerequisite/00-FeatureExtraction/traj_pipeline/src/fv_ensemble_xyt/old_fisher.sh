cat HVC5789.raw.short | valgrind --leak-check=full ../v0.92/fisher_pipe/fisher tmp 640 480 tmp -1 0 2 0.5 codebook_pca_list 1>/dev/null
