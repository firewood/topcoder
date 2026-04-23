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

string strip(string &s) {
	string r;
	for (char c : s) {
		r += c;
		if (c == ')' && r.length() >= 4 && r.substr(r.length() - 4) == "(xx)") {
			r.erase(r.end() - 4, r.end());
			r += "xx";
		}
	}
	return r;
}

bool solve(std::string A, std::string B) {
	return strip(A) == strip(B);
}

void process_case() {
	std::string A, B;
	std::cin >> A >> B;
	auto ans = solve(A, B);
	cout << (ans ? YES : NO) << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		process_case();
	}
}
