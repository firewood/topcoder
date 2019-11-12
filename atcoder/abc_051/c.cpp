// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	string ans = string(ty - sy, 'U');
	ans += string(tx - sx, 'R');
	ans += string(ty - sy, 'D');
	ans += string(tx - sx + 1, 'L');
	ans += string(ty - sy + 1, 'U');
	ans += string(tx - sx + 1, 'R');
	ans += "DR";
	ans += string(ty - sy + 1, 'D');
	ans += string(tx - sx + 1, 'L');
	ans += "U";
	cout << ans << endl;
	return 0;
}
