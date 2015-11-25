#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
	int x, y, x2, y2;
	cin >> x >> y >> x2 >> y2;
	int ans = max(x, y);
	if (x == y && x2 == y2 && x2 < x) {
		++ans;
	}
	cout << ans << endl;
	return 0;
}
