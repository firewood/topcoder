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

int main() {
	int Q, t, x, c;
	map<int, int> m;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		cin >> t;
		switch (t) {
		case 1:
			cin >> x;
			m[x] += 1;
			break;
		case 2:
			cin >> x >> c;
			m[x] -= c;
			if (m[x] <= 0) {
				m.erase(x);
			}
			break;
		case 3:
			cout << (m.rbegin()->first - m.begin()->first) << endl;
			break;
		}
	}
}
