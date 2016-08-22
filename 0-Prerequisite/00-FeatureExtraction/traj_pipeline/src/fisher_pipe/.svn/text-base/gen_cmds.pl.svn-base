#!/usr/bin/perl

use strict;
use warnings;

my $dir = "/data/MM21/iyu/semantic_concepts/gmm_combo";

my @dims = (128, 256, 512, 1024);
my @conf = ("", "_xy", "_xyt");
my @conf_id = (0, 2, 3);

for(my $i = 0; $i < scalar(@conf); $i++){
	for(my $j = 0; $j < scalar(@dims); $j++){
		if( $dims[$j] == 256 && $i == 0 ){
			next;
		}
		print("perl gen_codebook_pca_list.pl $dir/gmm_MED$conf[$i]_$dims[$j] > $dir/gmm_MED$conf[$i]_$dims[$j]/codebook_pca_list\n");
		print "zcat /data/MM21/iyu/semantic_concepts/libraries/fisher/matlab/not_used/brush_hair_100.avi.raw.gz | /home/iyu/MyCodes/lab/semantic_concepts/2014/fisher_pipe/fisher orz_$conf[$i]_$dims[$j]_0 320 240 empty -1 0 2 0.5 $conf_id[$i] $dir/gmm_MED$conf[$i]_$dims[$j]/codebook_pca_list > /dev/null\n";
		if( $dims[$j] < 300 ){
			print "zcat /data/MM21/iyu/semantic_concepts/libraries/fisher/matlab/not_used/brush_hair_100.avi.raw.gz | /home/iyu/MyCodes/lab/semantic_concepts/2014/fisher_pipe/fisher orz_$conf[$i]_$dims[$j]_1 320 240 empty -1 1 2 0.5 $conf_id[$i] $dir/gmm_MED$conf[$i]_$dims[$j]/codebook_pca_list > /dev/null\n";
		}
	}
}
