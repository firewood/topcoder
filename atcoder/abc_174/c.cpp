// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	LL k, x, ans;
	cin >> k;
	for (x = 7 % k, ans = 1; x != 0 && ans < 10000000; ++ans) {
		x = (x * 10 + 7) % k;
	}
	cout << (ans >= 10000000 ? -1 : ans) << endl;
	return 0;
}
