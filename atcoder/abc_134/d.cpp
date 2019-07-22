// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

typedef long long LL;
typedef bitset<200002> BS;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	BS a, r;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		if (x) {
			a[i] = true;
		}
	}
	for (int i = n; i >= 1; --i) {
		bool c = a[i];
		for (int j = i + i; j <= n; j += i) {
			c ^= r[j];
		}
		r[i] = c;
	}
	vector<int> res;
	for (int i = 1; i <= n; ++i) {
		if (r[i]) {
			res.push_back(i);
		}
	}
	cout << res.size() << endl;
	if (res.size()) {
		for (int i = 0; i < (int)res.size(); ++i) {
			if (i) cout << " ";
			cout << res[i];
		}
		cout << endl;
	}
	return 0;
}
