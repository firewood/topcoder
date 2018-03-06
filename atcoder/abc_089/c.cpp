// C.

#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	const char p[5] = {'M','A','R','C','H'};
	LL cnt[5] = {};
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < 5; ++j) {
			if (s[0] == p[j]) {
				++cnt[j];
			}
		}
	}
	LL ans = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = i + 1; j < 4; ++j) {
			for (int k = j + 1; k < 5; ++k) {
				ans += cnt[i] * cnt[j] * cnt[k];
			}
		}
	}
	cout << ans << endl;
	return 0;
}
