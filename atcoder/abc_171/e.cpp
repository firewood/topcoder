#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <cmath>
#include <cassert>

using namespace std;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1, x = 0;
		cin >> n;
		if (n < 0) return 0;
		vector<int> a(n);

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			x ^= a[i];
		}
		for (int i = 0; i < n; ++i) {
			cout << " " << (x ^ a[i]);
		}
		cout << endl;
	}
	return 0;
}
