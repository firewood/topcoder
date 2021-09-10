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

bool solve(std::string S, std::string T) {
	return S < T;
}

int main() {
	std::string S, T;
	std::cin >> S >> T;
	cout << (solve(S, T) ? "Yes" : "No") << endl;
	return 0;
}
