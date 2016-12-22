#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <cstring>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
//	set<int> p[5001], r[5001];
	char p[5001][5001] = {}, r[5001][5001] = {};
	int len = (int)s.length();
	for (int i = 0; i < len; ++i) {
		for (int j = 0; (i - j) >= 0 && (i + j) < len; ++j) {
			if (s[i - j] == s[i + j]) {
//				p[i - j].insert(j * 2 + 1);
//				r[i + j + 1].insert(j * 2 + 1);
				p[i - j][j * 2 + 1] = 1;
				r[i + j + 1][j * 2 + 1] = 1;
			} else {
				break;
			}
		}
		for (int j = 0; (i - j) >= 0 && (i + j + 1) < len; ++j) {
			if (s[i - j] == s[i + j + 1]) {
//				p[i - j].insert(j * 2 + 2);
//				r[i + j + 2].insert(j * 2 + 2);
				p[i - j][j * 2 + 2] = 1;
				r[i + j + 2][j * 2 + 2] = 1;
			} else {
				break;
			}
		}
	}
	int cnt = 0;
	int right[5000] = {};
	for (int i = len - 1; i >= 0; --i) {
		right[i] = cnt;
//		if (r[len].find(len - i) != r[len].end()) {
		if (r[len][len - i]) {
			++cnt;
		}
	}
	LL ans = 0;
	int left[5000] = {};
//	for (int i : p[0]) {
//		for (int j : p[a]) {
	for (int i = 1; i < len; ++i) {
		if (p[0][i]) {
			for (int j = 1; j < len; ++j) {
				if (p[i][j]) {
					left[i + j] += 1;
				}
			}
		}
	}
	for (int i = 0; i < len; ++i) {
		ans += left[i] * right[i];
	}
	cout << ans << endl;
	return 0;
}
