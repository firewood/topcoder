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

int solve(long long N) {
	int ans = 0;
	for (int i = 1; ; ++i) {
		string s = to_string(i);
		if (stoll(s + s) > N) break;
		++ans;
	}
	return ans;
}

int main() {
    long long N;
	std::cin >> N;
	cout << solve(N) << endl;
	return 0;
}
