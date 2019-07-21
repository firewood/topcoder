// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	LL s;
	cin >> s;
	LL a = (LL)ceil(sqrt(s));
	LL r = a * a - s;
	cout << "0 0 1 " << a << " " << a << " " << r << endl;
	return 0;
}
