// B. 

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	string s, ans;
	cin >> s;
	for (char c : s) {
		if (c == 'B') {
			if (!ans.empty()) {
				ans = ans.substr(0, ans.length() - 1);
			}
		} else {
			ans += c;
		}
	}
	cout << ans << endl;
	return 0;
}
