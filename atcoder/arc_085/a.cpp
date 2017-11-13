// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	string a, b;
	cin >> a >> b;
	cout << (a == b ? "=" : (a > b ? ">" : "<")) << endl;
	return 0;
}
