// A.
 
#include <iostream>
 
using namespace std;
 
int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	int ans = 800 * n - (200 * (n / 15));
	cout << ans << endl;
	return 0;
}
