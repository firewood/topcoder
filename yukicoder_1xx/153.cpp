#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int grundy[101];
	int N;
	cin >> N;
	grundy[1] = 0;
	for (int i = 2; i <= N; ++i) {
		int g[101] = {};
		g[grundy[i / 2] ^ grundy[(i + 1) / 2]] = 1;
		if (i >= 3) {
			g[grundy[i / 3] ^ grundy[(i + 1) / 3] ^ grundy[(i + 2) / 3]] = 1;
		}
		for (int j = 0; j <= N; ++j) {
			if (!g[j]) {
				grundy[i] = j;
				break;
			}
		}
	}
	cout << (grundy[N] ? "A" : "B") << endl;
	return 0;
}
