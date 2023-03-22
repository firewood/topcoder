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

typedef pair<int64_t, int64_t> II;

II solve(int64_t A) {
	return { A + 1, A };
}

int main() {
	int64_t A;
	std::cin >> A;
	II ans = solve(A);
	cout << ans.first << " " << ans.second << endl;
	return 0;
}
