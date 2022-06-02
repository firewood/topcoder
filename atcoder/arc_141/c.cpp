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

bool valid(string v) {
	int p = 0;
	for (auto c : v) {
		if (c == ')') {
			--p;
			if (p < 0) {
				return false;
			}
		} else {
			++p;
		}
	}
	return true;
}

string build(string pat, const vector<int> seq) {
	string x;
	for (int i = 0; i < seq.size(); ++i) {
		x += pat[seq[i]];
	}
	return x;
}

string solve(int N, const vector<int>& P, const vector<int>& Q) {
	string ans(N * 2, ' ');
	map<char, set<int>> m;
	auto f = [&](int p, char c) {
		ans[p] = c;
		m[c].insert(p);
	};
	for (int i = 1; i < N * 2; ++i) {
		if (P[i - 1] > P[i]) {
			f(P[i - 1], '(');
			f(P[i], ')');
		}
		if (Q[i - 1] < Q[i]) {
			f(Q[i - 1], '(');
			f(Q[i], ')');
		}
	}

	map<char, set<int>> m2 = m;
	for (int i = 0; i < N * 2; ++i) {
		auto& s = m[ans[P[i]]];
		if (s.empty()) {
			return "";
		}
		int seq = *s.begin();
		if (seq != P[i]) {
			return "";
		}
		s.erase(seq);
	}
	for (int i = 0; i < N * 2; ++i) {
		auto& s = m2[ans[Q[i]]];
		if (s.empty()) {
			return "";
		}
		int seq = *s.rbegin();
		if (seq != Q[i]) {
			return "";
		}
		s.erase(seq);
	}

	return ans;
}

bool gen(int len) {
	set<string> all_pats;
	set<string> pats;

	vector<int> seq(len * 2);
	iota(seq.begin(), seq.end(), 0);
	do {
		string pat(len * 2, ')');
		for (int i = 0; i < len * 2; ++i) {
			if (seq[i] < len) {
				pat[i] = '(';
			}
		}
		all_pats.insert(pat);
		if (valid(pat)) {
			pats.insert(pat);
		}
	} while (next_permutation(seq.begin(), seq.end()));

	iota(seq.begin(), seq.end(), 0);

	for (auto pat : all_pats) {
		vector<int> mn, mx;
		iota(seq.begin(), seq.end(), 0);
		string pmn, pmx;
		do {
			string a;
			for (int i = 0; i < len * 2; ++i) {
				a += pat[seq[i]];
			}
			if (pats.find(a) != pats.end()) {
				if (mn.empty()) {
					mn = seq;
					pmn = a;
				} else {
					mx = seq;
					pmx = a;
				}
			}
		} while (next_permutation(seq.begin(), seq.end()));

		string s = solve(len, mn, mx);
		if (s != pat) {
			cerr << "FAILED: " << pat << endl;
			return false;
		}
	}
	return true;
}

int main() {
	{
//		gen(4);
	}

	int N;
	std::cin >> N;
	std::vector<int> P(2*N);
	for (int i = 0; i < 2*N; i++) {
		std::cin >> P[i];
		--P[i];
	}
	std::vector<int> Q(2*N);
	for (int i = 0; i < 2*N; i++) {
		std::cin >> Q[i];
		--Q[i];
	}
	string ans = solve(N, P, Q);
	if (ans.empty()) {
		ans = "-1";
	}
	cout << ans << endl;
	return 0;
}
