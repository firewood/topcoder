#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>
#include <cstdio>

using namespace std;
typedef long long LL;
typedef set<int> IntSet;

int get_common_length(const IntSet &a, const IntSet &b) {
	int r = 0;
	for (int x : a) {
		r += b.find(x) != b.end();
	}
	return r;
}

int main(int argc, char *argv[]) {
	int N, M;
	cin >> N >> M;
	int m = 0;
	vector<IntSet> v;
	for (int i = 0; i != M; ++i) {
		vector<IntSet> w;
		int c[100][100];
		for (int j = 0; j != N; ++j) {
			IntSet s;
			for (int k = 0; k != N; ++k) {
				cin >> c[j][k];
				s.insert(c[j][k]);
			}
			w.push_back(s);
		}
		IntSet a, b;
		for (int j = 0; j != N; ++j) {
			IntSet s;
			for (int k = 0; k != N; ++k) {
				s.insert(c[k][j]);
			}
			w.push_back(s);
			a.insert(c[j][j]);
			b.insert(c[j][N - j - 1]);
		}
		w.push_back(a);
		w.push_back(b);
		for (auto x : w) {
			for (auto y : v) {
				m = max(m, get_common_length(x, y));
			}
		}
		for (auto s : w) {
			v.push_back(s);
		}
	}
	int ans = N * 2 - m - 1;
	cout << ans << endl;
	return 0;
}
