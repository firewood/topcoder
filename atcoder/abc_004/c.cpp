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

void solve(long long N) {
	N %= 30;
	vector<int> a = { 1,2,3,4,5,6 };
	for (int i = 0; i < N; ++i) {
		swap(a[i % 5], a[(i % 5) + 1]);
	}
	for (auto x : a) {
		cout << x;
	}
	cout << endl;
}

int main() {
    long long N;
	std::cin >> N;
	solve(N);
	return 0;
}
