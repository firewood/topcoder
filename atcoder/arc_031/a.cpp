// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	string r = s;
	reverse(r.begin(), r.end());
	cout << (s == r ? "YES" : "NO") << endl;
	return 0;
}
