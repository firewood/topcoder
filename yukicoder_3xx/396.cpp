#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int N, M, X, Y;
	cin >> N >> M >> X >> Y;
	X = (X - 1) % (2 * M);
	Y = (Y - 1) % (2 * M);
	if (X >= M) {
		X = 2 * M - X - 1;
	}
	if (Y >= M) {
		Y = 2 * M - Y - 1;
	}
	cout << ((X == Y) ? "YES" : "NO") << endl;
	return 0;
}
