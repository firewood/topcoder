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

bool solve(int64_t N, std::string S) {
	return S[0] == S[N - 1] || (N > 2 && S[N - 1] == 'A');
}

int main() {
	int64_t N;
	std::string S;
	std::cin >> N >> S;
	cout << (solve(N, S) ? "Yes" : "No") << endl;
	return 0;
}
