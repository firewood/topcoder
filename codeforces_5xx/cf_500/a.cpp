// A. 

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	int n, x, y;
	cin >> n;
	int a = 0, b = 0;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		a += x;
	}
	for (int i = 0; i < n; ++i) {
		cin >> y;
		b += y;
	}
	cout << (b <= a ? "Yes" : "No") << endl;
	return 0;
}
