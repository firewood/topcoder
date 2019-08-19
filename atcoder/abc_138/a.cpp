// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	string s;
	int a;
	cin >> a >> s;
	cout << (a >= 3200 ? s : "red") << endl;
	return 0;
}
