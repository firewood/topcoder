// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	string s;
	cin >> s;
//	n = 131072, s = string(n, 'a');

	int top[131072] = {}, len[131072] = {};
	int prev_top = 0, prev_len = 0;
	char prev_char = 0;
	int ans = 0;
	{
		map<int, int> m;
		for (int i = 0; i < n; ++i) {
			if (prev_char != s[i]) {
				if (prev_char) {
					m[prev_char] = max(m[prev_char], prev_len);
				}
				len[prev_top] = prev_len;
				prev_len = 0;
				prev_top = i;
				prev_char = s[i];
			}
			top[i] = prev_top;
			++prev_len;
		}
		m[prev_char] = max(m[prev_char], prev_len);
		len[prev_top] = prev_len;
		for (auto &kv : m) {
			ans += kv.second;
		}
	}

	{
		set<string> m;
		for (int i = 0; i < n; ++i) {
			int st = top[i], ed = st + len[st] - 1;
			int skip_length = min(i - st, ed - i);
			int j = 1 + skip_length;
			if (i - j >= 0 && i + j < n && s[i - j] == s[i + j]) {
				string x = s.substr(i, skip_length + 1);
				for (; i - j >= 0 && i + j < n; ++j) {
					if (s[i - j] != s[i + j]) {
						break;
					}
					x += s[i + j];
					m.insert(x);
				}
			}
		}
		ans += m.size();
	}

	{
		set<string> m;
		for (int i = 1; i < n; ++i) {
			if (s[i - 1] == s[i]) {
				int st = top[i], ed = st + len[st] - 1;
				int skip_length = min(i - st - 1, ed - i);
				int j = 1 + skip_length;
				if (i - j >= 1 && i + j < n && s[i - j - 1] == s[i + j]) {
					string x = s.substr(i, skip_length + 1);
					for (; i - j >= 1 && i + j < n; ++j) {
						if (s[i - j - 1] != s[i + j]) {
							break;
						}
						x += s[i + j];
						m.insert(x);
					}
				}
			}
		}
		ans += m.size();
	}
	cout << ans << endl;
	return 0;
}
