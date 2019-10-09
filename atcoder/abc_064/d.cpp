// D.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
	while (true) {
		int len = -1, cnt = 0, miss = 0;
		cin >> len;
		string s;
		cin >> s;
		if (len <= 0) break;
		for (char c : s) {
			if (c == '(') {
				++cnt;
			} else if (cnt <= 0) {
				++miss;
			} else {
				--cnt;
			}
		}
		string ans = string(miss, '(') + s + string(cnt, ')');
		cout << ans << endl;
	}
	return 0;
}
