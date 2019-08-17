// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
  int n, d;
  cin >> n >> d;
  int ans = (n + 2 * d) / (2 * d + 1);
  cout << ans << endl;
  return 0;
}
