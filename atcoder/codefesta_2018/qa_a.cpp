// A. 

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int a, b, c, s;
	cin >> a >> b >> c >> s;
	s -= a + b + c;
	bool ans = s >= 0 && s <= 3;
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
