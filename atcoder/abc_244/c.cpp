#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

void solve(int N) {
	set<int> s;
	for (int t = 0; t <= N; ++t) {
		for (int i = 1; i <= 2 * N + 1; ++i) {
			if (s.find(i) == s.end()) {
				s.insert(i);
				cout << i << endl;
				fflush(stdout);
				break;
			}
		}
		string x;
		getline(cin, x);
		s.insert(stoi(x));
	}
}

int main() {
	string s;
	getline(cin, s);
	int N = stoi(s);
	solve(N);
	return 0;
}
