// A.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {
	string s;
	cin >> s;
	string ans = s;
	ans[5] = ans[13] = ' ';
	cout << ans << endl;
	return 0;
}
