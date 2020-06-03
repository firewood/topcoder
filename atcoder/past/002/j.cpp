// J.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

string reversed(string s) {
	reverse(s.begin(), s.end());
	return s;
}

string dfs(const string& s) {
	int pos = s.find('(');
	if (pos < 0) return s;
	if (pos > 0) {
		return s.substr(0, pos) + dfs(s.substr(pos));
	}
	int len = (int)s.length();
	int op = 1;
	int i;
	for (i = 1; i < len; ++i) {
		if (s[i] == '(') {
			++op;
		}
		if (s[i] == ')') {
			--op;
			if (op == 0) {
				break;
			}
		}
	}
	string r = dfs(s.substr(1, i - 1));
	return r + reversed(r) + dfs(s.substr(i + 1));
}

int main(int argc, char* argv[]) {
	string s;
	cin >> s;
	string ans = dfs(s);
	cout << ans << endl;
	return 0;
}
