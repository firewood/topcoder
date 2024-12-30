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

bool solve(int64_t A, int64_t B, int64_t C, int64_t D) {
	vector<int64_t> a({ A, B, C, D });
	sort(a.begin(), a.end());
	bool ans = false;
	if (a[0] == a[2] && a[2] != a[3]) return true;
	if (a[0] != a[1] && a[1] == a[3]) return true;
	if (a[0] == a[1] && a[1] != a[2] && a[2]==a[3]) return true;
	return ans;
}

int main() {
	int64_t A, B, C, D;
	std::cin >> A >> B >> C >> D;
	cout << (solve(A, B, C, D) ? "Yes" : "No") << endl;
	return 0;
}
