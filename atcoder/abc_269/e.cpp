#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <set>
#include <vector>
#include <cassert>
#include <map>
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
		r.push_back(atoi(v.c_str()));
	}
	return r;
}

void solve(int N) {
	auto binary_search = [&](bool x) {
		int left = 1, size = N;
		while (size > 1) {
			int a = size / 2;
			if (x) {
				printf("%s %d %d %d %d\n", "?", left, left + a - 1, 1, N);
			} else {
				printf("%s %d %d %d %d\n", "?", 1, N, left, left + a - 1);
			}
			fflush(stdout);
			int r = get_ints()[0];
			if (r == a) {
				left += a;
				size -= a;
			} else {
				size = a;
			}
		}
		return left;
	};
	printf("%s %d %d\n", "!", binary_search(true), binary_search(false));
}

int main(int argc, char* argv[]) {
	vector<int> x = get_ints();
	assert(x.size() == 1);
	int N = x[0];
	solve(N);
	fflush(stdout);
	return 0;
}
