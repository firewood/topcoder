// B.

#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		int N;
		cin >> N;
		int ans = 0;
		int prev = 1;
		for (int i = 0; i < N; ++i) {
			int g;
			cin >> g;
			if (!prev && !g) {
				++ans;
				prev = 1;
			} else {
				prev = g;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
