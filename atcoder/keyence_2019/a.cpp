// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	string e = a + b + c + d;
	sort(e.begin(), e.end());
	string ans = e == "1479" ? "YES" : "NO";
	cout << ans << endl;
	return 0;
}
