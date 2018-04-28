// A. 

#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;
typedef map<LL, LL> LLMap;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	LL ans = 0, sum = 0;
	LLMap m;
	m[0] = 1;
	for (int i = 0; i < n; ++i) {
		LL a;
		cin >> a;
		sum += a;
		ans += m[sum];
		m[sum] += 1;
	}
	cout << ans << endl;
	return 0;
}
