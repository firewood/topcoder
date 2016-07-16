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
	LL N, L[200], ans = 0;
	cin >> N;
	for (int i = 0; i < N * 2; ++i) {
		cin >> L[i];
	}
	sort(L, L + N * 2);
	for (int i = 0; i < N; ++i) {
		ans += L[i * 2];
	}
	cout << ans << endl;
	return 0;
}
