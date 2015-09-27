#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int X[100000];

bool possible(int t) {
	int right = 0;
	for (int i = 0; i < M; ++i) {
		int d = X[i] - (right + 1);
		if (d > t) {
			return false;
		}
		if (d > 0) {
			right = max(X[i] + max(0, (t - d) / 2), right + 1 + max(0, t - d));
		} else {
			right = max(right, X[i] + t);
		}
	}
	return right >= N;
}

int main(int argc, char *argv[])
{
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> X[i];
	}

	int low = -1, high = N * 2;
	while (high - low > 1) {
		int med = (low + high) / 2;
		if (possible(med)) {
			high = med;
		} else {
			low = med;
		}
	}
	cout << high << endl;
	return 0;
}
