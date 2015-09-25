#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[])
{
	LL H, W, N, K;
	cin >> H >> W >> N >> K;
	LL T = H * W;
	if (T > N) {
		T -= ((T - 1) / N) * N;
	}
	cout << (T == K ? "YES" : "NO") << endl;
	return 0;
}
