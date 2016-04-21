<?php

// Google Code Jam 2016 Round 1A
// Problem A. The Last Word

$T = fgets(STDIN);
for ($t = 1; $t <= $T; $t++) {
    $s = trim(fgets(STDIN));
    $ans = '';
    for ($i = 0; $i < strlen($s); $i++) {
        if ($i == 0 || $ans[0] <= $s[$i]) {
            $ans = $s[$i] . $ans;
        } else {
            $ans = $ans . $s[$i];
        }
    }
    print("Case #$t: $ans\n");
}
