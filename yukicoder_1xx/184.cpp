#include <iostream>
#include <cstdint>

using namespace std;

int main(int argc, char *argv[]) {
	int64_t N, A[100000], i, j, k, bits = 0;
	cin >> N;
	for (i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (i = 0; i < N; ++i) {
		if (A[i]) {
			++bits;
			for (k = 1; k <= A[i]; k <<= 1) {
				;
			}
			k >>= 1;
			for (j = i + 1; j < N; ++j) {
				if (A[j] & k) {
					A[j] ^= A[i];
				}
			}
		}
	}
	cout << (1LL << bits) << endl;
	return 0;
}
