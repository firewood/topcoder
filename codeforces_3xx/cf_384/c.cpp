// C.

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	int a = n + 1;
	int b = n * a;
	if (n == 1) {
		cout << -1 << endl;
	} else {
		cout << n << " " << a << " " << b << endl;
	}
	return 0;
}
