#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
	int f[20001] = {};
	int memo[20001];
	memset(memo, -1, sizeof(memo));
	memo[0] = 0;
	for (int i = 2; i <= 20000; ++i) {
		if (!f[i]) {
			for (int j = i * 2; j <= 20000; j += i) {
				f[j] = 1;
			}
			for (int j = 20000; j >= i; --j) {
				if (memo[j - i] >= 0) {
					memo[j] = max(memo[j], memo[j - i] + 1);
				}
			}
		}
	}
	int n;
	cin >> n;
	cout << memo[n] << endl;
	return 0;
}
