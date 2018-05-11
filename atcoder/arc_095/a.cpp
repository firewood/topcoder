// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	int ans = 700 + 100 * count(s.begin(), s.end(), 'o');
	cout << ans << endl;
	return 0;
}
