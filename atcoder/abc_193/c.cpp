#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

LL solve(long long N) {
	unordered_set<LL> s;
	for (LL i = 2; i * i <= N; ++i) {
		for (LL j = i * i; j <= N; j *= i) {
			s.insert(j);
		}
	}
	return N - s.size();
}

int main() {
    long long N;
	std::cin >> N;
	cout << solve(N) << endl;
	return 0;
}
