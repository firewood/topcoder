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
const string YES = "Yes";
const string NO = "No";

bool solve(int64_t A, int64_t B, int64_t C) {
	bool ans = A != B && B == C;
	return ans;
}

int main() {
	int64_t A, B, C;
	std::cin >> A >> B >> C;
	auto ans = solve(A, B, C);
	cout << (ans ? YES : NO) << endl;
}
