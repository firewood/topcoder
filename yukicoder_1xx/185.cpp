#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
	int N;
	cin >> N;
	int x, y;
	cin >> x >> y;
	int ans = y - x;
	if (ans <= 0) {
		ans = -1;
	}
	for (int i = 1; i < N; ++i) {
		cin >> x >> y;
		if ((y - x) != ans) {
			ans = -1;
		}
	}
	cout << ans << endl;
	return 0;
}
