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

int main() {
	string s;
	getline(cin, s);
	int N;
	cin >> N;
	vector<string> t(N), ans;
	for (int i = 0; i < N; ++i) {
		cin >> t[i];
	}

	stringstream ss(s);
	while (true) {
		string w;
		ss >> w;
		if (w.empty()) {
			break;
		}
		for (int i = 0; i < N; ++i) {
			if (w.length() == t[i].length()) {
				bool matched = true;
				for (size_t j = 0; j < t[i].length(); ++j) {
					if (t[i][j] == '*' || w[j] == t[i][j]) {
						;
					} else {
						matched = false;
						break;
					}
				}
				if (matched) {
					w = string(t[i].length(), '*');
				}
			}
		}
		ans.emplace_back(w);
	}

	for (size_t i = 0; i < ans.size(); ++i) {
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << endl;

	return 0;
}
