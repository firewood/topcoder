#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
	double p, q;
	cin >> p >> q;
	double p1 = (1 - p) * q;
	double p2 = p * (1 - q) * q;
	bool ans = p1 < p2;
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
