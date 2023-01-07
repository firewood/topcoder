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

int main() {
	int64_t T, N;
	cin >> T;
	for (int tt = 0; tt < T; ++tt) {
		cin >> N;
		int64_t p, q;
		for (int64_t a = 2; a <= 5000000; ++a) {
			if ((N % a) == 0) {
				N /= a;
				if ((N % a) == 0) {
					p = a, q = N / a;
				} else {
					p = sqrt(N), q = a;
				}
				break;
			}
		}
		cout << p << " " << q << endl;
	}
	return 0;
}
