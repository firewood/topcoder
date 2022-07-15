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

string solve(int K) {
	int t = 21 * 60 + K;
	char buffer[16];
	sprintf(buffer, "%02d:%02d", t / 60, t % 60);
	return buffer;
}

int main() {
	int K;
	std::cin >> K;
	cout << solve(K) << endl;
	return 0;
}
