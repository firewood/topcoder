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

set<string> dfs(int N) {
	set<string> r;
	if (N == 2) {
		r.insert("()");
	} else if (N > 2 && N % 2 == 0) {
		for (int a = N - 2; a >= 2; a -= 2) {
			set<string> x = dfs(a);
			set<string> y = dfs(N - a);
			for (auto p : x) {
				if (a == N - 2) {
					r.insert("(" + p + ")");
				}
				for (auto q : y) {
					r.insert(p + q);
				}
			}
		}
	}
	return r;
}

vector<string> enumerate(int N) {
	vector<string> ans;
	string s(N, '(');
	while (true) {
		int c = 0;
		for (int i = 0; i < N; ++i) {
			if (s[i] == '(') {
				++c;
			} else if (--c < 0) {
				break;
			}
		}
		if (c == 0) {
			ans.emplace_back(s);
		}
		for (int i = N - 1; i >= 0; --i) {
			if (s[i] == '(') {
				s[i] = ')';
				break;
			}
			s[i] = '(';
			if (i == 0) {
				return ans;
			}
		}
	}
}

int main() {
	int N;
	std::cin >> N;
	for (auto s : enumerate(N)) {
		cout << s << endl;
	}
	return 0;
}
