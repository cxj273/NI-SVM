#!/usr/bin/perl

use strict;
use warnings;

my @arr = ();
my $acc = 0;

while(<STDIN>){
	my @aa = split / /, $_;
	for(my $i = 0; $i < scalar(@aa); $i++){
		$aa[$i] =~ /(.*):(.*)/;
		if( ! defined $1 ){
			next;
		}
		$arr[ $1 ] += $2;
	}
	$acc++;
}

for(my $i = 1; $i < scalar(@arr); $i++){
	print $i.":".sprintf("%g",$arr[$i]/$acc)." ";
}
