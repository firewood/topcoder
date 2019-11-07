// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int a, b;
	cin >> a >> b;
	a = (a + 11) % 13;
	b = (b + 11) % 13;
	cout << (a == b ? "Draw" : (a > b ? "Alice" : "Bob")) << endl;
	return 0;
}
