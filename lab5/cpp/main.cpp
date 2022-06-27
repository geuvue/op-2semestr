#include "vector"
#include <iostream>
#include "functions.h"
#include "ctime"




int main() {
    srand(time(nullptr));


    int n = capture_n();
    int m = capture_m();


    vector<LineOnPlane> lines_2d = generate_2d_lines(n);
    vector<LineInSpace> lines_3d = generate_3d_lines(m);


    Point2D point = capture_point();


    vector<LineOnPlane> perpendicular_line = perpendicular_lines(lines_2d);
    check_if_2dlines_contains_point(perpendicular_line, point);


    check_if_3Dlines_contains_others(lines_3d);
}
