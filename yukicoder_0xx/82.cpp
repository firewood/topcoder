#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int W, H;
	char C;
	cin >> W >> H >> C;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			cout << ((i + j + (C == 'W')) % 2 ? "W" : "B");
		}
		cout << endl;
	}
	return 0;
}
