// Google Code Jam 2019 Round 1B
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

typedef long long LL;

vector<LL> sim(vector<LL>& v, int t) {
	vector<LL> r = v;
	for (int i = 1; i <= t; ++i) {
		for (int j = 0; j < 6; ++j) {
			if ((i % (j + 1)) == 0) {
				r[j] = (r[j] + 1) % 64;
			}
		}
	}
	return r;
}

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
//		r.push_back(stoi(v));
		r.push_back(atoll(v.c_str()));
	}
	return r;
}

bool solve(int W) {
	vector<LL> cnt(6), chk(6);
	{
		cout << 185 << endl;
		fflush(stdout);
		vector<LL> res = get_ints();
		assert(res.size() == 1);
		cnt[3] = res[0] >> 46 & 127;
		cnt[4] = (res[0] >> 37) & 127;
		cnt[5] = (res[0] >> 30) & 127;
	}
	{
		cout << 40 << endl;
		fflush(stdout);
		vector<LL> res = get_ints();
		assert(res.size() == 1);
		cnt[0] = res[0] >> 40;
		cnt[1] = (res[0] >> 20) & 127;
		cnt[2] = ((res[0] - (cnt[3] << 10) - (cnt[4] << 8) - (cnt[5] << 6) )  >> 13) & 127;
	}
	for (int qq = 2; qq < W; ++qq) {
		cout << 1 << endl;
		fflush(stdout);
		vector<LL> res = get_ints();
		assert(res.size() == 1);
	}

	for (int i = 0; i < 6; ++i) {
		if (i) cout << " ";
		cout << cnt[i];
	}
	cout << endl;
	fflush(stdout);

	vector<LL> x = get_ints();
//	fprintf(stderr, "JUDGE: %d\n", x[0]);
	return (x.size() == 1 && x[0] != -1);
}

int main(int argc, char *argv[]) {
/*
	vector<LL> temp(6, 0);
	for (int i = 1; i <= 200; ++i) {
		vector<LL> x = sim(temp, i);
		cerr << "DAY:" << i << " ";
		for (int j = 0; j < 6; ++j) {
			cerr << " " << x[j];
		}
		cerr << endl;
	}
//*/

#if defined(_WIN32) && defined(_DEBUG)
	Sleep(5000);
#endif

	vector<LL> x = get_ints();
	assert(x.size() == 2);
	int T = x[0], W = x[1];
	for (int t = 0; t < T; ++t) {
		if (!solve(W)) {
			break;
		}
	}
	return 0;
}
