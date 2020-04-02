// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int x;
	cin >> x;
	int a = x / 500;
	int ans = a * 1000 + ((x - a * 500) / 5) * 5;
	cout << ans << endl;
	return 0;
}
