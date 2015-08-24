#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[])
{
	LL R, C;
	cin >> R >> C;
	LL ans = (R / 2) * C;
	if (R == C) {
		ans /= 2;
	}
	if (R % 2) {
		ans += C / 2 + (C % 2);
	}
	ans = max(0LL, ans - 1);
	cout << ans << endl;
	return 0;
}
