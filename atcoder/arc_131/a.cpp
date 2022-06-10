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

string solve(int64_t A, int64_t B) {
	return to_string(A) + "0" + to_string(B * 5);
}

int main() {
	int64_t A, B;
	std::cin >> A >> B;
	cout << solve(A, B) << endl;
	return 0;
}
