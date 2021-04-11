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

bool solve(std::vector<std::string> &S) {
	vector<vector<int>> ch(3, vector<int>(11, -1));
	vector<int> ord;
	set<int> used;
	for (int i = 0; i < 3; i++) {
		const string& s = S[i];
		for (int j = 0; j < s.length(); ++j) {
			int c = s[s.length() - j - 1] - 'a';
			ch[i][j] = c;
			if (used.find(c) == used.end()) {
				used.insert(c);
				ord.emplace_back(c);
			}
		}
	}
	if (used.size() > 10) {
		return false;
	}
	vector<int> seq(10);
	iota(seq.begin(), seq.end(), 0);
	do {
		bool ok = true;
		vector<int> c2d(26);
		for (int i = 0; i < (int)ord.size(); ++i) {
			c2d[ord[i]] = seq[i];
		}
		if (c2d[S[0][0] - 'a'] == 0 || c2d[S[1][0] - 'a'] == 0 || c2d[S[2][0] - 'a'] == 0) {
			continue;
		}
		int carry = 0;
		for (int i = 0; i <= 10; ++i) {
			int sum = carry;
			if (ch[0][i] >= 0) {
				sum += c2d[ch[0][i]];
			}
			if (ch[1][i] >= 0) {
				sum += c2d[ch[1][i]];
			}
			if (sum == 0 && ch[2][i] < 0) {
				break;
			}
			if (ch[2][i] < 0) {
				ok = false;
				break;
			}
			if (c2d[ch[2][i]] != sum % 10) {
				ok = false;
				break;
			}
			carry = sum / 10;
		}
		if (ok) {
			for (int i = 0; i < 3; i++) {
				const string& s = S[i];
				for (int j = 0; j < s.length(); ++j) {
					int c = s[j] - 'a';
					cout << c2d[c];
				}
				cout << endl;
			}
			return true;
		}
	} while (next_permutation(seq.begin(), seq.end()));
	return false;
}

int main() {
    std::vector<std::string> S(3);
	for (int i = 0; i < 3; i++) {
		std::cin >> S[i];
	}
	if (!solve(S)) {
		cout << "UNSOLVABLE" << endl;
	}
	return 0;
}
