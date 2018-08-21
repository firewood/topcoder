// B. 

#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	int ans = max(0, ((n - 75) / 30)) + (n >= 189);
	cout << ans << endl;
	return 0;
}
