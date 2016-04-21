// Google Code Jam 2016 Qualification Round
// Problem C. Coin Jam

var fs = require('fs');

function gen_primes(m) {
  var f = {};
  primes = [2];
  for (var i = 3; i <= 65536; i += 2) {
    if (!f[i]) {
      primes.push(i);
      for (var j = i * 2; j <= 65536; j += i) {
        f[j] = 1;
      }
    }
  }
  return primes;
}

function digitsToInteger(N, digits, radix) {
  return parseInt(digits.join(''), radix);
}

function check(N, primes, digits, divisors) {
  for (var j = 2; j <= 10; ++j) {
    var n = digitsToInteger(N, digits, j);
    for (var i = 0; i != primes.length; ++i) {
      if (primes[i] >= n) {
        break;
      }
      if ((n % primes[i]) == 0) {
        divisors[j] = primes[i];
        break;
      }
    }
    if (divisors[j] == 0) {
      return false;
    }
  }
  return true;
}

function solve(N, J) {
  var primes = gen_primes(65536);
  var u = {};
  for (var i = 0; i < J; ++i) {
    while (true) {
      var digits = new Array(N);
      digits[0] = 1;
      digits[N - 1] = 1;
      for (var j = 1; j < N - 1; ++j) {
        digits[j] = Math.random() >= 0.5 ? 1 : 0;
      }
      var divisors = new Array(11);
      for (var d = 2; d <= 10; ++d) {
        divisors[d] = 0;
      }
      if (check(N, primes, digits, divisors)) {
        var n = digitsToInteger(N, digits, 10);
        if (!u[n]) {
          u[n] = 1;
          var res = "" + n;
          for (var d = 2; d <= 10; ++d) {
            res += " " + divisors[d];
          }
          console.log(res);
          break;
        }
      }
    }
  }
}

fs.readFile('./in_c.txt', 'utf8', function (err, text) {
  var a = text.split('\n')
  var T = parseInt(a.shift(), 10);
  for (var t = 1; t <= T; ++t) {
    console.log("Case #" + t + ":");
    var req = a.shift().split(' ')
    solve(parseInt(req[0], 10), parseInt(req[1], 10));
  }
});
