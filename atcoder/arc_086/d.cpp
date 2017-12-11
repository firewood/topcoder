// D.

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef pair<int, int> II;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	vector<int> a(n);
	vector<II> b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		b[i] = II(a[i], i);
	}
	sort(b.begin(), b.end());
	int bi = abs(b.back().first) > abs(b.front().first) ? b.back().second : b.front().second;
	vector<II> ans;
	for (int i = 0; i < n; ++i) {
		if (i != bi) {
			ans.push_back(II(bi + 1, i + 1));
			a[i] += a[bi];
		}
	}
	if (a[0] >= 0) {
		for (int i = 1; i < n; ++i) {
			ans.push_back(II(i, i + 1));
		}
	} else {
		for (int i = n - 1; i > 0; --i) {
			ans.push_back(II(i + 1, i));
		}
	}
	cout << ans.size() << endl;
	for (auto kv : ans) {
		cout << kv.first << " " << kv.second << endl;
	}
}
