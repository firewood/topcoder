// A. 

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int n, a, b;
	cin >> n >> a >> b;
	bool ans = false;
	while (n > 0) {
		n -= a;
		ans = n <= 0;
		n -= b;
	}
	cout << (ans ? "Ant" : "Bug") << endl;
	return 0;
}
