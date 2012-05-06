/*

Google Code Jam 2011 Round 1B

Problem C. House of Kittens


Problem

You have recently adopted some kittens, and now you want to make a house for them.
On the outside, the house will be shaped like a convex polygon with N vertices.
On the inside, it will be divided into several rooms by M interior walls
connecting vertices along straight lines. No two walls will ever cross, but
there might be multiple walls touching a single vertex.

So why is your house of kittens going to be so special? At every vertex, you are
going to build a pillar entirely out of catnip! Kittens will be able to play with
any pillar that touches the room they are in, giving them a true luxury home.

To make the house even more exciting, you want to use different flavors of catnip.
A single pillar can only use one flavor, but different pillars can use different
flavors. There is only one problem. If some room does not have access to all the
catnip flavors in the house, then the kittens in that room will feel left out
and be sad.

Your task is to choose what flavor of catnip to use for each vertex in such a way
that (a) every flavor is accessible from every room, and (b) as many flavors as
possible are used.

In the following example, three different flavors (represented by red, green,
and blue dots) are distributed across an 8-sided house while keeping the kittens
in every room happy:


In the image above, starting at the left corner of the top wall and going
clockwise, the colors here are: green, blue, red, red, blue, green, blue, red.


Input

The first line of the input gives the number of test cases, T. T test cases follow.

Each test case consists of three lines. The first line gives N and M, the number of
vertices and interior walls in your cat house. The second lines gives space-separated
integers U1, U2, ..., UM describing where each interior wall begins. The third lines
gives space-separated integers V1, V2, ..., VM describing where each interior wall ends.

More precisely, if the vertices of your cat house are labeled 1, 2, ..., N in clockwise
order, then the interior walls are between vertices U1 and V1, U2 and V2, etc.


Output

For each test case, output two lines. The first should be "Case #x: C", where x is
the case number, and C is the maximum number of catnip flavors that can be used.
The second line should contain N space-separated integers: "y1 y2 ... yN", where yi is
an integer between 1 and C indicating which catnip flavor you assigned to vertex i.

If there are multiple assignments with C flavors, you may output any of them.


Limits

1 <= T <= 100.
1 <= M <= N - 3.
1 <= Ui < Vi <= N for all i.
Interior walls do not touch each other except at the N vertices.
Interior walls do not touch the outside of the house except at the N vertices.
Small dataset

4 <= N <= 8.

Large dataset

4 <= N <= 2000.


Sample


Input

2
4 1
2
4
8 3
1 1 4
3 7 7


Output

Case #1: 3
1 2 1 3
Case #2: 3
1 2 3 1 1 3 2 3

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

