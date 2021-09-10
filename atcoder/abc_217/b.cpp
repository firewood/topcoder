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

string solve(std::vector<std::string> S) {
	set<string> s;
	s.insert("ABC");
	s.insert("ARC");
	s.insert("AGC");
	s.insert("AHC");
	for (auto x : S) {
		s.erase(x);
	}
	return *(s.begin());
}

int main() {
	std::vector<std::string> S(3);
	for (int i = 0; i < 3; i++) {
		std::cin >> S[i];
	}
	cout << solve(S) << endl;
	return 0;
}
