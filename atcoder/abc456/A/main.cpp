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

bool solve(int64_t X) {
	bool ans = X >= 3 && X <= 18;
	return ans;
}

int main() {
	int64_t X;
	cin >> X;
	auto ans = solve(X);
	cout << (ans ? YES : NO) << endl;
}
