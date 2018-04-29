// B.

#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			for (int k = j + 1; k < n; ++k) {
				cnt += s[j][(k + i) % n] == s[k][(i + j) % n];
			}
		}
		if (cnt == ((n - 1) * n) / 2) {
			ans += n;
		}
	}
	cout << ans << endl;
	return 0;
}
