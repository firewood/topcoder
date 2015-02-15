#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

static int get_hash(int n) {
	if (n < 10) {
		return n;
	}
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return get_hash(sum);
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int K = atoi(s.c_str());
	getline(cin, s);
	int N = atoi(s.c_str());
	static int f[200001] = {};
	static int p[200001] = {};
	static int h[200001] = {};
	int primes = 0;
	int pos[10] = {};
	int mx[11] = {};
	int count = 0;
	int max_count = 0;
	int ans = 0;
	for (int i = 2; i <= N; ++i) {
		if (!f[i]) {
			for (int j = i * 2; j <= N; j += i) {
				f[j] = 1;
			}
			if (i >= K) {
				++count;
				int hash = get_hash(i);
				p[primes] = i;
				h[primes] = hash;
				++primes;
				int c = primes - mx[hash];
				if (c < count) {
					count = c;
				}
				if (count >= max_count) {
					max_count = count;
					ans = p[primes - count];
				}
				mx[hash] = primes;
			}
		}
	}

	cout << ans << endl;
	return 0;
}
