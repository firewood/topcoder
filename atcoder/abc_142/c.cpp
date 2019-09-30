// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	while (true) {
		int n = -1, a;
		cin >> n;
		if (n <= 0) break;
		vector<int> order(n);
		for (int i = 0; i < n; ++i) {
			cin >> a;
			order[a - 1] = i;
		}
		for (int i = 0; i < n; ++i) {
			if (i) cout << " ";
			cout << (order[i] + 1);
		}
		cout << endl;
	}
	return 0;
}
