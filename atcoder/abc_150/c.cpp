// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int n, a = 0, b = 0, c = 0;
	cin >> n;
	vector<int> seq(n), p(n), q(n);
	for (int i = 0; i < n; ++i) {
		seq[i] = i + 1;
		cin >> p[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> q[i];
	}
	do {
		++c;
		if (seq == p) {
			a = c;
		}
		if (seq == q) {
			b = c;
		}
	} while (next_permutation(seq.begin(), seq.end()));
	cout << abs(b - a) << endl;
	return 0;
}
