// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

struct EERTREE {
	struct Node {
		map<char, int> link;
		int suffix_link;
		int length;
		int count;
		Node() : suffix_link(0), length(0), count(0) { }
	};
	vector<Node> c;
	string s;
	int active_index;

	Node *create_node() {
		c.emplace_back();
		return &c.back();
	}

	int find_previous_index(int id) {
		const int pos = int(s.size()) - 1;
		while (true) {
			const int opposite_index = pos - 1 - c[id].length;
			if (opposite_index >= 0 && s[opposite_index] == s.back()) {
				break;
			}
			id = c[id].suffix_link;
		}
		return id;
	}

public:
	EERTREE() {
		Node *m1 = create_node();
		m1->length = -1;
		Node *m0 = create_node();
		active_index = 0;
	}

	void add(char ch) {
		s.push_back(ch);
		const int a = find_previous_index(active_index);
		const auto inserted_result = c[a].link.insert(make_pair(ch, int(c.size())));
		active_index = inserted_result.first->second;
		if (!inserted_result.second) {
			c[active_index].count++;
			return;
		}
		Node *node = create_node();
		node->count = 1;
		node->length = c[a].length + 2;
		if (node->length == 1) {
			node->suffix_link = 1;
		} else {
			const int b = find_previous_index(c[a].suffix_link);
			node->suffix_link = c[b].link[ch];
		}
	}

	int size() const {
		return int(c.size()) - 2;
	}
};

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	n = 131072, s = string(n, 'a');

	EERTREE eertree;
	for (auto c : s) {
		eertree.add(c);
	}
	cout << eertree.size() << endl;

	return 0;
}
