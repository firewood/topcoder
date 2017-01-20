// B. 

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int f[100001] = {};
	vector<int> v[100001];
	for (int n = 2; n <= 100000; ++n) {
		if (!f[n]) {
			for (int j = n; j <= 100000; j += n) {
				f[j] = 1;
				v[j].push_back(n);
			}
		}
	}

	int cnt[100001] = {};

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		for (int b : v[a]) {
			++cnt[b];
		}
	}

	int ans = 1;
	for (int i = 2; i <= 100000; ++i) {
		ans = max(ans, cnt[i]);
	}
	cout << ans << endl;
	return 0;
}
