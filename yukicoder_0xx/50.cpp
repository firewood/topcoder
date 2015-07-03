#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int N, M;
int A[10];
int B[10];

int main(int argc, char *argv[])
{
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	cin >> M;
	for (int i = 0; i < M; ++i) {
		cin >> B[i];
	}

	sort(A, A + N);
	sort(B, B + M);

	int ans = 1 << 30;
	do {
		int i = 0;
		for (int j = 0; j < M; ++j) {
			int r = B[M - j - 1];
			while (i < N && r >= A[i]) {
				r -= A[i];
				++i;
			}
			if (i >= N) {
				ans = min(ans, j + 1);
				break;
			}
		}
	} while (next_permutation(A, A + N));
	cout << (ans < (1 << 30) ? ans : -1) << endl;
	return 0;
}
