#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	getline(cin, s);
	stringstream ss(s);
	int a[2] = {};
	for (int i = 0; i < N; ++i) {
		int b;
		ss >> b;
		a[b & 1] += 1;
	}
	cout << abs(a[0] - a[1]) << endl;
	return 0;
}
