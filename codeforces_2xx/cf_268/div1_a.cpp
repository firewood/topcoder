
// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int N;
	string s;
	getline(cin, s);
	stringstream ss(s);
	ss >> N;
	if (N < 4) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;

	int n = N;

	int k;
	if (n % 4 == 0){
		k = 5;
	} else if (n % 4 == 1){
		k = 6;
	} else if (n % 4 == 2){
		k = 7;
	} else {
		k = 8;
	}
	if (N < k){
		return 0;
	}
	int l = N - k + 1;
	l = l / 2;
	for (int i = k; i < k + l; ++i){
		printf("%d + %d = %d\n", i, n + k - i, n + k);
	}
	l = l / 2;
	for (int i = 0; i < l; ++i){
		printf("%d - %d = 0\n", n + k, n + k);
	}
	for (int i = 0; i < l;++i){
		printf("24 + 0 = 24\n");
	}

	return 0;
}

