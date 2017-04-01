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
	int N, a[300000];
	cin >> N;
	for (int i = 0; i < N * 3; ++i) {
		cin >> a[i];
	}
	sort(a, a + N * 3);
	LL ans = 0;
	for (int i = 0; i < N; ++i) {
		ans += a[N + i * 2];
	}
	cout << ans << endl;
	return 0;
}
