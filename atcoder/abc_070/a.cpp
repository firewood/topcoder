// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	stringstream ss;
	ss << n;
	string s;
	ss >> s;
	string r = s;
	reverse(r.begin(), r.end());
	cout << (s == r ? "Yes" : "No") << endl;
	return 0;
}
