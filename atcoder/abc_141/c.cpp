// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	while (true) {
		int n = -1, k, q;
		cin >> n >> k >> q;
		if (n <= 0) break;
		vector<int> v(n);
		for (int i = 0; i < q; ++i) {
			int a;
			cin >> a;
			v[a - 1] += 1;
		}
		for (int i = 0; i < n; ++i) {
			cout << ((k + v[i] - q) > 0 ? "Yes" : "No") << endl;
		}
	}
	return 0;
}
