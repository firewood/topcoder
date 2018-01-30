// B. 

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(int argc, char *argv[])
{
	int n, m;
	cin >> n >> m;
	map<string, string> servers;
	for (int i = 0; i < n; ++i) {
		string name, ip;
		cin >> name >> ip;
		servers[ip + ";"] = name;
	}
	for (int i = 0; i < m; ++i) {
		string command, ip;
		cin >> command >> ip;
		cout << command << " " << ip << " #" << servers[ip] << endl;
	}
	return 0;
}
