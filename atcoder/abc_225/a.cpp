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

int64_t solve(std::string S) {
	set<string> s;
	sort(S.begin(), S.end());
	do {
		s.insert(S);
	} while (next_permutation(S.begin(), S.end()));
	return s.size();
}

int main() {
	std::string S;
	std::cin >> S;
	cout << solve(S) << endl;
	return 0;
}
