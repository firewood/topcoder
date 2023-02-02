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

int main() {
	int N, L;
	cin >> N >> L;
	std::vector<string> a(L+1);
	getline(cin, a[0]);
	for (int i = 0; i <= L; i++) {
		getline(cin, a[i]);
	}
	int pos = a[L].find('o');
	for (int i = L - 1; i >= 0; --i) {
		if (pos > 0 && a[i][pos - 1] == '-') {
			pos -= 2;
		} else if (pos < N * 2 && a[i][pos + 1] == '-') {
			pos += 2;
		}
	}
	int ans = 1 + pos / 2;
	cout << ans << endl;
	return 0;
}
