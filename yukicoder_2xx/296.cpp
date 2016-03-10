#include <iostream>
#include <sstream>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[])
{
	LL N, H, M, T;
	cin >> N >> H >> M >> T;
	M += H * 60 + T * (N - 1);
	cout << (M / 60) % 24 << endl;
	cout << (M % 60) << endl;
	return 0;
}
