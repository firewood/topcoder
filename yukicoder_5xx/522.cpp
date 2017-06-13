#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	for (int a = 1; a <= n / 3; ++a) {
		for (int b = a; b <= n - b - a; ++b) {
			int c = n - b - a;
			cout << a << " " << b << " " << c << endl;
		}
	}
	return 0;
}
