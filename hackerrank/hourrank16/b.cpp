// B. 

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	vector<LL> x { 0,1,2,3,5,6,9,10,13,17 };
	set<LL> s(x.begin(), x.end());
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		LL a;
		cin >> a;
		cout << (s.find(a) == s.end() ? "Yes" : "No") << endl;
	}
	return 0;
}
