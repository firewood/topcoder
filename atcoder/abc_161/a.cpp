// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int x, y, z;
	cin >> x >> y >> z;
	swap(x, y);
	swap(x, z);
	cout << x << " " << y << " " << z << endl;
	return 0;
}
