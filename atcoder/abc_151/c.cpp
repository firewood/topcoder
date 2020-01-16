// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int n, m, p, tac = 0, twa = 0;
	string s;
	cin >> n >> m;
	vector<int> ac(n + 1), wa(n + 1);
	for (int i = 0; i < m; ++i) {
		cin >> p >> s;
		if (s == "AC") {
			if (!ac[p]) {
				ac[p] = 1;
				++tac;
				twa += wa[p];
			}
		} else {
			if (!ac[p]) {
				wa[p] += 1;
			}
		}
	}
	cout << tac << " " << twa << endl;
	return 0;
}
