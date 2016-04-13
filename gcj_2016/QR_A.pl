#!/usr/bin/env perl

# Google Code Jam 2016 Qualification Round
# Problem A. Counting Sheep

use List::Util 'max';

sub solve {
  my $n = $_[0];
  max map {
    my $d = ''.$_, $x;
    for ($x = $n; index(''.$x, $d) < 0; $x += $n) {
      ;
    }
    $x;
  } (0..9);
}

my $T = <>;
for (my $t = 1; $t <= $T; $t++) {
  my $n = <>;
  my $ans = $n > 0 ? solve($n) : "INSOMNIA";
  print "Case #$t: $ans\n";
}
