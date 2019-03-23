// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

typedef long long LL;
static const LL MOD = 1000000007LL;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<int> b(n);
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		int j;
		for (j = b.size() - 1; j >= 0; --j) {
			if (b[j] == j + 1) {
				ans.push_back(j + 1);
				b.erase(b.begin() + j);
				break;
			}
		}
		if (j < 0) {
			cout << "-1" << endl;
			return 0;
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		cout << ans[i] << endl;
	}
	return 0;
}
