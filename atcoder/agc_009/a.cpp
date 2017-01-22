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
	int N;
	cin >> N;
	LL a[100000], b[100000];
	for (int i = 0; i < N; ++i) {
		cin >> a[i] >> b[i];
	}
	LL ans = 0;
	for (int i = N - 1; i >= 0; --i) {
		LL r = (ans + a[i]) % b[i];
		ans += (b[i] - r) % b[i];
	}
	cout << ans << endl;
	return 0;
}
