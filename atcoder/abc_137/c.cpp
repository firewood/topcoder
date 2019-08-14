// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	int n;
	cin >> n;
	map<string, LL> m;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		m[s] += 1;
	}
	LL ans = 0;
	for (auto kv : m) {
		ans += ((kv.second - 1) * kv.second) / 2;
	}
	cout << ans << endl;
	return 0;
}

