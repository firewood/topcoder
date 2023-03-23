#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> II;

struct Info {
	II next[4];
};

const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
const string dirs = "RULD";

II solve(int K, const string& s) {
	II pos(0, 0);
	map<II, Info> m;
	auto insert = [&](II xy) {
		Info& info = m[xy];
		for (int dir = 0; dir < 4; ++dir) {
			II next(xy.first + dx[dir], xy.second + dy[dir]);
			if (m.find(next) != m.end()) {
				next = m[next].next[dir];
			}
			info.next[dir] = next;
		}
		for (int dir = 0; dir < 4; ++dir) {
			II next(info.next[dir].first - dx[dir], info.next[dir].second - dy[dir]);
			m[next].next[dir ^ 2] = info.next[dir ^ 2];
		}
	};
	for (char c : s) {
		insert(pos);
		pos = m[pos].next[dirs.find(c)];
	}
	return pos;
}

int main() {
	int K;
	string s;
	cin >> K;
	cin >> s;
	II ans = solve(K, s);
	cout << ans.first << " " << ans.second << endl;
	return 0;
}
