#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int M, N;
	cin >> M >> N;
	int ans = 0;
	while (M != N) {
		if (M == 1) {
			ans += N;
			break;
		}
		if (N == 1) {
			ans += (M - 1);
			break;
		}
		if (M > N) {
			int x = (M - 1) / N;
			ans += x;
			M -= x * N;
		} else {
			++ans;
			swap(M, N);
		}
	}
	cout << ans << endl;
	return 0;
}
