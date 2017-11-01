// A.
 
#include <iostream>
#include <sstream>
 
using namespace std;
 
int main(int argc, char *argv[])
{
	int a, b, c;
	cin >> a >> b >> c;
	bool ans = (b - a) == (c - b);
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
