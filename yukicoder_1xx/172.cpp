#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
	int x, y, r;
	cin >> x >> y >> r;
	int d = abs(x) + abs(y) + sqrt(r * r * 2);
	cout << (d + 1) << endl;
	return 0;
}
