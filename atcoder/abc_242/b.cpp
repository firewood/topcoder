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

string solve(std::string S) {
	sort(S.begin(), S.end());
	return S;
}

int main() {
	std::string S;
	std::cin >> S;
	cout << solve(S) << endl;
	return 0;
}
