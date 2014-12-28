#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int x = 0, y = 0;
	for (char c : s) {
		switch (c) {
		case 'N': --y; break;
		case 'E': ++x; break;
		case 'W': --x; break;
		case 'S': ++y; break;
		}
	}
	double ans = sqrt(x*x + y*y);
	cout.precision(16);
	cout << ans << endl;
	return 0;
}
