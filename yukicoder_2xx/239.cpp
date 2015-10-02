#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	int cnt[100] = {};
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			string s;
			cin >> s;
			cnt[j] += s.compare("nyanpass") == 0;
		}
	}
	int ans = -1;
	for (int i = 0; i < N; ++i) {
		if (cnt[i] >= (N - 1)) {
			if (ans >= 0) {
				ans = -1;
				break;
			}
			ans = i + 1;
		}
	}
	cout << ans << endl;
	return 0;
}
