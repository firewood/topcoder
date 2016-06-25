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
	LL A, B, K, L;
	cin >> A >> B >> K >> L;
	LL ans = min((K % L) * A + (K / L) * B, (K / L + 1) * B);
	cout << ans << endl;
	return 0;
}
