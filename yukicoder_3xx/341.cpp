#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	int ans = 0, cnt = 0;
	for (int i = 0; i < (int)s.length() - 2; ++i) {
		if (s[i] == -30 && s[i + 1] == -128 && s[i+2] == -90) {
			i += 2;
			++cnt;
			ans = max(ans, cnt);
		} else {
			cnt = 0;
		}
	}
	cout << ans << endl;
	return 0;
}
