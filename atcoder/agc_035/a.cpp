// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		m[a[i]] += 1;
	}
	bool ans = false;
	switch (m.size()) {
	case 1:
		ans = m.begin()->first == 0;
		break;
	case 2:
		ans = m.begin()->first == 0 && m.begin()->second == n / 3;
		break;
	case 3:
	{
		ans = true;
		int x = 0;
		for (auto y : m) {
			x ^= y.first;
			if (y.second != n / 3) {
				ans = false;
			}
		}
		ans = ans && x == 0;
		break;
	}
	}
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
