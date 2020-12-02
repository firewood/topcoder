#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main() {
	map<string, int> m;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		m[s] += 1;
	}
	vector<int> h;
	map<int, string> r;
	for (auto kv : m) {
		h.emplace_back(kv.second);
		if (r.find(kv.second) == r.end()) {
			r[kv.second] = kv.first;
		} else {
			r[kv.second] = "AMBIGUOUS";
		}
	}
	sort(h.rbegin(), h.rend());
	cout << r[h[k - 1]] << endl;
	return 0;
}
