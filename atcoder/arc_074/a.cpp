// A.

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int x, y;
	cin >> x >> y;
	int g[] = {0,1,3,1,2,1,2,1,1,2,1,2,1};
	bool ans = g[x] == g[y];
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
