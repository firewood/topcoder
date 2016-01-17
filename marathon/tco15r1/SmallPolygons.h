#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <cmath>

#define MAX_COORDINATE 700

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795029
#endif

typedef long long LL;

struct UnionFind {
	std::vector<int> _parent;
	std::vector<int> _size;
	UnionFind(int size) : _parent(size, -1), _size(size, 1) { }
	void unite(int a, int b) {
		int ra = root(a), rb = root(b); if (ra == rb) { return; }
		if (_size[ra] >= _size[rb]) { _parent[rb] = ra, _size[ra] += _size[rb]; } else { _parent[ra] = rb, _size[rb] += _size[ra]; }
	}
	int root(int a) {
		int p = _parent[a];
		if (p < 0) { return a; }
		while (_parent[p] >= 0) { p = _parent[p]; }
		return _parent[a] = p;
	}
	int size(int a) { return _size[root(a)]; }
};

struct Node {
	int next;
	int previous;
};

struct Triangle;
typedef std::pair<int, int> II;
typedef std::set<int> IntSet;
typedef std::set<II> IISet;
typedef std::vector<int> IntVec;
typedef std::map<II, IntSet> IIIntSetMap;

inline II make_edge(int a, int b) {
#ifdef WIN32
	return std::make_pair(min(a, b), max(a, b));
#else
	return std::make_pair(std::min(a, b), std::max(a, b));
#endif
}

struct Triangle {
	int a;
	int b;
	int c;
	int s;

	static Triangle gen(int p, int q, int r) {
		if (p > q) {
			std::swap(p, q);
		}
		if (p > r) {
			std::swap(p, r);
		}
		if (q > r) {
			std::swap(q, r);
		}
		return{ p, q, r, 0 };
	}

	bool operator <(const Triangle &t) const {
		if (a != t.a) {
			return a < t.a;
		}
		if (b != t.b) {
			return b < t.b;
		}
		return c < t.c;
	}

	std::string toString() const {
		char w[64];
		sprintf(w, "%d %d %d", a, b, c);
		return w;
	}

	void dump() const {
		fprintf(stderr, "%d,%d,%d\n", a, b, c);
		//		std::cout << a << "," << b << "," << c << std::endl;
	}
};

typedef std::vector<Triangle> TriangleVec;
typedef std::map<Triangle, int> TriangleMap;

struct SmallPolygons {

	int MaxPolygons;
	int Np;
	std::vector<int> x;
	std::vector<int> y;
	std::vector<int> cx;
	std::vector<int> cy;
	TriangleMap t_map;
	TriangleVec t_vec;
	IIIntSetMap edge_to_triangles;
	IntVec points[40][40];
	IntVec all_points[20][20];
	IntVec core_points[20][20];
	IntVec p_triangles[1500];
	Node connection[1500];
	IntVec polygons;
	UnionFind uf;
	std::vector<int> used;

public:
	SmallPolygons() : uf(1500) { }
	void init(std::vector <int> points, int N);
	std::vector <std::string> choosePolygons(std::vector <int> points, int N);
	int area(const Triangle &t) const;
	int dist(const Triangle &t) const;
	bool intersect(int a, int b, int c, int d) const;

//private:
	void findTriangles();
	void chooseFirstPolygon(void);
	bool chooseNextVertex(void);
	void chooseRemainVertices(void);
};
