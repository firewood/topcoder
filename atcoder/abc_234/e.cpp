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

string solve(string X) {
	if (X.length() == 1) return X;
	for (char c = X[0]; c <= '9'; ++c) {
		for (char d = '0'; d <= '9'; ++d) {
			string x = [&](string x) {
				x[0] = c;
				x[1] = d;
				for (int i = 2; i < (int)X.length(); ++i) {
					int next = x[i - 1] + d - c;
					if (next < '0' || next > '9') return string();
					x[i] = char(next);
				}
				return x;
			}(X);
			if (!x.empty() && x >= X) {
				return x;
			}
		}
	}
}

int main() {
	string X;
	std::cin >> X;
	cout << solve(X) << endl;
	return 0;
}
