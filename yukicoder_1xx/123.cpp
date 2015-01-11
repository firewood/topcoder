#include <iostream>
#include <algorithm>
#include <sstream>
#include <list>

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
	list<int> l;
	for (int i = 0; i < N; ++i) {
		l.push_back(i + 1);
	}
	{
		getline(cin, s);
		stringstream ss(s);
		for (int i = 0; i < M; ++i) {
			int pos;
			ss >> pos;
			list<int>::iterator it = l.begin();
			for (int j = 1; j < pos; ++j) {
				++it;
			}
			int a = *it;
			l.erase(it);
			l.push_front(a);
		}
		cout << l.front() << endl;
	}
	return 0;
}
