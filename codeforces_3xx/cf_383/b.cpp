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
	LL n, x;
	cin >> n >> x;
	LL cnt[320000] = {}, ans = 0;
	for (int i = 0; i != n; ++i) {
		LL a;
		cin >> a;
		ans += cnt[a ^ x];
		cnt[a] += 1;
	}
	cout << ans << endl;
	return 0;
}
