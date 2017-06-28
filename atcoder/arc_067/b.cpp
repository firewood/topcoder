// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	string s;
	cin >> n >> s;
	int ans = 0, d = 0;
	for (char c : s) {
		d += c == 'I' ? 1 : -1;
		ans = max(ans, d);
	}
	cout << ans << endl;
	return 0;
}
