#include <iostream>
#include <sstream>
using namespace std;
int main(int argc, char *argv[])
{
	int N, M;
	cin >> N >> M;
	int cnt[100001] = {};
	int ans = -1;
	for (int i = 0; i != N; ++i) {
		int a;
		cin >> a;
		cnt[a] += 1;
		if (cnt[a] > N / 2) {
			ans = a;
			break;
		}
	}
	if (ans < 0) {
		cout << "?" << endl;
	} else {
		cout << ans << endl;
	}
	return 0;
}
