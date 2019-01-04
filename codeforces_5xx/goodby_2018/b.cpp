// B.

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef pair<int, int> II;

int main(int argc, char *argv[])
{
	map<II, int> m;
	int n;
	cin >> n;
	vector<int> ox(n), oy(n), dx(n), dy(n);
	for (int i = 0; i < n; ++i) {
		cin >> ox[i] >> oy[i];
		m[II(ox[i], oy[i])] = 1;
	}
	for (int i = 0; i < n; ++i) {
		cin >> dx[i] >> dy[i];
	}
	if (n == 1) {
		cout << (ox[0] + dx[0]) << " " << (oy[0] + dy[0]) << endl;
		return 0;
	}
	int a = ox[1] - ox[0], b = oy[1] - oy[0];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) {
				continue;
			}
			int c = dx[j] - dx[i], d = dy[j] - dy[i];
			if (a == c && b == d) {
				int x = ox[0] + dx[j];
				int y = oy[0] + dy[j];
				bool ok = true;
				for (int i = 0; i < n; ++i) {
					int p = x - dx[i], q = y - dy[i];
					if (m.find(II(p, q)) == m.end()) {
						ok = false;
						break;
					}
				}
				if (ok) {
					cout << x << " " << y << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
