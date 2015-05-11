// Google Code Jam 2015 R1C
// Problem B. Typewriter Monkey

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef long double LD;

LD solve(string k, string l, int S) {
	LL K = k.length();
	LL L = l.length();
	LD cnt[256] = {};
	for (char c : k) {
		cnt[c] += 1;
	}
	LD d = 1;
	for (char c : l) {
		d = (d * cnt[c]) / (LD)K;
	}
	LD e = 0;
	for (LL i = 0; i <= (S - L); ++i) {
		e += d;
	}

	LL ov = 0;
	for (ov = L - 1; ov > 0; --ov) {
		if (l.substr(0, ov).compare(l.substr(L - ov, ov)) == 0) {
			break;
		}
	}
	LD m = 0;
	if (d > 0) {
		m = 1;
		LL r = S - L;
		LL a = L - ov;
		while (r >= a) {
			m += 1;
			r -= a;
		}
	}
	return m - e;
}

int main(int argc, char *argv[]) {
	cout.precision(8);
	string s;
	getline(cin, s);
	LL T = atoi(s.c_str());
	for (LL t = 1; t <= T; ++t) {
		getline(cin, s);
		stringstream ss(s);
		int K, L, S;
		ss >> K >> L >> S;
		string k, l;
		getline(cin, k);
		getline(cin, l);
		cout << "Case #" << t << ": " << solve(k, l, S) << endl;
	}
	return 0;
}
