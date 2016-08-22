#!/usr/bin/perl

use strict;
use warnings;

if( scalar(@ARGV) != 3 || !(-f $ARGV[0]) || !(-f $ARGV[1]) ){
	print STDERR "usage: ./correlation.pl bof_file_1 bof_file_2 dimensions\n";
	exit -1;
}

my $dim = $ARGV[2];
my @v1 = ();
my @v2 = ();
for(my $i = 0; $i < $dim; $i++){
	$v1[$i] = 0;
	$v2[$i] = 0;
}

my $m1 = 0;
open(F1, $ARGV[0]);
while(<F1>){
	chomp;
	my @arr = split / /, $_;
	for(my $i = 0; $i < scalar(@arr); $i++){
                if( length($arr[$i]) == 0 ){
                        next;
                }
		my @ar2 = split /:/, $arr[$i];
		$v1[$ar2[0] - 1] = $ar2[1];
		$m1 += $ar2[1];
	}
}
close(F1);
$m1 /= $dim;

my $m2 = 0;
open(F2, $ARGV[1]);
while(<F2>){
	chomp;
	my @arr = split / /, $_;
	for(my $i = 0; $i < scalar(@arr); $i++){
                if( length($arr[$i]) == 0 ){
                        next;
                }
		my @ar2 = split /:/, $arr[$i];
		$v2[$ar2[0] - 1] = $ar2[1];
		$m2 += $ar2[1];
	}
}
close(F2);
$m2 /= $dim;

my $numer = 0.0;
my $denom1 = 0.0;
my $denom2 = 0.0;
for(my $i = 0; $i < $dim; $i++){
	$numer += ( $v1[$i] - $m1 ) * ( $v2[$i] - $m2 );
	$denom1 += ( $v1[$i] - $m1 ) * ( $v1[$i] - $m1 );
	$denom2 += ( $v2[$i] - $m2 ) * ( $v2[$i] - $m2 );	
}

my $corr = $numer / sqrt($denom1) / sqrt($denom2);
print sprintf("%.3f", $corr);
