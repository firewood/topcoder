#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int64_t solve(int64_t L, int64_t R) {
	int64_t ans = R - L + 1;
	return ans;
}

int main() {
	int64_t L, R;
	std::cin >> L >> R;
	auto ans = solve(L, R);
	cout << ans << endl;
}
