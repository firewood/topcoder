// B.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	long long a, b, x, ans;
	cin >> a >> b >> x;
	ans = (b + x) / x - (a + x - 1) / x;
	cout << ans << endl;
	return 0;
}
