#include <iostream>
#include <algorithm>
#include <sstream>
#include <set>
#include <vector>

using namespace std;

int to_bit(int n) {
	int b = 0;
	while (n > 0) {
		b |= (1 << (n % 10));
		n /= 10;
	}
	return b;
}

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	int N = atoi(s.c_str());
	getline(cin, s);
	stringstream ss(s);
	int bits = 0;
	for (int i = 0; i < N; ++i) {
		int d;
		ss >> d;
		bits |= (1 << d);
	}

	int ans = -1;
	int current_bits = 0;
	int low = 1;
	int primes = 0;
	static int p[5000001] = {};
	for (int i = 2; i <= 5000000; ++i) {
		if (!p[i]) {
			int b = to_bit(i);
			if ((b & bits) != b) {
				if (bits == current_bits) {
					ans = max(ans, (i - 1 - low));
				}
				current_bits = 0;
				low = i + 1;
			} else {
				current_bits |= b;
			}
			for (int j = i * 2; j <= 5000000; j += i) {
				p[j] = 1;
			}
		}
	}
	if (bits == current_bits) {
		ans = max(ans, (5000000 - low));
	}
	cout << ans << endl;
	return 0;
}
