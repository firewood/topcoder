// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef long long LL;

struct Trie {
	Trie* next[26];
	int cnt[26];
	Trie() {
		memset(next, 0, sizeof(next));
		memset(cnt, 0, sizeof(cnt));
	}
};

int main(int argc, char *argv[]) {
	vector<Trie> pool(1000002);
	int pi = 1;
	LL n, ans = 0;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		int len = s[i].length();
		vector<int> cf(len + 2);
		for (int j = 0; j < len; ++j) {
			cf[j + 2] = cf[j + 1] | (1 << (s[i][j] - 'a'));
		}
		Trie* p = &(pool[0]);

		for (int k = 0; k < 26; ++k) {
			if (cf[len - 1 + 2] & (1 << k)) {
				p->cnt[k] += 1;
			}
		}

		for (int j = len - 1; j >= 0; --j) {
			char c = s[i][j] - 'a';
			if (p->next[c] == 0) {
				p->next[c] = &(pool[pi]);
				++pi;
			}
			p = p->next[c];
			for (int k = 0; k < 26; ++k) {
				if (cf[j + 1] & (1 << k)) {
					p->cnt[k] += 1;
				}
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		int len = s[i].length();
		Trie* p = &(pool[0]);
		for (int j = len - 1; j > 0; --j) {
			char c = s[i][j] - 'a';
			p = p->next[c];
		}
		ans += p->cnt[s[i][0] - 'a'] - 1;
	}
	cout << ans << endl;
	return 0;
}
