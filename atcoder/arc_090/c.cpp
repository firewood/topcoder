// C.

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  int a[2][101] = {}, dp[2][101] = {};
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> a[i][j];
    }
  }
  for (int j = n - 1; j >= 0; --j) {
    dp[1][j] = a[1][j] + dp[1][j + 1];
    dp[0][j] = a[0][j] + max(dp[1][j], dp[0][j + 1]);
  }
  cout << dp[0][0] << endl;
	return 0;
}
