// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
  int a, b;
  cin >> a >> b;
  int ans = max({ a + b, a - b, a * b });
  cout << ans << endl;
  return 0;
}
