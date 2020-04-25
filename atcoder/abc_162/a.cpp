// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	string s;
	cin >> s;
	bool ans = (int)s.find('7') >= 0;
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
