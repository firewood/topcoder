#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int N, Q, t, k, x;
	cin >> N;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		cin >> t >> k;
		if (t == 1) {
			cin >> x;
			A[k - 1] = x;
		}
		if (t == 2) {
			cout << A[k - 1] << endl;
		}
	}
	return 0;
}
