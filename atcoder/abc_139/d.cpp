// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	LL n;
	cin >> n;
	LL ans = ((n - 1) * n) / 2;
	cout << ans << endl;
	return 0;
}
