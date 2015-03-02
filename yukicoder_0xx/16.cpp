#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <set>
#include <vector>

using namespace std;
const int MOD = 1000003;

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	int x, N;
	{
		stringstream ss(s);
		ss >> x >> N;
	}
	vector<long long> a(N), b(N, 1);
	getline(cin, s);
	{
		stringstream ss(s);
		for (int i = 0; i < N; ++i) {
			ss >> a[i];
		}
	}
	long long p = 1, q = x;
	for (int i = 1; i <= 30; ++i) {
		for (int j = 0; j < N; ++j) {
			if (a[j] & p) {
				b[j] = (b[j] * q) % MOD;
			}
		}
		p *= 2;
		q = (q * q) % MOD;
	}
	long long ans = accumulate(b.begin(), b.end(), 0LL) % MOD;
	cout << ans << endl;
	return 0;
}
