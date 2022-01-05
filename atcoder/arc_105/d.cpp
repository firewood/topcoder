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

bool solve(int N, vector<int> A) {
	if (N % 2) {
		return false;
	}
	sort(A.begin(), A.end());
	for (int i = 1; i < N; i += 2) {
		if (A[i - 1] != A[i]) {
			return true;
		}
	}
	return false;
}

int main() {
	int T, N;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		cout << (solve(N, A) ? "First" : "Second") << endl;
	}
	return 0;
}
