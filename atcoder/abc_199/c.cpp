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

string solve(int N, std::string S, int Q, std::vector<int> &T, std::vector<int> &A, std::vector<int> &B) {
	string s[2] = { S.substr(0, N), S.substr(N) };
	for (int i = 0; i < Q; i++) {
		if (T[i] == 1) {
			int a = A[i], b = B[i];
			swap(s[a / N][a % N], s[b / N][b % N]);
		} else {
			swap(s[0], s[1]);
		}
	}
	return s[0] + s[1];
}

int main() {
	int N, Q;
	std::string S;
	std::cin >> N >> S >> Q;
	std::vector<int> T(Q), A(Q), B(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> T[i] >> A[i] >> B[i];
		--A[i], --B[i];
	}
	cout << solve(N, S, Q, T, A, B) << endl;
	return 0;
}
