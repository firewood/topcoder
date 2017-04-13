#!/usr/bin/env perl

# Google Code Jam 2017 Qualification Round
# Problem C. Bathroom Stalls

use bigint;

sub solve {
  my $t = $_[0], $n = int($_[1]), $k = int($_[2]);
  my $r = $n, $d = 1;
  while ($k > $d) {
    $k -= $d;
    $r -= $d;
    $d *= 2;
  }
  my $sz = int($r / $d) + ($k <= ($r % $d) ? 1 : 0) - 1;
  my $p = int($sz / 2);
  my $q = $p + ($sz % 2);
  print "Case #$t: $q $p\n";
}

my $T = <>;
for (my $t = 1; $t <= $T; $t++) {
  my ($n, $k) = split " ", <>;
  solve($t, $n, $k);
}
