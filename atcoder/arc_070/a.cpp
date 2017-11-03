// A.
 
#include <iostream>
#include <sstream>
 
using namespace std;
 
int main(int argc, char *argv[])
{
	string a, b;
	cin >> a >> b;
	bool ans = a == b;
	cout << (ans ? "H" : "D") << endl;
	return 0;
}
