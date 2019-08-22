// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

vector<vector<int>> edges;
vector<LL> values;
vector<int> visited;

void dfs(int node) {
  visited[node] = 1;
  for (int next : edges[node]) {
    if (!visited[next]) {
      values[next] += values[node];
      dfs(next);
    }
  }
}

int main(int argc, char *argv[]) {
  int n, q;
  cin >> n >> q;
  edges.resize(n);
  values.resize(n);
  visited.resize(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    edges[a - 1].push_back(b - 1);
    edges[b - 1].push_back(a - 1);
  }
  for (int i = 0; i < q; ++i) {
    int p, x;
    cin >> p >> x;
    values[p - 1] += x;
  }
  dfs(0);
  for (LL v : values) {
    cout << " " << v;
  }
  cout << endl;
  return 0;
}
