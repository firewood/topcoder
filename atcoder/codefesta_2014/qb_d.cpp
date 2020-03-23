// D.

#include <algorithm>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int n = -1, h;
	cin >> n;
	map<int, vector<int>> m;
	for (int i = 0; i < n; ++i) {
		cin >> h;
		m[h].push_back(i);
	}
	set<int> s;
	s.insert(-1);
	s.insert(n);
	vector<int> ans(n);
	for (auto it = m.rbegin(); it != m.rend(); ++it) {
		for (auto i : it->second) {
			auto ed = s.lower_bound(i);
			auto st = ed;
			--st;
			ans[i] = *ed - *st - 2;
		}
		for (auto i : it->second) {
			s.insert(i);
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
