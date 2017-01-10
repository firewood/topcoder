//
// Facebook Hacker Cup 2017 Qualification Round
// A. Progress Pie
//

#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

static const double EPS = 1e-10;

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		double p, x, y;
		cin >> p >> x >> y;
		double r = sqrt((x - 50) * (x - 50) + (y - 50) * (y - 50));
		double a = atan2(x - 50, y - 50);
		double pp = (a * 100) / (M_PI * 2);
		if (pp < 0) {
			pp += 100;
		}
		string ans = (p > 0 && pp <= p && r <= 50) ? "black" : "white";
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
