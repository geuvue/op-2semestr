
#include "vector"
#include "classes.h"
using namespace std;


int capture_n();
int capture_m();
vector<LineOnPlane> generate_2d_lines(int n);
vector<LineInSpace> generate_3d_lines(int m);
Point2D capture_point();
vector<LineOnPlane> perpendicular_lines(vector<LineOnPlane> lines_2d);
void check_if_2dlines_contains_point(vector<LineOnPlane> lines_2d, Point2D point);
void check_if_3Dlines_contains_others(vector<LineInSpace> lines_3d);
