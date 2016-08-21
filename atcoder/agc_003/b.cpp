// B. 

#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	long long N, prev = 0, ans = 0;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		long long a;
		cin >> a;
		if (a > 0) {
			ans += (a + prev) / 2;
			prev = (a - prev) % 2;
		} else {
			prev = 0;
		}
	}
	cout << ans << endl;
	return 0;
}
