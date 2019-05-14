// Google Code Jam 2019 Round 1C
// Problem A.

#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

static uint32_t _x = 2463534242;
static void xorshift32_seed(uint32_t seed)
{
  if (seed != 0) {
    _x = seed;
  }
}
static uint32_t xorshift32(void)
{
  _x ^= (_x << 13);
  _x ^= (_x >> 17);
  _x ^= (_x << 15);
  return _x;
}
static __inline uint32_t _rand() {
  return xorshift32();
}

string solve(int n, vector<string> h) {
  string ans;
  int lens[256] = {};
  for (int j = 0; j < n; ++j) {
    lens[j] = (int)h[j].length();
  }
  // R, P, S
  for (int t = 0; t < 1000000; ++t) {
    int len = (rand() % 128) + 3;
    int hand[512];
    for (int i = 0; i < len; ++i) {
      hand[i] = _rand() % 3;
    }
    int wins = 0;
    vector<int> w(n);
    for (int i = 0; i < len; ++i) {
      for (int j = 0; j < n; ++j) {
        if (!w[j]) {
          char op = h[j][i % lens[j]];
          if (hand[i] == 0) {
            if (op == 'P')goto lose;
            if (op == 'S') {
              w[j] = 1;
              ++wins;
            }
          } else if (hand[i] == 1) {
            if (op == 'S')goto lose;
            if (op == 'R') {
              w[j] = 1;
              ++wins;
            }
          } else {
            if (op == 'R')goto lose;
            if (op == 'P') {
              w[j] = 1;
              ++wins;
            }
          }
        }
      }
    }
    if (wins >= n) {
      for (int i = 0; i < len; ++i) {
        ans += "RPS"[hand[i]];
      }
      return ans;
    }
  lose:
    ;
  }
  return "IMPOSSIBLE";
}

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int n;
    cin >> n;
    vector<string> h(n);
    for (int i = 0; i < n; ++i) {
      cin >> h[i];
    }
    cout << "Case #" << t << ": " << solve(n, h) << endl;
  }
  return 0;
}
