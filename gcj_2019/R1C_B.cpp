// Google Code Jam 2019 Round 1C
// Problem B. 

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
#ifdef _WIN32
#include <Windows.h>
#endif

using namespace std;

typedef pair<int, int> II;
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
	string ans;
	vector<II> q(119);
	for (int i = 0; i < (int)q.size(); ++i) {
		q[i] = II(i, 0);
	}
	for (int col = 0; col < 4; ++col) {
		vector<II> cnt(5);
		for (int i = 0; i < 5; ++i) {
			cnt[i].second = i;
		}
		vector<II> nq;
		for (auto kv : q) {
			--F;
			int row = kv.first;
			cout << (row * 5 + col + 1) << endl;
			fflush(stdout);
			string s;
			getline(cin, s);
			int ch = s[0] - 'A';
			cnt[ch].first += 1;
			nq.push_back(II(row, ch));
		}
		sort(cnt.begin(), cnt.end());
		if (col == 3) {
			char ch = 'A' + cnt.back().second;
			string x = ans;
			x += ch;
			for (char c : "ABCDE") {
				if (x.find(c) == string::npos) {
					ans += c;
					ans += ch;
					break;
				}
			}
			break;
		} else {
			int ch = cnt[col].second;
			ans += 'A' + ch;
			q.clear();
			for (auto kv : nq) {
				if (kv.second == ch) {
					q.push_back(kv);
				}
			}
		}
	}
	while (F--) {
		cout << "1" << endl;
		fflush(stdout);
		string s;
		getline(cin, s);
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
	int T = (int)x[0], F = (int)x[1];
	for (int t = 0; t < T; ++t) {
		if (!solve(F)) {
			break;
		}
	}
	return 0;
}
