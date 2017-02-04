// B. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	LL N, a[100000], sum = 0;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	LL x = (N * (N + 1)) / 2, y = sum / x;
	bool ans = (sum % x) == 0;
	if (ans) {
		int m;
		for (int i = 0; i < N; ++i) {
			if (a[i] < y || a[i] > N * y) {
				ans = false;
				break;
			}
			LL b = a[i] + (N - i) * y;
			if (i > 0 && m != (b % N)) {
				ans = false;
				break;
			} else {
				m = b % N;
			}
		}
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
