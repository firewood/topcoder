// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;

struct Edge {
  int node;
  LL dist;
};

struct Node {
  LL value;
  vector <Edge> edges;
  bool vis;
};

vector<Node> nodes;

bool check(int n, LL value) {
  if (nodes[n].vis) {
    return nodes[n].value == value;
  }
  nodes[n].value = value;
  nodes[n].vis = true;
  for (Edge &edge : nodes[n].edges) {
    if (!check(edge.node, value + edge.dist)) {
      return false;
    }
  }
  return true;
}

int main(int argc, char *argv[])
{
  int n, m;
  cin >> n >> m;
  nodes.resize(n);
  for (int i = 0; i < m; ++i) {
    int l, r;
    LL d;
    cin >> l >> r >> d;
    --l, --r;
    nodes[l].edges.push_back({r, d});
    nodes[r].edges.push_back({l, -d});
  }
  bool ans = true;
  for (int i = 0; i < n; ++i) {
    if (!nodes[i].vis && !check(i, 0)) {
      ans = false;
    }
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
