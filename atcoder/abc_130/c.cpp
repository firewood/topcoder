// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	cout.precision(10);
	int w, h, x, y;
	cin >> w >> h >> x >> y;
	double s = (double)w * (double)h * 0.5;
	cout << s << " " << (w == x * 2 && h == y * 2) << endl;
	return 0;
}
