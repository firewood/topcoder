// A. 

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int n, a;
	cin >> n >> a;
	bool ans = a >= (n % 500);
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
