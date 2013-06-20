
#pragma once

#include <cmath>
#include <set>
#include <vector>

using namespace std;

typedef pair<double, int> DI;
typedef vector<int> IntVec;
typedef vector<double> DblVec;
typedef vector<DI> DIVec;
typedef set<int> IntSet;

#define INF 1.0e+12
#define EPS 1.0e-9
#define CENTER 0.5
#define PITCH 0.1
#define GRIDS 50

class CirclesSeparation {
	int _N;
	DblVec _ox;
	DblVec _oy;
	DblVec _x;
	DblVec _y;
	DblVec _r;
	DblVec _m;
	IntSet _gr[GRIDS][GRIDS];
	double _cenx;
	double _ceny;

	bool intersect_gr(double x, double y, double r);
	bool intersect_gr_wo_i(int i, double x, double y, double r);
	double get_closest_dist(double x, double y, double r);
	void clear_grid(void);
	void add_to_grid(int i, double x, double y);
	void remove_from_grid(int i, double x, double y);
	void refresh_grid();

public:
	void initialize(DblVec &x, DblVec &y, DblVec r, DblVec m);
	IntVec gen_process_order_1(void);
	IntVec get_display_order(IntVec process_order);
	double evaluate(DblVec &x, DblVec &y, DIVec &ev);
	DblVec build_answer(DblVec &x, DblVec &y);
	void place_1(IntVec order);
	void move_1(IntVec &order, DblVec &xv, DblVec &yv);
	DblVec minimumWork(DblVec x, DblVec y, DblVec r, DblVec m);
};

static double random(void) {
	return (double)rand() / (double)(RAND_MAX+1);
}

