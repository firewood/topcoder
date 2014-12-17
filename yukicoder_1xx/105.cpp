#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	cout.precision(16);
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	for (int t = 0; t < N; ++t) {
		getline(cin, s);
		double rad[6];
		for (int i = 0; i < 6; ++i) {
			double x, y;
			getline(cin, s);
			stringstream ss(s);
			ss >> x >> y;
			rad[i] = atan2(y,x);
			if (rad[i] < 0) {
				rad[i] += 2 * M_PI;
			}
		}
		sort(rad, rad + 6);
		double d = rad[0] / (2 * M_PI) * 360;
		if (d >= (60 - 1.0e-8)) {
			d -= 60;
		}
		if (d <= 1.0e-8) {
			d = 0;
		}
		cout << d << endl;
	}
	return 0;
}
