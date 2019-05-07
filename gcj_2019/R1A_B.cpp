// Google Code Jam 2019 Round 1A
// Problem B. Golf Gophers

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

vector<int> get_ints() {
	vector<int> r;
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
		r.push_back(atoi(v.c_str()));
	}
	return r;
}

bool solve(int n, int m) {
	int p[] = { 5,7,9,11,13,16,17 };
	vector<int> c(m + 1);
	for (int i = 0; i < 7; ++i) {
		for (int j = 0; j < 18; ++j) {
			if (j) cout << " ";
			cout << p[i];
		}
		cout << endl;
		fflush(stdout);
		vector<int> res = get_ints();
		int r = accumulate(res.begin(), res.end(), 0) % p[i];
		for (int j = r; j <= m; j += p[i]) {
			++c[j];
		}
	}
	int ans = -1;
	for (int i = 0; i <= m; ++i) {
		if (c[i] == 7) {
			ans = i;
			break;
		}
	}
	cout << ans << endl;
	fflush(stdout);

	vector<int> x = get_ints();
//	fprintf(stderr, "JUDGE: %d\n", x[0]);
	return (x.size() == 1 && x[0] == 1);
}

int main(int argc, char *argv[]) {
#if defined(_WIN32) && defined(_DEBUG)
	Sleep(5000);
#endif

	vector<int> x = get_ints();
	assert(x.size() == 3);
	int T = x[0], N = x[1], M = x[2];
//	fprintf(stderr, "T: %d, N: %d, M: %d\n", T, N, M);
	for (int t = 0; t < T; ++t) {
		if (!solve(N, M)) {
			break;
		}
	}
	return 0;
}
