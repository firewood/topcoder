#!/usr/bin/env perl

# Google Code Jam 2016 Round 1A
# Problem B. Rank and File

#use List::Util qw(first max maxstr min minstr reduce shuffle sum);
#use bigint;

my $T = <>;
foreach my $t (1..$T) {
	my $N = <>;
	my %h;
	foreach my $i (0..$N*2-2) {
		foreach my $j (split('\s', <>)) {
			if ($h{"$j"}) {
				$h{"$j"} += 1;
			} else {
				$h{"$j"} = 1;
			}
		}
	}
	my @a;
	while (my ($key, $value) = each(%h)){
		if (($value % 2) != 0) {
			push(@a, $key);
		}
	}
	printf "Case #$t: %s\n", join(' ', sort {$a <=> $b} @a);
}
