// B. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

bool solve(int N, int A, int B) {
	if (N <= A || A > B) {
		return true;
	}
	if (B > A) {
		return false;
	}
	return N % (A + 1) != 0;
}

int main(int argc, char *argv[])
{
	int N, A, B;
	cin >> N >> A >> B;
	string ans = solve(N, A, B) ? "Takahashi" : "Aoki";
	cout << ans << endl;
	return 0;
}
