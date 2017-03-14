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
	int N, a[100000], ans = 0;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	sort(a, a + N);
	LL tot = 0;
	for (int i = 0; i < N; ++i) {
		if (tot * 2 < a[i]) {
			ans = 0;
		}
		++ans;
		tot += a[i];
	}
	cout << ans << endl;
	return 0;
}
