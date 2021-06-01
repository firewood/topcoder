#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

LL solve(long long N, long long K) {
  LL ans = 0;
  for (int i = 1; i <= N; ++i) {
    ans += i * 100 * K;
    ans += (K * (K + 1)) / 2;
  }
  return ans;
}

int main() {
  long long N, K;
  std::cin >> N >> K;
  cout << solve(N, K) << endl;
  return 0;
}
