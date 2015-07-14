#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int x[4], y[4];

bool check(int a, int b, int c) {
	int vbx = x[b] - x[a];
	int vby = y[b] - y[a];
	int vcx = x[c] - x[a];
	int vcy = y[c] - y[a];
	if (vbx * vcx + vby * vcy) {
		return false;
	}
	if ((vbx * vbx + vby * vby) != (vcx * vcx + vcy * vcy)) {
		return false;
	}
	x[3] = x[a] + vbx + vcx;
	y[3] = y[a] + vby + vcy;
	return true;
}

int main(int argc, char *argv[])
{
	cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
	if (check(0, 1, 2) || check(1, 0, 2) || check(2, 0, 1)) {
		cout << x[3] << " " << y[3] << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}
