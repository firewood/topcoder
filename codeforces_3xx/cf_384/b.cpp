// B. 

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[])
{
	LL n, k;
	cin >> n >> k;
	--k;
	LL len = (1LL << n) - 1;
	LL ans = n;
	while (ans > 1) {
		LL h = len / 2;
		if (k == h) {
			break;
		}
		--ans;
		k = k % (h + 1);
		len = h;
	}
	cout << ans << endl;
	return 0;
}
