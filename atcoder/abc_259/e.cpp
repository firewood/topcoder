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
#include <unordered_set>

using namespace std;

int main() {
	int64_t N;
	cin >> N;
	vector<int64_t> M(N);
	vector<vector<int64_t>> p(N), e(N);
	map<int64_t, int64_t> mxe;
	for (int i = 0; i < N; i++) {
		cin >> M[i];
		vector<int64_t> pp(M[i]), ee(M[i]);
		for (int j = 0; j < M[i]; ++j) {
			cin >> pp[j] >> ee[j];
			mxe[pp[j]] = max(mxe[pp[j]], ee[j]);
		}
		p[i] = pp;
		e[i] = ee;
	}
	map<int64_t, int64_t> mxcnt;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M[i]; ++j) {
			if (mxe[p[i][j]] == e[i][j]) {
				mxcnt[p[i][j]] += 1;
			}
		}
	}
	unordered_set<string> s;
	for (int i = 0; i < N; i++) {
		string x;
		for (int j = 0; j < M[i]; ++j) {
			if (mxe[p[i][j]] == e[i][j] && mxcnt[p[i][j]] == 1) {
				x += to_string(p[i][j]);
				x += ",";
			}
		}
		s.insert(x);
	}
	cout << s.size() << endl;
	return 0;
}
