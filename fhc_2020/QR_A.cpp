//
// Facebook Hacker Cup 2020 Qualification Round
// A. Travel Restrictions
//

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<string> solve(int n, string in, string out) {
	vector<string> ans(n, string(n, 'Y'));
	for (int i = 0; i < n; ++i) {
		for (int j = i - 1; j >= 0; --j) {
			if (out[j + 1] != 'Y' || in[j] != 'Y' || ans[i][j + 1] != 'Y') {
				ans[i][j] = 'N';
			}
		}
		for (int j = i + 1; j < n; ++j) {
			if (out[j - 1] != 'Y' || in[j] != 'Y' || ans[i][j - 1] != 'Y') {
				ans[i][j] = 'N';
			}
		}
	}
	return ans;
}

int main(int argc, char *argv[]) {
	int T, n;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> n;
		string in, out;
		cin >> in >> out;
		vector<string> ans = solve(n, in, out);
		cout << "Case #" << t << ":" << endl;
		for (string s : ans) {
			cout << s << endl;
		}
	}
	return 0;
}
