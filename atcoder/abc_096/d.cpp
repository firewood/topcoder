// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

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

int main(int argc, char *argv[])
{
	vector<int> primes = gen_primes(55555);
	int n;
	cin >> n;
	string delim = "";
	int cnt = 0;
	for (int a : primes) {
		if ((a % 100) == 1) {
			cout << delim << a;
			delim = " ";
			if (++cnt >= n) {
				break;
			}
		}
	}
	cout << endl;
	return 0;
}
