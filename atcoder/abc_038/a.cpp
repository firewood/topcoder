// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	string s;
	cin >> s;
	cout << (s.back() == 'T' ? "YES" : "NO") << endl;
	return 0;
}
