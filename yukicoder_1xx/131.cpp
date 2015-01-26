#include <iostream>
#include <algorithm>
#include <sstream>
#include <list>

using namespace std;

int main(int argc, char *argv[])
{
	int x, y, d;
	string s;
	getline(cin, s);
	stringstream ss(s);
	ss >> x >> y >> d;
	int sx = d - min(y, d);
	int ex = min(x, d);
	int ans = max(0, ex - sx + 1);
	cout << ans << endl;
	return 0;
}
