#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

int solve(int r, int g, int b)
{
	int ans = min(r, min(g, b));
	int a[3] = { r - ans, g - ans, b - ans };
	sort(a, a + 3);
	a[0] = a[1], a[1] = a[2];
	while (a[0] >= 1 && a[1] >= 3) {
		++ans;
		a[0] -= 1, a[1] -= 3;
		if (a[1] < a[0]) {
			swap(a[0], a[1]);
		}
	}
	ans += a[1] / 5;
	return ans;
}

int main(int argc, char *argv[])
{
	string s;
	int r, g, b;
	while (getline(cin, s) && !s.empty()) {
		stringstream ss(s);
		ss >> r >> g >> b;
//		cout << r << "," << g << "," << b << endl;
		cout << solve(r, g, b) << endl;
	}
}
