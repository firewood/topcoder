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
	vector<pair<int, string>> v;
	for (int i = 0; i < 3; ++i) {
		int x;
		cin >> x;
		v.emplace_back(make_pair(x, string(1, 'A' + i)));
	}
	sort(v.begin(), v.end());
	cout << v[1].second << endl;
	return 0;
}
