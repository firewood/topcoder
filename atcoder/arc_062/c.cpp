// C.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[])
{
	LL N, T, A;
	cin >> N >> T >> A;
	for (int i = 1; i < N; ++i) {
		LL t, a;
		cin >> t >> a;
		LL b = max(T / t, A / a);
		LL x = b * t, y = b * a;
		while (x < T || y < A) {
			x += t, y += a;
		}
		T = x, A = y;
	}
	cout << (T + A) << endl;
	return 0;
}
