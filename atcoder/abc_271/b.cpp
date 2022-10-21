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
	int N, Q, l, s, t;
	cin >> N >> Q;
	vector<vector<int>> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> l;
		a[i].resize(l);
		for (int j = 0; j < l; ++j) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < Q; ++i) {
		cin >> s >> t;
		--s;
		--t;
		cout << a[s][t] << endl;
	}
	return 0;
}
