// A. 

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int a, b;
	cin >> a >> b;
	cout << ((a <= 8 && b <= 8) ? "Yay!" : ":(") << endl;
	return 0;
}
