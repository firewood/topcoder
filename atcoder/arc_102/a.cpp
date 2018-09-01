// A. 

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int k;
	cin >> k;
	int ans = (k / 2) * ((k + 1) / 2);
	cout << ans << endl;
	return 0;
}
