#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
	cout.precision(10);
	string s;
	getline(cin, s);
	double N = atoi(s.c_str()) * 100;
	double a = (1000000.0 - N) * 0.01;
	double b = N * 0.99;
	double ans = a / (a + b) * 100;
	cout << ans << endl;
	return 0;
}
