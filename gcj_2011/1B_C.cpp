/*

Google Code Jam 2011 Round 1B

Problem C. House of Kittens


問題
柱がN本ある猫屋敷がある。
柱と柱の間にM個の間仕切りを設置して部屋を作った。
それぞれの柱は異なる種類のマタタビが使ってある。
ある部屋にあるマタタビの種類が別の部屋にないと猫は機嫌を損ねる。
マタタビの種類を最大化した上で、それぞれの柱に使用する種類を求める。

*/

#include <algorithm>
#include <set>
#include <vector>
#include <iostream>

using namespace std;

typedef pair<int, int> II;
typedef vector<int> IntVec;
typedef vector<II> IIVec;
typedef set<int> IntSet;

void set_flavor(int rooms, IntSet V[], IntSet F[], IntVec &pillars, int pillar, int flavor) {
	int i;
	for (i = 0; i < rooms; ++i) {
		if (V[i].count(pillar) > 0) {
			F[i].insert(flavor);
		}
	}
	pillars[pillar] = flavor;
}

bool fill_room(int rooms, int flavors, IntSet V[], IntSet F[], IntVec C[], IntVec &pillars, int room) {
	bool result = true;
	IntSet::const_iterator it;
	for (it = V[room].begin(); it != V[room].end(); ++it) {
		int pillar = *it;
		if (pillars[pillar] > 0) {
			continue;
		}
		IntSet s;
		int i;
		for (i = 0; i < (int)C[pillar].size(); ++i) {
			s.insert(pillars[C[pillar][i]]);
		}
		for (i = 1; i <= flavors; ++i) {
			if (F[room].count(i) <= 0 && s.count(i) <= 0) {
				set_flavor(rooms, V, F, pillars, pillar, i);
				break;
			}
		}
		if (i > flavors) {
			for (i = 1; i <= flavors; ++i) {
				if (s.count(i) <= 0) {
					set_flavor(rooms, V, F, pillars, pillar, i);
					break;
				}
			}
			if (i > flavors) {
				result = false;
			}
		}
	}
	return result;
}

bool solve(int N, int M, IIVec &walls, int &flavors, IntVec &pillars) {
	IntSet V[2000];		// vertexes in a room
	IntSet F[2000];		// flavors in a room
	IntVec C[2001];		// vertex connection

	int i, j;
	for (i = 0; i < N; ++i) {
		V[0].insert(i);
	}
	int rooms = 1;

	for (i = 0; i < N; ++i) {
		C[i].push_back((i-1+N)%N);
		C[i].push_back((i+1)%N);
	}

	for (i = 0; i < (int)walls.size(); ++i) {
		int s = min(walls[i].first, walls[i].second) - 1;
		int e = max(walls[i].first, walls[i].second) - 1;
		for (j = 0; j < rooms; ++j) {
			if (V[j].count(s) > 0 && V[j].count(e) > 0) {
				break;
			}
		}
		if (j >= rooms) {
			// error
			return false;
		}
		IntSet a, b;
		a.insert(s);
		a.insert(e);
		b.insert(s);
		b.insert(e);
		bool f = false;
		IntSet::const_iterator it;
		for (it = V[j].begin(); it != V[j].end(); ++it) {
			if (!f) {
				a.insert(*it);
			} else {
				b.insert(*it);
			}
			if (*it == s || *it == e) {
				f = !f;
			}
		}
		V[j] = a;
		V[rooms++] = b;
		C[s].push_back(e);
		C[e].push_back(s);
	}

	flavors = N;
	for (i = 0; i < rooms; ++i) {
		flavors = min((int)V[i].size(), flavors);
	}

	// fill the first room
	{
		int flavor = 1;
		IntSet::const_iterator it;
		for (it = V[0].begin(); it != V[0].end(); ++it) {
			int pillar = *it;
			if (flavor <= flavors) {
				set_flavor(rooms, V, F, pillars, pillar, flavor);
			} else {
				// fill with different color
				IntSet s;
				for (i = 0; i < (int)C[pillar].size(); ++i) {
					s.insert(pillars[C[pillar][i]]);
				}
				for (i = 1; ; ++i) {
					if (s.count(i) <= 0) {
						set_flavor(rooms, V, F, pillars, pillar, i);
						break;
					}
				}
			}
			++flavor;
		}
	}

	int filled_rooms, room;
	for (filled_rooms = 1; filled_rooms < N; ++filled_rooms) {
		bool found = false;
		for (room = 0; room < rooms; ++room) {
			int c = 0;
			IntSet::const_iterator it;
			for (it = V[room].begin(); it != V[room].end(); ++it) {
				if (pillars[*it] > 0) {
					++c;
				}
			}
			if (c >= 2 && c < (int)V[room].size()) {
				found = true;
				break;
			}
		}
		if (!found) {
			break;
		}
		fill_room(rooms, flavors, V, F, C, pillars, room);
	}

	for (i = 0; i < rooms; ++i) {
		if ((int)F[i].size() < flavors) {
			return false;
		}
	}
	for (i = 0; i < N; ++i) {
		if (pillars[i] <= 0 || pillars[i] > flavors) {
			return false;
		}
	}

	return true;
}

int main()
{
	cout.precision(16);
	int T, N, M;
	cin >> T;
	int t, i;
	for (t = 0; t < T; ++t) {
		cin >> N >> M;
		IIVec walls(M);
		for (i = 0; i < M; ++i) {
			cin >> walls[i].first;
		}
		for (i = 0; i < M; ++i) {
			cin >> walls[i].second;
		}
		int flavors = 0;
		IntVec pillars(N);
		solve(N, M, walls, flavors, pillars);
		cout << "Case #" << (t+1) << ": " << flavors << endl;
		for (i = 0; i < (int)pillars.size(); ++i) {
			if (i > 0) cout << " ";
			cout << pillars[i];
		}
		cout << endl;
	}

	return 0;
}

