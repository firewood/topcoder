#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
  int n, m, a = 0, b = 1;
  cin >> n >> m;
  for (int i = 2; i < n; ++i) {
    int c = (int)(((long long)a + b) % m);
    a = b, b = c;
  }
  cout << b << endl;
	return 0;
}
