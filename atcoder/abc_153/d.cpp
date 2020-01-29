// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		LL h = -1, ans = 0, d = 1;
		cin >> h;
		if (h < 0) return 0;
		while (h > 0) {
			ans += d;
			h /= 2;
			d *= 2;
		}
		cout << ans << endl;
	}
	return 0;
}
