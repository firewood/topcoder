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

int64_t solve(int A, int B, int C, int D, int E) {
	set<int> s({ A,B,C,D,E });
	return s.size();
}

int main() {
	int A, B, C, D, E;
	std::cin >> A >> B >> C >> D >> E;
	cout << solve(A, B, C, D, E) << endl;
	return 0;
}
