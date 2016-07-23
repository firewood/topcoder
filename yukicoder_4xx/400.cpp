#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	string s, ans;
	cin >> s;
	for (int i = s.length() - 1; i >= 0; --i) {
		ans += s[i] == '<' ? '>' : '<';
	}
	cout << ans << endl;
	return 0;
}
