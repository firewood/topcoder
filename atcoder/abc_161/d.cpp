// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>
#include <map>
#include <bitset>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int k = -1, g = 1;
		cin >> k;
		if (k <= 0) return 0;
		vector<int> d(20);
		for (int i = 0; i < k; ++i) {
			for (int j = 0; j < g; ++j) {
				if (d[j] < 9 && (j == g - 1 || d[j] <= d[j + 1])) {
					++d[j];
					for (int k = j - 1; k >= 0; --k) {
						d[k] = max(0, d[k + 1] - 1);
					}
					goto done;
				}
			}
			for (int j = 0; j < g; ++j) {
				d[j] = 0;
			}
			++g;
			d[g - 1] = 1;
		done:
			{}
		}
		for (int i = g - 1; i >= 0; --i) {
			cout << d[i];
		}
		cout << endl;
	}
	return 0;
}
