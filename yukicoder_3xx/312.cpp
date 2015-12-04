#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	long long N;
	cin >> N;
	long long ans = N;
	if (N > 4 && (ans % 2) == 0) {
		ans = N / 2;
	}
	for (long long x = 3; x * x <= N; ++x) {
		if ((N % x) == 0) {
			ans = x;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
