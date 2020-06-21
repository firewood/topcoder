// C.

#include <iostream>
#include <sstream>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <set>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	LL n;
	cin >> n;
	string ans;
	while (n > 0) {
		--n;
		ans += ('a' + n % 26);
		n /= 26;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}
