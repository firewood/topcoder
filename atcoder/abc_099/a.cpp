// A. 

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	cout << (n < 1000 ? "ABC" : "ABD") << endl;
	return 0;
}
