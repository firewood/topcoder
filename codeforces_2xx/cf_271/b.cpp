
// B. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main(int argc, char *argv[])
{
	int N, M;
	string s;
	{
		getline(cin, s);
		stringstream ss(s);
		ss >> N;
	}
	static int a[100001];
	{
		getline(cin, s);
		stringstream ss(s);
		for (int i = 0; i < N; ++i) {
			ss >> a[i];
			if (i > 0) {
				a[i] += a[i - 1];
			}
		}
	}
	{
		getline(cin, s);
		stringstream ss(s);
		ss >> M;
	}
	{
		getline(cin, s);
		stringstream ss(s);
		for (int i = 0; i < M; ++i) {
			int d;
			ss >> d;
			int *pos = lower_bound(a, a + N, d);
			cout << (pos - a + 1) << endl;
		}
	}

	return 0;
}

