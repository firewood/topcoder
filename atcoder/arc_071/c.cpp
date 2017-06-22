// C.

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	int n, i;
	cin >> n;
	vector<string> v;
	for (i = 0; i < n; ++i) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		v.push_back(s);
	}
	string ans;
	while (v[0].length()) {
		char c = v[0].front();
		v[0] = v[0].substr(1);
		for (i = 1; i < n; ++i) {
			if (v[i].find(c) == string::npos) {
				break;
			}
		}
		if (i >= n) {
			for (i = 1; i < n; ++i) {
				char d = -1;
				while (d != c) {
					d = v[i].front();
					v[i] = v[i].substr(1);
				}
			}
			ans += c;
		}
	}
	cout << ans << endl;
	return 0;
}
