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

typedef pair<int, int> II;

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

int solve(int N) {
	int ans = 1 << 30;
	vector<int> three;
	for (int i = 3; i <= N; ++i) {
		printf("%s %d %d\n", "?", 1, i);
		fflush(stdout);
		int x = get_ints()[0];
		printf("%s %d %d\n", "?", 2, i);
		fflush(stdout);
		int y = get_ints()[0];
		ans = min(ans, x + y);
		if (x > y) swap(x, y);
		if (x == 1 && y == 2) {
			three.emplace_back(i);
		}
	}
	if (ans == 3) {
		if (three.size() == 2) {
			printf("%s %d %d\n", "?", three[0], three[1]);
			fflush(stdout);
			int x = get_ints()[0];
			if (x != 1) {
				ans = 1;
			}
		} else {
			ans = 1;
		}
	}
	return ans;
}

int main(int argc, char* argv[]) {
	vector<int> x = get_ints();
	assert(x.size() == 3);
	int N = x[0];
	int ans = solve(N);
	printf("%s %d\n", "!", ans);
	fflush(stdout);
	return 0;
}
