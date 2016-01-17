//
// Facebook Hacker Cup 2016 Qualification Round
// C. The Price is Correct
//

#include <cstdint>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int64_t T;
	cin >> T;
	for (int64_t t = 1; t <= T; ++t) {
		int64_t ans = 0, N, P, b[100000], sum = 0, left = 0;
		cin >> N >> P;
		for (int i = 0; i < N; ++i) {
			cin >> b[i];
			sum += b[i];
			while (sum > P) {
				sum -= b[left++];
			}
			if (left <= i) {
				ans += i - left + 1;
			}
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
