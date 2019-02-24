// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	int y, m, d;
	sscanf(s.c_str(), "%d/%d/%d", &y, &m, &d);
	cout << (y > 2019 || (y == 2019 && m >= 5) ? "TBD" : "Heisei") << endl;
	return 0;
}
