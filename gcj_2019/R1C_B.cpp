// Google Code Jam 2019 Round 1C
// Problem B. 

#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
#include <cassert>
#ifdef _WIN32
#include <Windows.h>
#endif

using namespace std;

typedef pair<int, int> II;
typedef pair<II, II> IIII;

typedef long long LL;

vector<LL> get_ints() {
	vector<LL> r;
	string s;
	getline(cin, s);
	stringstream ss(s);
	while (true) {
		string v;
		ss >> v;
		if (v.empty()) {
			break;
		}
		r.push_back(atoll(v.c_str()));
	}
	return r;
}

bool solve(int F) {
	vector<IIII> res(119, IIII(II(-1, -1), II(-1, -1)));
	int cnt[5][5] = {};
	int a = 0, b = 0;
	for (int i = 0; i < F; ++i) {
		int c = a * 5 + b + 1;
		cout << c << endl;
		fflush(stdout);
		string s;
		getline(cin, s);
		int ch = s[0] - 'A';
		cnt[b][ch] += 1;
		switch (b) {
		case 0:res[a].first.first = ch; break;
		case 1:res[a].first.second = ch; break;
		case 2:res[a].second.first = ch; break;
		case 3:res[a].second.second = ch; break;
		}

		b = (b + 1) % 4;
		if (b == 0)++a;
	}

	set<IIII> rs;
	for (auto kv : res) {
		rs.insert(kv);
	}

	vector<IIII> aa;
	int seq[] = { 0,1,2,3,4 };
	do {
		aa.push_back(IIII(II(seq[0], seq[1]), II(seq[2], seq[3])));
	} while (next_permutation(seq, seq + 5));
	sort(aa.begin(), aa.end());

	int used[5] = {};
	vector<IIII> bb;
	int ri = 0;
	for (int i = 0; i != aa.size(); ++i) {
		if (rs.find(aa[i]) == rs.end()) {
			if (cnt[0][aa[i].first.first] < 24 &&
				cnt[1][aa[i].first.second] < 24 &&
				cnt[2][aa[i].second.first] < 24 &&
				cnt[3][aa[i].second.second] < 24) {
				bb.push_back(aa[i]);
			}
		} else {
			char u[5] = { 1,1,1,1,1 };
			u[aa[i].first.first] = 0;
			u[aa[i].first.second] = 0;
			u[aa[i].second.first] = 0;
			u[aa[i].second.second] = 0;
			for (int j = 0; j < 5; ++j) {
				used[j] += u[j];
			}
		}
	}

	string ans;
	for (int t = 0; t != bb.size(); ++t) {
		ans = "";
		ans += "ABCDEF"[bb[0].first.first];
		ans += "ABCDEF"[bb[0].first.second];
		ans += "ABCDEF"[bb[0].second.first];
		ans += "ABCDEF"[bb[0].second.second];
		char u[5] = {};
		u[bb[0].first.first] = 1;
		u[bb[0].first.second] = 1;
		u[bb[0].second.first] = 1;
		u[bb[0].second.second] = 1;
		for (int i = 0; i < 5; ++i) {
			if (!u[i]) {
				ans += "ABCDEF"[i];
				if (used[i] >= 24) {
					ans.clear();
				}
				break;
			}
		}
		if (!ans.empty()) {
			break;
		}
	}
	if (ans.empty()) {
		ans = "F";
	}
	cout << ans << endl;
	fflush(stdout);

	string s;
	getline(cin, s);
	return s == "Y";
}

int main(int argc, char* argv[]) {
#if defined(_WIN32) && defined(_DEBUG)
	Sleep(5000);
#endif

	vector<LL> x = get_ints();
	assert(x.size() == 2);
	int T = x[0], F = x[1];
	for (int t = 0; t < T; ++t) {
		if (!solve(F)) {
			break;
		}
	}
	return 0;
}
