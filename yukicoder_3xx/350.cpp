#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
	long double v, t;
	cin >> v >> t;
	long double ans = (v + 1.0e-10) * (t + 1.0e-10);
	cout << floor(ans) << endl;
	return 0;
}
