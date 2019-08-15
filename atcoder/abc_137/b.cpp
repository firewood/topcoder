// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  int k, x;
  cin >> k >> x;
  for (int i = -k + 1; i < k; ++i) {
    cout << " " << (i + x);
  }
  cout << endl;
  return 0;
}
