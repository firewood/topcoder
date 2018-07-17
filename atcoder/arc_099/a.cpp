// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	long long ans = s.length() - count(s.begin(), s.end(), '-') * 2;
	cout << ans << endl;
	return 0;
}
