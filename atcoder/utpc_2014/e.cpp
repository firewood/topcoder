// E.
 
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstring>
 
using namespace std;
 
typedef long long LL;
 
LL Max = 0;
 
struct D;
typedef vector<D*> DPVec;
 
struct D {
	D *parent;
	D *d[10];
	LL v;
	LL cm;
	D(D *_parent) {
		parent = _parent;
		memset(d, 0, sizeof(d));
		v = 0;
		cm = 0;
	}
};
 
void add(D &parent) {
	LL cm = 0;
	for (LL i = 0; i < 10; ++i) {
		D *child = parent.d[i];
		if (child) {
			cm = max(cm, child->v + child->cm);
		}
	}
	parent.cm = cm;
	Max = max(Max, parent.v + parent.cm);
	if (parent.parent) {
		add(*parent.parent);
	}
}
 
void alloc(D &parent, const char *digit, LL value) {
	LL c = *digit++;
	if (c == 0) {
		parent.v += value;
		add(parent);
		return;
	}
	c -= '0';
	D *&next = parent.d[c];
	if (next == NULL) {
		next = new D(&parent);
	}
	alloc(*next, digit, value);
}
 
int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	LL N = atoi(s.c_str());
	D root(NULL);
	for (LL i = 0; i < N; ++i) {
		getline(cin, s);
		stringstream ss(s);
		string a;
		LL b;
		ss >> a >> b;
		reverse(a.begin(), a.end());
		alloc(root, a.c_str(), b);
		cout << Max << endl;
	}
	return 0;
}
