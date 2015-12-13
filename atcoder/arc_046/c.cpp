// C.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	int N, M;
	cin >> N >> M;
	int A[150000], B[150000], C[150000], D[150000];
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i];
	}
	for (int i = 0; i < M; ++i) {
		cin >> C[i] >> D[i];
	}

	sort(A, A + N);
	sort(D, D + M);
	int ans = 0;
	int n = 0;
	for (int i = 0; i < M; ++i) {
		while (n < N && A[n] < D[i]) {
			++n;
		}
		if (n >= N) {
			break;
		}
		++n;
		++ans;
	}
	cout << ans << endl;
	return 0;
}
