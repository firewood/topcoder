// Google Code Jam 2022 Round 1B
// Problem C. ASeDatAb (25pts, 15pts)

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
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
		r.push_back(stoi(v));
	}
	return r;
}

bool solve() {
	int prev = 4;
	for (int i = 0; i < 300; ++i) {
		int r = (1 << prev) - 1;

		string s = "";
		for (int i = 0, x = r; i < 8; ++i) {
			s += char('0' + (x & 1));
			x >>= 1;
		}
		printf("%s\n", s.c_str());
		fflush(stdout);

		int res = get_ints()[0];
		if (res == 0) {
			cerr << "OK: " << i << endl;
			return true;
		}
		if (res < 0) {
			cerr << "FAILED" << endl;
			return false;
		}
		prev = res;
	}
}

int main(int argc, char* argv[]) {
#if defined(_WIN32) && defined(_DEBUG)
	Sleep(1000);
#endif

	int ac = 0;
	vector<int> x = get_ints();
	assert(x.size() == 1);
	int T = x[0];
	for (int t = 0; t < T; ++t) {
		if (!solve()) {
			break;
		}
		++ac;
	}
	return 0;
}
