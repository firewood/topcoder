#include <iostream>
#include <cmath>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	LL n;
	cin >> n;
	long double r = sqrt(n / 3 + 1);
	LL ans = (LL)r;
	cout << ans << endl;
	return 0;
}
