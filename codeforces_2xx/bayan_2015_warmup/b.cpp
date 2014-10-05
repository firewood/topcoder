
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
		ss >> N >> M;
	}
	string h, v;
	getline(cin, h);
	getline(cin, v);
	bool p = (h[0] == '<' && v[0] == 'v' && h.back() == '>' &&  v.back() == '^') ||
		(h[0] == '>' && v[0] == '^' && h.back() == '<' &&  v.back() == 'v');
	cout << (p ? "YES" : "NO") << endl;
	return 0;
}

