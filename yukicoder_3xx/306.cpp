#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

long double xa, ya, xb, yb;

long double cost(double y) {
	return sqrt(xa*xa + (y - ya)*(y - ya)) + sqrt(xb*xb + (y - yb)*(y - yb));
}

int main(int argc, char *argv[])
{
	cout.precision(12);
	cin >> xa >> ya >> xb >> yb;
	if (ya > yb) {
		swap(xa, xb);
		swap(ya, yb);
	}
	long double left = ya;
	long double right = yb;
	for (int a = 0; a < 1000; ++a) {
		if (cost((left * 2 + right) / 3) <= cost((left + right * 2) / 3)) {
			right = (left + right * 2) / 3;
		} else {
			left = (left * 2 + right) / 3;
		}
	}
	cout << left << endl;
	return 0;
}
