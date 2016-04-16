// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	int x1, y1, r, x2, y2, x3, y3;
	cin >> x1 >> y1 >> r >> x2 >> y2 >> x3 >> y3;
	bool red = !(x2 <= (x1 - r) && x3 >= (x1 + r) && y2 <= (y1 - r) && y3 >= (y1 + r));
	bool blue = !(
		((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1)) <= r*r &&
		((x2 - x1)*(x2 - x1) + (y3 - y1)*(y3 - y1)) <= r*r &&
		((x3 - x1)*(x3 - x1) + (y2 - y1)*(y2 - y1)) <= r*r &&
		((x3 - x1)*(x3 - x1) + (y3 - y1)*(y3 - y1)) <= r*r
	);
	cout << (red ? "YES" : "NO") << endl;
	cout << (blue ? "YES" : "NO") << endl;
	return 0;
}
