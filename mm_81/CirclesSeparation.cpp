
#include <algorithm>
#include <numeric>
#include "CirclesSeparation.h"

using namespace std;

bool CirclesSeparation::intersect_gr(double x, double y, double r) {
	int grdidx_xs = max(0, (int)((x-r)*(1/PITCH)) + GRIDS/2);
	int grdidx_xe = min(GRIDS-1, (int)((x+r)*(1/PITCH)) + GRIDS/2);
	int grdidx_ys = max(0, (int)((y-r)*(1/PITCH)) + GRIDS/2);
	int grdidx_ye = min(GRIDS-1, (int)((y+r)*(1/PITCH)) + GRIDS/2);
	int xi, yi;
	for (yi = grdidx_ys; yi <= grdidx_ye; ++yi) {
		for (xi = grdidx_xs; xi <= grdidx_xe; ++xi) {
			IntSet::const_iterator it;
			for (it = _gr[yi][xi].begin(); it != _gr[yi][xi].end(); ++it) {
				double dx = _x[*it] - x;
				double dy = _y[*it] - y;
				double d = _r[*it] + r;
				if ((dx*dx+dy*dy) <= d*d) {
					return true;
				}
			}
		}
	}
	return false;
}

bool CirclesSeparation::intersect_gr_wo_i(int i, double x, double y, double r) {
	int grdidx_xs = max(0, (int)((x-r)*(1/PITCH)) + GRIDS/2);
	int grdidx_xe = min(GRIDS-1, (int)((x+r)*(1/PITCH)) + GRIDS/2);
	int grdidx_ys = max(0, (int)((y-r)*(1/PITCH)) + GRIDS/2);
	int grdidx_ye = min(GRIDS-1, (int)((y+r)*(1/PITCH)) + GRIDS/2);
	int xi, yi;
	for (yi = grdidx_ys; yi <= grdidx_ye; ++yi) {
		for (xi = grdidx_xs; xi <= grdidx_xe; ++xi) {
			IntSet::const_iterator it;
			for (it = _gr[yi][xi].begin(); it != _gr[yi][xi].end(); ++it) {
				if (i != *it) {
					double dx = _x[*it] - x;
					double dy = _y[*it] - y;
					double d = _r[*it] + r;
					if ((dx*dx+dy*dy) <= d*d) {
						return true;
					}
				}
			}
		}
	}
	return false;
}

double CirclesSeparation::get_closest_dist(double x, double y, double r) {
	double m = 10000;
	int grdidx_xs = max(0, (int)((x-r)*(1/PITCH)) + GRIDS/2);
	int grdidx_xe = min(GRIDS-1, (int)((x+r)*(1/PITCH)) + GRIDS/2);
	int grdidx_ys = max(0, (int)((y-r)*(1/PITCH)) + GRIDS/2);
	int grdidx_ye = min(GRIDS-1, (int)((y+r)*(1/PITCH)) + GRIDS/2);
	int xi, yi;
	for (yi = grdidx_ys; yi <= grdidx_ye; ++yi) {
		for (xi = grdidx_xs; xi <= grdidx_xe; ++xi) {
			IntSet::const_iterator it;
			for (it = _gr[yi][xi].begin(); it != _gr[yi][xi].end(); ++it) {
				double dx = _x[*it] - x;
				double dy = _y[*it] - y;
				double d = _r[*it] + r;
				double ev = (dx*dx+dy*dy) - d*d;
				m = min(m, ev);
			}
		}
	}
	return m;
}

void CirclesSeparation::clear_grid(void) {
	for (int i = 0; i < GRIDS; ++i) {
		for (int j = 0; j < GRIDS; ++j) {
			_gr[i][j].clear();
		}
	}
}

void CirclesSeparation::add_to_grid(int i, double x, double y) {
	double r = _r[i];
	int grdidx_xs = max(0, (int)((x-r)*(1/PITCH)) + GRIDS/2);
	int grdidx_xe = min(GRIDS-1, (int)((x+r)*(1/PITCH)) + GRIDS/2);
	int grdidx_ys = max(0, (int)((y-r)*(1/PITCH)) + GRIDS/2);
	int grdidx_ye = min(GRIDS-1, (int)((y+r)*(1/PITCH)) + GRIDS/2);
	int xi, yi;
	for (yi = grdidx_ys; yi <= grdidx_ye; ++yi) {
		for (xi = grdidx_xs; xi <= grdidx_xe; ++xi) {
			_gr[yi][xi].insert(i);
		}
	}
}

void CirclesSeparation::remove_from_grid(int i, double x, double y) {
	double r = _r[i];
	int grdidx_xs = max(0, (int)((x-r)*(1/PITCH)) + GRIDS/2);
	int grdidx_xe = min(GRIDS-1, (int)((x+r)*(1/PITCH)) + GRIDS/2);
	int grdidx_ys = max(0, (int)((y-r)*(1/PITCH)) + GRIDS/2);
	int grdidx_ye = min(GRIDS-1, (int)((y+r)*(1/PITCH)) + GRIDS/2);
	int xi, yi;
	for (yi = grdidx_ys; yi <= grdidx_ye; ++yi) {
		for (xi = grdidx_xs; xi <= grdidx_xe; ++xi) {
			_gr[yi][xi].erase(i);
		}
	}
}

void CirclesSeparation::refresh_grid() {
	clear_grid();
	for (int i = 0; i < _N; ++i) {
		add_to_grid(i, _x[i], _y[i]);
	}
}

