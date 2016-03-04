#include <iostream>
#include <sstream>
#include <cstdint>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	int64_t ans = 0, cnt = 0;
	for (int i = s.length() - 1; i >= 0; --i) {
		if (s[i] == 'w') {
			++cnt;
		} else if (s[i] == 'c') {
			ans += (cnt * (cnt - 1)) / 2;
		}
	}
	cout << ans << endl;
	return 0;
}
