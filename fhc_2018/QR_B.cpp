//
// Facebook Hacker Cup 2018 Qualification Round
// B. Interception
//

#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int n, p;
		cin >> n;
		for (int i = 0; i <= n; ++i) {
			cin >> p;
		}
		int ans = n % 2;
		cout << "Case #" << t << ": " << ans << endl;
		if (ans) {
			cout << "0.0" << endl;
		}
	}
	return 0;
}
