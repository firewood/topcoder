// B.

#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
	string a, b;
	cin >> a >> b;
	string s = a + b;
	stringstream ss(s);
	int x;
	ss >> x;
	int r = sqrt(x);
	bool ans = r * r == x;
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
