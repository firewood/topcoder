// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <locale>

using namespace std;

int main(int argc, char *argv[]) {
	int a, b;
	cin >> a >> b;
	int ans = a >= 13 ? b : (a >= 6 ? b / 2 : 0);
	cout << ans << endl;
	return 0;
}
