// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[])
{
	LL a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	LL ans = (a[2] % 2) * a[0] * a[1];
	cout << ans << endl;
	return 0;
}
