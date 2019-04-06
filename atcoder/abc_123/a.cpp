// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
	int pos[5], k;
	for (int i = 0; i < 5; ++i) {
		cin >> pos[i];
	}
	cin >> k;
	sort(pos, pos + 5);
	bool ans = pos[4] - pos[0] <= k;
	cout << (ans ? "Yay!" : ":(") << endl;
	return 0;
}
