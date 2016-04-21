#!/usr/bin/env perl

# Google Code Jam 2016 Qualification Round
# Problem A. Counting Sheep

use List::Util 'max';

sub solve {
  my $n = $_[0];
  return "INSOMNIA" if $n == 0;

  max map {
    my $d = ''.$_, $x;
    for ($x = $n; "$x" !~ /$d/; $x += $n) {
    }
    $x;
  } (0..9);
}

my $T = <>;
for (my $t = 1; $t <= $T; $t++) {
  my $n = <> + 0;
  my $ans = solve($n);
  print "Case #$t: $ans\n";
}
