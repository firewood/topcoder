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

size_t solve(long long N, std::string s) {
	string q;
	for (char c : s) {
		q += c;
		while (q.length() >= 3 && q.substr(q.length() - 3) == "fox") {
			q = q.substr(0, q.length() - 3);
		}
	}
	return q.length();
}

int main() {
	long long N;
	std::cin >> N;
	std::string s;
	std::cin >> s;
	cout << solve(N, s) << endl;
	return 0;
}
