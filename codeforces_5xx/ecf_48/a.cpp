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
	int n, m;
	LL ans = 0, a, b = 0;
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		b += a;
		cout << (i ? " " : "") << (b / m);
		b %= m;
	}
	cout << endl;
	return 0;
}
