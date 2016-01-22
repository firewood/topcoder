// Google Code Jam 2015 R1B
// Problem A. Counter Culture

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

typedef long long LL;

typedef vector<string> StrVec;
typedef set<LL> IntSet;
typedef vector<LL> IntVec;

LL reversed(LL n) {
  LL x = 0;
  while (n > 0) {
    x = (x * 10) + (n % 10);
    n /= 10;
  }
  return x;
}

LL solve1(LL N) {
  IntSet s;
  LL count;

  if (N >= 100000) {
    s.insert(100000);
    count = 1436;
  } else if (N >= 10000) {
    s.insert(10000);
    count = 337;
  } else if (N >= 1000) {
    s.insert(1000);
    count = 138;
  } else {
    s.insert(1);
    count = 1;
  }

  while (s.find(N) == s.end()) {
    ++count;
    IntSet n;
    IntSet::const_iterator it;
    for (it = s.begin(); it != s.end(); ++it) {
      n.insert(*it + 1);
      n.insert(reversed(*it));
    }
    s = n;
  }
  return count;
}

LL solve2(LL N) {
  if (N <= 20) {
    return N;
  }
  LL x = 10;
  LL count = 10;

  char w[64];
  sprintf(w, "%lld", N);
  LL len = strlen(w);

  for (LL i = 2; i < len; ++i) {
    LL j = (i + 1) / 2;
    LL k = i - j;
    LL a = pow(10, j);
    LL b = pow(10, k) - 1;
    x = reversed(x + a - 1);
    count += a;
    x += b;
    count += b;
  }

  if (x == N) {
    return count;
  }

  LL ans = N - x;
  LL f = reversed(N);
  for (LL i = 1; i < len; ++i) {
    LL a = pow(10, i);
    LL b = f % a;
    LL c = b + 1;
    LL d = reversed(x + b);
    if (d <= N) {
      ans = min(ans, c + N - d);
    }

    LL p = pow(10, i - 1);
    if (b >= p) {
      c = b - p + 1;
      d = reversed(x + b - p);
      if (d <= N) {
        ans = min(ans, c + N - d);
      }
    }

    LL r = (N / a) - 1;
    if (r > 0) {
      b = reversed(r);
      c = b + 1;
      d = reversed(x + b);
      if (d <= N) {
        ans = min(ans, c + N - d);
      }
    }
  }
  return count + ans;
}

int main(int argc, char *argv[]) {
  string s;
  getline(cin, s);
  LL T = atoi(s.c_str());
  for (LL t = 1; t <= T; ++t) {
    getline(cin, s);
    stringstream ss(s);
    LL N;
    ss >> N;
    cout << "Case #" << t << ": " << solve2(N) << endl;
  }
  return 0;
}
