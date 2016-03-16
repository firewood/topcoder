#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

int kind[1000000];
int seq[1000000];

int main(int argc, char *argv[])
{
	int H, W, N;
	cin >> H >> W >> N;
	for (int i = 0; i < N; ++i) {
		string S;
		cin >> S >> seq[i];
		kind[i] = S[0] == 'C';
	}
	int r = 0, c = 0;
	for (int i = N - 1; i >= 0; --i) {
		if (kind[i]) {
			if (seq[i] == c) {
				r = (r + H - 1) % H;
			}
		} else {
			if (seq[i] == r) {
				c = (c + W - 1) % W;
			}
		}
	}
	cout << (((r + c) % 2) ? "black" : "white") << endl;
	return 0;
}
