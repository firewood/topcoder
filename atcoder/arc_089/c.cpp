// C.

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
	long long t = 0, x = 0, y = 0;
  bool ans = true;
  for (int i = 0; i < n; ++i) {
    long long nt, nx, ny;
    cin >> nt >> nx >> ny;
    long long dt = nt - t, dx = abs(nx - x), dy = abs(ny - y);
    dt -= (dx + dy);
    if (dt < 0 || (dt % 2) != 0) {
      ans = false;
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
