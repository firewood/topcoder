#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;
map<string, int> m;
int dfs(string s) {
	if (m.find(s) == m.end()) {
		int x = 0;
		for (int i = 0; i < (int)s.length() - 2; ++i) {
			if (s[i] != '0') {
				for (int j = i + 1; j < (int)s.length() - 1; ++j) {
					if (s[i] != s[j]) {
						for (int k = j + 1; k < (int)s.length(); ++k) {
							if (s[j] == s[k]) {
								string r = s.substr(i + 1, j - i - 1) + s.substr(j + 1, k - j - 1) + s.substr(k + 1);
								x = max(x, (s[i] - '0') * 100 + (s[j] - '0') * 11 + dfs(r));
							}
						}
					}
				}
			}
		}
		m[s] = x;
	}
	return m[s];
}
int main(int argc, char *argv[]) {
	std::string s;
	std::cin >> s;
	std::cout << dfs(s) << std::endl;
	return 0;
}
