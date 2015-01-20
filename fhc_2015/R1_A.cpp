//
// Facebook Hacker Cup 2015 Round 1
// A. Homework
//

/*
Constraints

1 <= T <= 100 
2 <= A <= B <= 10^7
1 <= K <= 10^9
*/

#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	static int cnt[10000002];
	memset(cnt, 0, sizeof(cnt));
	for (int i = 2; i <= 10000000; ++i) {
		if (!cnt[i]) {
			for (int j = i; j <= 10000000; j += i) {
				cnt[j] += 1;
			}
		}
	}

	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	for (int t = 0; t < T; ++t) {
		getline(cin, s);
		stringstream ss(s);
		int A, B, K;
		ss >> A >> B >> K;
		int ans = 0;
		for (int n = A; n <= B; ++n) {
			ans += cnt[n] == K;
		}
		cout << "Case #" << (t+1) << ": " << ans << endl;
	}

	return 0;
}
