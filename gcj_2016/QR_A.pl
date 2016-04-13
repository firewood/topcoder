#!/usr/bin/env perl

# Google Code Jam 2016 Qualification Round
# Problem A. Counting Sheep

use List::Util 'min';

sub solve {
  my $n = $_[0];
  min map {
    my $d = ''.$_;
    for (my $x = $n; ; $x += $n) {
      if (index(''+$x, $d) >= 0) {
        return $x;
      }
    }
  } (0..9);
}

my $T = <>;
for (my $t = 1; $t <= $T; $t++) {
  my $n = <>;
  my $ans = $n > 0 ? solve($n) : "INSOMNIA";
  print "Case #$t: $ans\n";
}
