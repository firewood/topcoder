// Google Code Jam 2016 Round 1C
// Problem C. Fashion Police

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

typedef pair<int, int> II;
typedef pair<int, II> III;
typedef vector<III> IIIVec;

void solve(int J, int P, int S, int K) {
	IIIVec mx;
	for (int i = 0; i < 10000; ++i) {
		IIIVec v;
		int jp[3][3] = {};
		int js[3][3] = {};
		int ps[3][3] = {};
		int ng = 0;
		set<int> m;
		while (true) {
			int j = (rand() * J) / (RAND_MAX + 1);
			int p = (rand() * P) / (RAND_MAX + 1);
			int s = (rand() * S) / (RAND_MAX + 1);
			int curr = j * 9 + p * 3 + s;
			if (m.find(curr) == m.end() && jp[j][p] < K && js[j][s] < K && ps[p][s] < K) {
				m.insert(curr);
				v.push_back(III(j + 1, II(p + 1, s + 1)));
				ng = 0;
				jp[j][p] += 1;
				js[j][s] += 1;
				ps[p][s] += 1;
			} else {
				++ng;
				if (ng > 256) {
					break;
				}
			}
		}
		if (v.size() > mx.size()) {
			mx = v;
		}
	}
	cout << mx.size() << endl;
	for (int i = 0; i != mx.size(); ++i) {
		cout << mx[i].first << " " << mx[i].second.first << " " << mx[i].second.second << endl;
	}
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int J, P, S, K;
		cin >> J >> P >> S >> K;
		cout << "Case #" << t << ": ";
		solve(J, P, S, K);
	}
	return 0;
}
