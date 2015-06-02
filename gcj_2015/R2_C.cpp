// Google Code Jam 2015 R2
// Problem C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;

typedef long long LL;
typedef vector<int> IntVec;
typedef map<string, int> StrIntMap;

int lang[2][20001];
IntVec v[20];

int solve(LL N) {
	int ans = 0;
	for (int i = 0; i <= 20000; ++i) {
		ans += lang[0][i] && lang[1][i];
	}
	int M = 1 << (N - 2);
	if (M >= 2) {
		ans = 1 << 20;
		for (int b = 0; b < M; ++b) {
			int temp = 0;
			int l[2][20001];
			memcpy(l, lang, sizeof(l));
			for (int i = 0; i < N - 2; ++i) {
				int d = ((1 << i) & b) == 0;
				for (int a : v[i + 2]) {
					l[d][a] = 1;
				}
			}
			for (int i = 0; i <= 20000; ++i) {
				temp += l[0][i] && l[1][i];
			}
			ans = min(ans, temp);
		}
	}
	return ans;
}

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	LL T = atoi(s.c_str());
	for (LL t = 1; t <= T; ++t) {
		memset(lang, 0, sizeof(lang));
		int cnt = 0;
		getline(cin, s);
		int N = atoi(s.c_str());
		StrIntMap kw;
		for (LL i = 0; i < N; ++i) {
			v[i].clear();
			getline(cin, s);
			stringstream ss(s);
			while (true) {
				string k;
				ss >> k;
				if (k.empty()) {
					break;
				}
				int idx;
				if (kw.count(k) <= 0) {
					idx = cnt;
					kw[k] = cnt;
					++cnt;
				} else {
					idx = kw[k];
				}
				if (i <= 1) {
					lang[i][idx] = 1;
				}
				v[i].push_back(idx);
			}
		}
		cout << "Case #" << t << ": " << solve(N) << endl;
	}
	return 0;
}
