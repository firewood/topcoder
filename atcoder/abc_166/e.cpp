// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		LL ans = 0;
		int n = -1, a;
		cin >> n;
		if (n < 0) return 0;
		map<int, int> m;
		
		for (int i = 0; i < n; ++i) {
			cin >> a;
			int d = (n - 1 - i);
			a -= d;
			int sum = -d * 2 - a;
			ans += m[sum];
			m[a] += 1;
		}
		cout << ans << endl;
	}
	return 0;
}
