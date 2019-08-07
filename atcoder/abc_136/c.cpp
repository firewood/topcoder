// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<LL> h(n);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	bool ans = true;
	for (int i = n - 2; i >= 0; --i) {
		if (h[i] > h[i + 1]) {
			--h[i];
		}
		if (h[i] > h[i + 1]) {
			ans = false;
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
