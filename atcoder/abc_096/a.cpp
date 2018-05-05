// A. 

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int a, b;
	cin >> a >> b;
	int ans = a - (b < a);
	cout << ans << endl;
	return 0;
}
