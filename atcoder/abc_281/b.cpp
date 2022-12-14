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

typedef long double LD;
typedef pair<int64_t, int64_t> II;
typedef pair<int64_t, II> III;

static const int64_t INF = 1LL << 60;

bool solve(std::string S) {
	return S.length() == 8 &&
		S.front() >= 'A' && S.front() <= 'Z' &&
		S.back() >= 'A' && S.back() <= 'Z' &&
		S.substr(1, 6) == to_string(stoi(S.substr(1)));
}

int main() {
	std::string S;
	std::cin >> S;
	cout << (solve(S) ? "Yes" : "No") << endl;
	return 0;
}
