// B.

#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;
typedef long long LL;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char *argv[])
{
  LL N, a, b;
  cin >> N >> a >> b;
  LL g = gcd(a, b);
  for (int i = 0; i < g; ++i) {
    cout << N;
  }
  cout << endl;
	return 0;
}
