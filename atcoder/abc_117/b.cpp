// B.

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	bool ans = a[0] < accumulate(a.begin() + 1, a.end(), 0);
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
