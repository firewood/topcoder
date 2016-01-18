//
// Facebook Hacker Cup 2016 Round 1
// A. Coding Contest Creation
//

/*
Constraints

1 <= T <= 50
1 <= N <= 100,000
1 <= Di <= 100

*/

#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N, cnt = 0, prev = 0, ans = 0;
		cin >> N;
		for (int n = 0; n < N; ++n) {
			int d;
			cin >> d;
			while (cnt > 0 && !(d > prev && d <= (prev + 10))) {
				++ans;
				prev += 10;
				cnt = (cnt + 1) % 4;
			}
			prev = d;
			cnt = (cnt + 1) % 4;
		}
		ans += (4 - cnt) % 4;
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
