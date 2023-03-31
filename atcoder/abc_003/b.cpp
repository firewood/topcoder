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
	string atcoder = "atcoder";
	for (int i = 0; i < S.length(); ++i) {
		if (S[i] == T[i]) continue;
		if (S[i] == '@' && atcoder.find(T[i]) != string::npos) continue;
		if (T[i] == '@' && atcoder.find(S[i]) != string::npos) continue;
		return false;
	}
	return true;
}

int main() {
	std::string S, T;
	std::cin >> S >> T;
	cout << (solve(S, T) ? "You can win" : "You will lose") << endl;
	return 0;
}
