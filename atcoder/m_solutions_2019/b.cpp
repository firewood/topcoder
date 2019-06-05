// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	int loses = count(s.begin(), s.end(), 'x');
	cout << (loses <= 7 ? "YES" : "NO") << endl;
	return 0;
}
