// A. 

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	int ans = 0;
	for (char c : s) {
		if (c >= '0' && c <= '9') {
			ans += c & 1;
		} else if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
