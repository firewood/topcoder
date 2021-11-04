// F.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	int m, k;
	cin >> m >> k;
	int b = 1 << m;
	vector<int> ans;
	if (k == 0) {
		for (int i = 0; i < b; ++i) {
			ans.push_back(i);
			ans.push_back(i);
		}
	} else if (m > 1 && k < b) {
		ans.clear();
		for (int i = 0; i < b; ++i) {
			if (i != k) {
				ans.push_back(i);
			}
		}
		ans.push_back(k);
		for (int i = b - 1; i >= 0; --i) {
			if (i != k) {
				ans.push_back(i);
			}
		}
		ans.push_back(k);
	} else {
		ans = { -1 };
	}
	for (int a : ans) {
		cout << " " << a;
	}
	cout << endl;
	return 0;
}
