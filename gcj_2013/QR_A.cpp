/*
Google Code Jam 2013 Qualification Round 
Problem A. Tic-Tac-Toe-Tomek
*/

#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

string s[5];

bool is_win(char player, int x, int y, int dx, int dy)
{
	for (int i = 0; i < 4; ++i, x += dx, y += dy) {
		if (s[y][x] != player && s[y][x] != 'T') {
			return false;
		}
	}
	return true;
}

string solve(void)
{
	int i, j, player;
	const char *players[2] = {"X","O"};
	for (player = 0; player < 2; ++player) {
		string s = players[player];
		for (i = 0; i < 4; ++i) {
			if (is_win(s[0], i, 0, 0, 1)) {
				return s + " won";
			}
			if (is_win(s[0], 0, i, 1, 0)) {
				return s + " won";
			}
			if (is_win(s[0], 0, 0, 1, 1)) {
				return s + " won";
			}
			if (is_win(s[0], 0, 3, 1, -1)) {
				return s + " won";
			}
		}
	}

	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j) {
			if (s[i][j] == '.') {
				return "Game has not completed";
			}
		}
	}

	return "Draw";
}

int main(int argc, char *argv[])
{
	getline(cin, s[0]);
	int N = atoi(s[0].c_str());
	if (N <= 0) return 0;

	for (int T = 0; T < N; ++T) {
		for (int i = 0; i < 5; ++i) {
			getline(cin, s[i]);
		}
		cout << "Case #" << (T+1) << ": " << solve() << endl;
	}

	return 0;
}

