// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
  int a, b, c;
  cin >> a >> b >> c;
  cout << max(0, b + c - a) << endl;
  return 0;
}
