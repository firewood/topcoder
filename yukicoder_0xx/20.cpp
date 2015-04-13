#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>

using namespace std;

int N, V, Ox, Oy;
int L[256][256];
int visited[256][256];

int dfs(int x, int y, int v) {
  visited[y][x] = v;
  if (x == N-1 && y == N-1) {
    return 1;
  }
  const int dx[] = {-1,1,0,0};
  const int dy[] = {0,0,-1,1};
  for (int d = 0; d < 4; ++d) {
    int nx = x + dx[d], ny = y + dy[d];
    if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
      int r = v - L[ny][nx];
      if (r > visited[ny][nx]) {
        if (dfs(nx, ny, r)) {
          return 1;
        }
      }
    }
  }
  return 0;
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
  stringstream ss(s);
  ss >> N >> V >> Ox >> Oy;
  --Ox, --Oy;
  for (int i = 0; i < N; ++i) {
    getline(cin, s);
    stringstream ss(s);
    for (int j = 0; j < N; ++j) {
      ss >> L[i][j];
    }
  }
  int possible = dfs(0, 0, V);
  if (!possible) {
    int r = visited[Oy][Ox];
    if (!(Ox == 0 && Oy == 0) && r > 0) {
      memset(visited, 0, sizeof(visited));
      possible = dfs(Ox, Oy, r * 2);
    }
  }
  cout << (possible ? "YES" : "NO") << endl;
	return 0;
}
