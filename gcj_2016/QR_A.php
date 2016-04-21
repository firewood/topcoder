<?php

// Google Code Jam 2016 Qualification Round
// Problem A. Counting Sheep

$T = fgets(STDIN);
for ($t = 1; $t <= $T; $t++) {
    $n = intval(fgets(STDIN));
    if ($n == 0) {
        $ans = "INSOMNIA";
    } else {
        $a = [];
        for ($d = 0; $d <= 9; $d++) {
            for ($x = $n; ; $x += $n) {
                if (strpos("$x", "$d") !== FALSE) {
                    break;
                }
            }
            $a[] = $x;
        }
        $ans = max($a);
    }
    print("Case #$t: $ans\n");
}
