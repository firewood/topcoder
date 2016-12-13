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
	long long N, x, prev = 0, ans = 0;
	cin >> N >> x;
	for (int i = 0; i != N; ++i) {
		long long a;
		cin >> a;
		int op = max(0LL, a + prev - x);
		prev = a - op;
		ans += op;
	}
	cout << ans << endl;
	return 0;
}
