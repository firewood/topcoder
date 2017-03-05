// B.

#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	LL N, K;
	cin >> N >> K;
	vector<LL> A(N);
	for (LL i = 0; i < N; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	LL ans = accumulate(A.begin(), A.begin() + K, 0LL) + (K * (K - 1)) / 2;
	cout << ans << endl;
	return 0;
}
