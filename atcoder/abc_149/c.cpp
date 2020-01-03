// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> gen_primes(int m) {
	vector<int> primes;
	primes.push_back(2);
	for (int i = 3; i <= m; i += 2) {
		for (int prime : primes) {
			if (i < prime * prime) {
				primes.push_back(i);
				break;
			}
			if ((i % prime) == 0) {
				break;
			}
		}
	}
	return primes;
}

int main(int argc, char* argv[]) {
	vector<int> primes = gen_primes(100005);
	int x;
	cin >> x;
	for (int n : primes) {
		if (n >= x) {
			cout << n << endl;
			break;
		}
	}
	return 0;
}
