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
	vector<LL> r(6);
	for (int qq = 0; qq < W; ++qq) {
		cout << (qq + 1) << endl;
		fflush(stdout);
		vector<LL> res = get_ints();
		assert(res.size() == 1);
		r[qq] = res[0];
	}
	vector<LL> cnt(6), chk(6);
	for (LL x = 0; x <= 100; ++x) {
		cnt[0] = x;
		cnt[1] = r[1] - r[0] - x * 2;
		cnt[2] = r[2] - r[1] - x * 4;
		cnt[3] = r[3] - r[2] - x * 8 - cnt[1] * 2;
		cnt[4] = r[4] - r[3] - x * 16;
		cnt[5] = r[0] - x * 2 - cnt[1] - cnt[2] - cnt[3] - cnt[4];
		bool ok = true;
		chk = cnt;
		for (int y = 0; y < 6; ++y) {
			if (cnt[y] < 0 || cnt[y] > 100) {
				ok = false;
			}
			chk[0] *= 2;
			if (y==1||y==3||y==5)chk[1] *= 2;
			if (y==2||y==5)chk[2] *= 2;
			if (y==3)chk[3] *= 2;
			if (y==4)chk[4] *= 2;
			if (y == 5)chk[5] *= 2;
			LL sum = 0;
			for (int z = 0; z < 6; ++z) {
				sum += chk[z];
			}
			if (sum != r[y]) {
				ok = false;
			}
		}
		if (ok) {
			break;
		}
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
#if defined(_WIN32) && defined(_DEBUG)
	Sleep(5000);
#endif

	vector<LL> x = get_ints();
	assert(x.size() == 2);
	int T = x[0], W = x[1];
//	fprintf(stderr, "T: %d, N: %d, M: %d\n", T, N, M);
	for (int t = 0; t < T; ++t) {
		if (!solve(W)) {
			break;
		}
	}
	return 0;
}