void CirclesSeparation::initialize(DblVec &x, DblVec &y, DblVec r, DblVec m) {
	_N = (int)x.size();
	double minx = 10000, maxx = -10000, miny = 10000, maxy = -10000;
	int i;
	for (i = 0; i < _N; ++i) {
		minx = min(minx, x[i]);
		maxx = max(maxx, x[i]);
		miny = min(miny, y[i]);
		maxy = max(maxy, y[i]);
	}
	_cenx = (minx+maxx) * 0.5;
	_ceny = (miny+maxy) * 0.5;
	for (i = 0; i < _N; ++i) {
		x[i] -= _cenx, y[i] -= _ceny;
	}
	_x = x, _y = y, _r = r, _m = m, _ox = x, _oy = y;
}

IntVec CirclesSeparation::gen_process_order_1(void) {
	DIVec v;
	int i;
	for (i = 0; i < _N; ++i) {
		double ev = _m[i];
		v.push_back(DI(-ev, i));
	}
	sort(v.begin(), v.end());
	IntVec order(_N);
	for (i = 0; i < _N; ++i) {
		order[i] = v[i].second;
	}
	return order;
}

IntVec CirclesSeparation::get_display_order(IntVec process_order) {
	IntVec order(_N);
	for (int i = 0; i < _N; ++i) {
		order[process_order[i]] = i;
	}
	return order;
}

double CirclesSeparation::evaluate(DblVec &x, DblVec &y, DIVec &ev) {
	double score = 0;
	ev.resize(_N);
	for (int i = 0; i < _N; ++i) {
		double dx = x[i] - _ox[i];
		double dy = y[i] - _oy[i];
		double s = sqrt(dx*dx+dy*dy) * _m[i];
		score += s;
		ev[i].first = s;
		ev[i].second = i;
	}
	sort(ev.rbegin(), ev.rend());
	return score;
}

DblVec CirclesSeparation::build_answer(DblVec &x, DblVec &y) {
	DblVec ans(_N*2);
	for (int i = 0; i < _N; ++i) {
		x[i] += _cenx, y[i] += _ceny;
		ans[i*2] = x[i], ans[i*2+1] = y[i];
	}
	return ans;
}

void CirclesSeparation::place_1(IntVec order) {
	clear_grid();
	int i = order[0];
	add_to_grid(i, _x[i], _y[i]);
	for (int k = 1; k < _N; ++k) {
		int i = order[k];
		double bestx = _ox[i], besty = _oy[i], r = _r[i];
		double best_s = INF;
		double rad = atan2(besty, bestx);
		double d;
		int bc = 0;
		double init_d = sqrt(bestx*bestx+besty*besty)*0.4/r;
		for (d = init_d; bc < 5; d += 0.1) {
			bool f = false;
			int deg, dir;
			int max_deg = k < (_N/2) ? 16 : 25;
			int deg_step = k < (_N/2) ? 2 : 4;
			for (deg = 0; !f && deg <= max_deg; deg += deg_step) {
				for (dir = -1; !f && dir <= 1; dir += 2) {
					double delta = (double)(deg * dir) * (M_PI/180.0);
					double x = cos(rad + delta) * r * d;
					double y = sin(rad + delta) * r * d;
					if (!intersect_gr(x, y, r)) {
						f = true;
						double dx = x - _ox[i];
						double dy = y - _oy[i];
						double s = dx*dx+dy*dy;
						if (s < best_s) {
							best_s = s;
							bestx = x, besty = y;
							bc = 0;
						}
					}
				}
			}
			bc += f;
		}
		_x[i] = bestx, _y[i] = besty;
		add_to_grid(i, bestx, besty);
	}
}

void CirclesSeparation::move_1(IntVec &order, DblVec &xv, DblVec &yv) {
	for (int k = _N-1; k >= 0; --k) {
		int i = order[k];

		double diffx = _x[i] - _ox[i], diffy = _y[i] - _oy[i];
		double best = diffx*diffx + diffy*diffy;
		if (best < 0.01) {
			continue;
		}
		double r = _r[i];
		double sx = _ox[i] - (diffx>0?r:-r) * 3;
		double ex = _x[i] + (diffx>0?r:-r) * 3;
		double sy = _oy[i] - (diffy>0?r:-r) * 3;
		double ey = _y[i] + (diffy>0?r:-r) * 3;
		double rx = ex - sx;
		double ry = ey - sy;
		if (fabs(rx) < 0.01 && fabs(ry) < 0.01) {
			continue;
		}
		int steps = 250;
		double stepx = rx / (double)steps;
		double stepy = ry / (double)steps;
		double y = sy;
		bool updated = false;
		double bestx, besty;
		int a, b;
		for (a = 0; a < steps; ++a, y += stepy) {
			double x = sx;
			for (b = 0; b < steps; ++b, x += stepx) {
				if (!intersect_gr_wo_i(i, x, y, r)) {
					double diffx = _ox[i] - x, diffy = _oy[i] - y;
					double ev = diffx*diffx + diffy*diffy;
					if (ev < best) {
						updated = true;
						best = ev;
						bestx = x;
						besty = y;
					}
				}
			}
		}
		if (updated) {
			remove_from_grid(i, _x[i], _y[i]);
			_x[i] = bestx;
			_y[i] = besty;
			add_to_grid(i, bestx, besty);
		}
	}
	xv = _x, yv = _y;
}

DblVec CirclesSeparation::minimumWork(DblVec x, DblVec y, DblVec r, DblVec m) {
	initialize(x, y, r, m);
	IntVec process_order = gen_process_order_1();
	place_1(process_order);
	int loops = 5;
	for (int l = 0; l < loops; ++l) {
		move_1(process_order, x, y);
	}
	return build_answer(x, y);
}

