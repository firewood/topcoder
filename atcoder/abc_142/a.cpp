// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	cout.precision(10);
	int n;
	cin >> n;
	double ans = (double)((n + 1) / 2) / n;
	cout << ans << endl;
	return 0;
}
