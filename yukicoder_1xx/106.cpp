#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	cout.precision(16);
	string s;
	getline(cin, s);
	stringstream ss(s);
	int N, K;
	ss >> N >> K;
	static int f[2000001];
	for (int i = 2; i <= N; ++i) {
		if (!f[i]) {
			for (int j = i; j <= N; j += i) {
				f[j] += 1;
			}
		}
	}
	int ans = 0;
	for (int i = 2; i <= N; ++i) {
		ans += f[i] >= K;
	}
	cout << ans << endl;
	return 0;
}
