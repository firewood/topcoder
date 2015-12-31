// B. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

typedef long long LL;

LL count(LL a) {
	int r = 0;
	int c = 0;
	LL x = a;
	while (x > 0) {
		++c;
		x /= 2;
	}
	for (int i = 1; i < c; ++i) {
		r += i - 1;
	}
	LL m = (1LL << c) - 1;
	for (int i = c - 2; i >= 0; --i) {
		LL b = m ^ (1LL << i);
		if (b > a) {
			break;
		}
		++r;
	}
	return r;
}

int main(int argc, char *argv[])
{
	LL a, b;
	cin >> a >> b;
	cout << (count(b) - count(a - 1)) << endl;
	return 0;
}
