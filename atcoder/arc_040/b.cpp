// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n, r;
	cin >> n >> r;
	string s, g(n, 'o');
	cin >> s;
	int ans = 0, pos = 0;
	while (s != g) {
		++ans;
		string next = s.substr(0, pos) + string(r, 'o') + s.substr(min(n, pos + r));
		if (s[pos] == 'o' && next != g) {
			++pos;
		} else {
			s = next;
		}
	}
	cout << ans << endl;
	return 0;
}
