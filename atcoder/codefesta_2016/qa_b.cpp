#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[])
{
	int N, ans = 0;
	cin >> N;
	int f[100001] = {};
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		ans += f[a] == (i + 1);
		f[i + 1] = a;
	}
	cout << ans << endl;
	return 0;
}
