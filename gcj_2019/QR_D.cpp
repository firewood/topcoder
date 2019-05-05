// Google Code Jam 2019 Qualification Round
// Problem D. Dat Bae

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>
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

void solve() {
	vector<int> x = get_ints();
	assert(x.size() == 3);
	int n = x[0];
	int b = x[1];
	int f = x[2];
//	fprintf(stderr, "N: %d, B: %d, F: %d\n", n, b, f);

	vector<string> response(f);
	for (int i = 0; i < f; ++i) {
		string t(n, '0');
		for (int j = 0; j < n; ++j) {
			t[j] = (j & (1 << i)) ? '1' : '0';
		}
		printf("%s\n", t.c_str());
		fflush(stdout);
		getline(cin, response[i]);
	}
	vector<int> broken;
	int seq = 0;
	for (int i = 0; i < (int)response[0].length(); ++i) {
		int x = 0;
		for (int j = 0; j < f; ++j) {
			x |= (1 << j) * (response[j][i] - '0');
		}
		while (x != (seq % (1 << f))) {
			broken.push_back(seq);
			++seq;
		}
		++seq;
	}
	while (broken.size() < b) {
		broken.push_back(seq);
		++seq;
	}

	string delim = "";
	for (int b : broken) {
		cout << delim << b;
		delim = " ";
	}
	cout << endl;
	fflush(stdout);
	x = get_ints();
	assert(x.size() == 1);
}

int main(int argc, char *argv[]) {
#if defined(_WIN32) && defined(_DEBUG)
	Sleep(5000);
#endif

	vector<int> x = get_ints();
	assert(x.size() >= 1);
	int T = x[0];
//	fprintf(stderr, "T: %d\n", T);
	for (int t = 0; t < T; ++t) {
		solve();
	}
	return 0;
}
