// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

struct Trie {
	Trie* next[26];
	int cnt[26];
	Trie() {
		fill_n(next, 26, (Trie *)NULL);
		fill_n(cnt, 26, 0);
	}
};

int main(int argc, char *argv[]) {
	vector<Trie> pool(1000002);
	LL n, ans = 0, pi = 0;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		int len = s[i].length();
		vector<int> cf(len + 1);
		for (int j = 0; j < len; ++j) {
			cf[j + 1] = cf[j] | (1 << (s[i][j] - 'a'));
		}
		Trie* node = &(pool[0]);
		for (int j = len - 1; j >= 0; --j) {
			for (int k = 0; k < 26; ++k) {
				if (cf[j + 1] & (1 << k)) {
					node->cnt[k] += 1;
				}
			}
			char c = s[i][j] - 'a';
			if (node->next[c] == NULL) {
				node->next[c] = &(pool[++pi]);
			}
			node = node->next[c];
		}
	}
	for (int i = 0; i < n; ++i) {
		Trie* node = &(pool[0]);
		for (int j = s[i].length() - 1; j > 0; --j) {
			node = node->next[s[i][j] - 'a'];
		}
		ans += node->cnt[s[i][0] - 'a'] - 1;
	}
	cout << ans << endl;
	return 0;
}
