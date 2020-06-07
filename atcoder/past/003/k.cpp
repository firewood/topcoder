// K.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;

struct Node {
	int i;
	Node *prev;
	Node *next;
};

int main() {
	int n, q, f, t, x;
	cin >> n >> q;
	vector<Node*> tail(n);
	vector<Node> p(n);
	for (int i = 0; i < n; ++i) {
		p[i].i = i;
		tail[i] = &(p[i]);
		p[0].prev = 0;
		p[0].next = 0;
	}
	for (int w = 0; w < q; ++w) {
		cin >> f >> t >> x;
		--f, --t, --x;
		Node* prev = p[x].prev;
		p[x].prev = tail[t];
		tail[t] = tail[f];
		tail[f] = prev;
	}
	vector<int> pos(n);
	for (int i = 0; i < n; ++i) {
		for (Node* t = tail[i]; t != 0; t = t->prev) {
			pos[t->i] = i;
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << pos[i] + 1 << endl;
	}
	return 0;
}
