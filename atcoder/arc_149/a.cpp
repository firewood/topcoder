#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

string solve(int64_t N, int64_t M) {
	int64_t num_of_digits = -1, digit = -1, b = 1, tot = 1;
	for (int64_t n = 1; n <= N; ++n) {
		for (int64_t d = 1; d <= 9; ++d) {
			if (((d * tot) % M) == 0) {
				num_of_digits = n;
				digit = d;
			}
		}
		b = (b * 10) % M;
		tot = (tot + b) % M;
	}
	return num_of_digits < 0 ? "-1" : string(num_of_digits, char('0' + digit));
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	cout << solve(N, M) << endl;
	return 0;
}
