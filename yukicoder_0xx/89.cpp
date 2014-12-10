#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	double c = atoi(s.c_str());
	getline(cin, s);
	stringstream ss(s);
	double i, o;
	ss >> i >> o;
	double a = (o - i) / 2;
	double b = 2 * (o + i) / 2;
	double ans = a * a * b * c * M_PI * M_PI;
	cout.precision(16);
	cout << ans << endl;
	return 0;
}
