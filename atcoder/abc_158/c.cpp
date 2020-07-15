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

int main(int argc, char* argv[]) {
	int a, b, ans = -1;
	cin >> a >> b;
	for (int p = 2; p <= 10000; ++p) {
		if ((int)(p * 0.08) == a && (int)(p * 0.1) == b) {
			ans = p;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
