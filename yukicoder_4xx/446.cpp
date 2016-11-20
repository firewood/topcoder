#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	string a, b;
	cin >> a >> b;
	int ai = atoi(a.c_str()), bi = atoi(b.c_str());
	char wa[16], wb[16];
	sprintf(wa, "%d", ai);
	sprintf(wb, "%d", bi);
	bool ans = strcmp(a.c_str(), wa) == 0 && strcmp(b.c_str(), wb) == 0 &&
		ai >= 0 && ai <= 12345 && bi >= 0 && bi <= 12345;
	cout << (ans ? "OK" : "NG") << endl;
	return 0;
}
