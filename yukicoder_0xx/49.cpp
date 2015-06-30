#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int ans = 0, n = 0;
	char op = '*';
	for (int i = 0; i < (int)s.length(); ++i) {
		if (s[i] == '*' || s[i] == '+') {
			if (op == '*') {
				ans += n;
			} else {
				ans *= n;
			}
			op = s[i];
			n = 0;
		} else {
			n = n * 10 + s[i] - '0';
		}
	}
	if (op == '*') {
		ans += n;
	} else {
		ans *= n;
	}
	cout << ans << endl;
	return 0;
}
