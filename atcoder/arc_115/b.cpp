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

vector<vector<int>> solve(int N, const vector<vector<int>>& A) {
	int c = *min_element(A[0].begin(), A[0].end());
	vector<int> a(N), b(N);
	for (int j = 0; j < N; ++j) {
		b[j] = A[0][j] - c;
	}
	for (int i = 1; i < N; i++) {
		c = *min_element(A[i].begin(), A[i].end());
		for (int j = 0; j < N; ++j) {
			if (A[i][j] - c != b[j]) {
				return {};
			}
		}
	}
	for (int i = 0; i < N; i++) {
		a[i] = A[i][0] - b[0];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; ++j) {
			if (A[i][j] != a[i] + b[j]) {
				return {};
			}
		}
	}
	return { a, b };
}

int main() {
	int N;
	cin >> N;
	vector<vector<int>> A(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<int>> ans = solve(N, A);
	if (ans.empty()) {
		cout << "No" << endl;
	} else {
		cout << "Yes" << endl;
		for (auto a : ans) {
			string delim = "";
			for (auto x : a) {
				cout << delim << x;
				delim = " ";
			}
			cout << endl;
		}
	}
	return 0;
}
