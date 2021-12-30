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

typedef pair<int, int> II;

void solve(int n) {
	vector<II> one, two;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if ((i + j) % 2) {
				one.emplace_back(II(i + 1, j + 1));
			} else {
				two.emplace_back(II(i + 1, j + 1));
			}
		}
	}
	int p = one.size() - 1;
	int q = two.size() - 1;
	for (int t = 0; t < n * n; ++t) {
		string s;
		getline(cin, s);
		int a = stoll(s);
		if (a != 1 && p >= 0) {
			printf("1 %d %d\n", one[p].first, one[p].second);
			fflush(stdout);
			--p;
			continue;
		}
		if (a != 2 && q >= 0) {
			printf("2 %d %d\n", two[q].first, two[q].second);
			fflush(stdout);
			--q;
			continue;
		}
		if (p >= 0) {
			printf("3 %d %d\n", one[p].first, one[p].second);
			fflush(stdout);
			--p;
		} else {
			printf("3 %d %d\n", two[q].first, two[q].second);
			fflush(stdout);
			--q;
		}
	}
}

int main(int argc, char* argv[]) {
	string s;
	getline(cin, s);
	int n = stoll(s);
	solve(n);
	return 0;
}
