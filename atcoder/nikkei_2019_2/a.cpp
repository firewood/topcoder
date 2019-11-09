// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1;
		cin >> n;
		if (n <= 0) return 0;
		int ans = 0;
		for (int a = 1; a <= n / 2; ++a) {
			ans += a != (n - a);
		}
		cout << ans << endl;
	}
	return 0;
}
