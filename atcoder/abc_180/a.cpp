#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <queue>
#include <vector>

using namespace std;

long long solve(long long N, long long A, long long B) {
	return N - A + B;
}

int main() {
	long long N, A, B;
	std::cin >> N >> A >> B;
	cout << solve(N, A, B) << endl;
	return 0;
}
