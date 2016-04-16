#!/usr/bin/env perl

# Google Code Jam 2016 Qualification Round
# Problem A. Counting Sheep

use List::Util qw(first max maxstr min minstr reduce shuffle sum);

my $T = <>;
foreach my $t (1..$T) {
	my $n = <>;
	if ($n == 0) {
        $ans = "INSOMNIA";
	} else {
		my @a;
        foreach my $d (0..9) {
			my $x;
			for ($x = $n; ; $x += $n) {
				if ("$x" =~ /$d/) {
					last;
				}
			}
			push(@a, $x);
		}
		$ans = max @a;
	}
	print "Case #$t: $ans\n";
}
