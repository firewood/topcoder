// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int n, k;
	cin >> n >> k;
	vector<int> h(n);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	sort(h.rbegin(), h.rend());
	long long sum = accumulate(h.begin() + min((int)h.size(), k), h.end(), 0LL);
	cout << sum << endl;
	return 0;
}
