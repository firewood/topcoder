// Google Code Jam 2021 Qualification Round
// Problem D. Median Sort (7pts, 11pts, 10pts)

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

//@@ TODO: LARGE
void solve(int N, int Q) {
	vector<int> seq({ 1,2 });
	for (int i = 3; i <= N; ++i) {
		seq.insert(seq.begin() + 1, i);
		for (int j = 0; j <= i - 3; ++j) {
			printf("%d %d %d\n", seq[j], seq[j + 1], seq[j + 2]);
			fflush(stdout);
			vector<int> res = get_ints();
			int x = res[0];
			if (x == seq[j]) {
				swap(seq[j], seq[j + 1]);
			} else if (x == seq[j + 2]) {
				swap(seq[j + 1], seq[j + 2]);
			} else {
				break;
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		if (i) cout << " ";
		cout << seq[i];
	}
	cout << endl;
	fflush(stdout);
	vector<int> res = get_ints();
}

int main(int argc, char* argv[]) {
#if defined(_WIN32) && defined(_DEBUG)
	Sleep(5000);
#endif

	vector<int> x = get_ints();
	assert(x.size() == 3);
	int T = x[0], N = x[1], Q = x[2];
	for (int t = 0; t < T; ++t) {
		solve(N, Q);
	}
	return 0;
}
