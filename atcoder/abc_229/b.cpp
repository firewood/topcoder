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

bool solve(int64_t A, int64_t B) {
	string a = string(20, '0') + to_string(A), b = string(20, '0') + to_string(B);
	for (int i = 0; i < 20; ++i) {
		if (*(a.rbegin() + i) - '0' + *(b.rbegin() + i) - '0' >= 10) {
			return true;
		}
	}
	return false;
}

int main() {
	int64_t A, B;
	std::cin >> A >> B;
	bool ans = solve(A, B);
	cout << (ans ? "Hard" : "Easy") << endl;
	return 0;
}
