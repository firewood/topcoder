// Google Code Jam 2019 Qualification Round
// Problem D. Dat Bae

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>
#include <cassert>
#include <Windows.h>

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

void solve() {
	vector<int> x = get_ints();
	int n = x[0];
	fprintf(stderr, "N: %d\n", n);
	int b = x[1];
	fprintf(stderr, "B: %d\n", b);
	int f = x[2];
	fprintf(stderr, "F: %d\n", f);

	vector<int> broken(n);
	for (int i = 0; i < n; ++i) {
		string t(n, '0');
		t[i] = '1';
		printf("%s\n", t.c_str());
		fflush(stdout);
		string res;
		getline(cin, res);
		if (res.find('1') == string::npos) {
			broken[i] = 1;
		}
	}
	string delim = "";
	for (int i = 0; i < n; ++i) {
		if (broken[i]) {
			cout << delim << i;
		}
		delim = " ";
	}
	cout << endl;
	fflush(stdout);
}

int main(int argc, char *argv[]) {
	vector<int> x = get_ints();
	assert(x.size() >= 1);
	int T = x[0];
	fprintf(stderr, "T: %d\n", T);
	solve();
	return 0;
}
