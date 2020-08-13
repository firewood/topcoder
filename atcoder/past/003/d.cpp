// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
	string digits[] = {
		".###..#..###.###.#.#.###.###.###.###.###.",
		".#.#.##....#...#.#.#.#...#.....#.#.#.#.#.",
		".#.#..#..###.###.###.###.###...#.###.###.",
		".#.#..#..#.....#...#...#.#.#...#.#.#...#.",
		".###.###.###.###...#.###.###...#.###.###.",
	};
	int n;
	cin >> n;
	string s[5];
	for (int i = 0; i < 5; ++i) {
		cin >> s[i];
	}
	string ans;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= 9; ++j) {
			bool ok = true;
			for (int k = 0; k < 5; ++k) {
				for (int l = 0; l < 3; ++l) {
					if (s[k][i * 4 + l + 1] != digits[k][j * 4 + l + 1]) {
						ok = false;
					}
				}
			}
			if (ok) {
				ans += ('0' + j);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
