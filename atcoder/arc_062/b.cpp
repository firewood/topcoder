// B.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	long long n, k;
	cin >> n >> k;
	long long ans = k;
	for (int i = 1; i < n; ++i) {
		ans *= (k - 1);
	}
	cout << ans << endl;
	return 0;
}
