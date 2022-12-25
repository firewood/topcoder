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

bool solve(std::string S) {
	int level;
	vector<char> st;
	set<int> s;
	for (char c : S) {
		st.emplace_back(c);
		switch (c) {
		case '(':
			break;
		case ')':
			level = 0;
			do {
				c = st.back();
				st.pop_back();
				switch (c) {
				case '(':
					--level;
					break;
				case ')':
					++level;
					break;
				default:
					s.erase(c);
					break;
				}
			} while (level > 0);
			break;
		default:
			if (s.find(c) != s.end()) {
				return false;
			}
			s.insert(c);
			break;
		}
	}
	return true;
}

int main() {
	std::string S;
	std::cin >> S;
	cout << (solve(S) ? "Yes" : "No") << endl;
	return 0;
}
