#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
	double x, y;
	string s;
	getline(cin, s);
	stringstream ss(s);
	ss >> x >> y;
	double r = sqrt(x*x + y*y);
	cout << ceil(r * 2 + 1.0e-9) << endl;
	return 0;
}
