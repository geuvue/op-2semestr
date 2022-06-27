from functions import *

n = capture_n()
m = capture_m()

lines_2d = generate_2d_lines(n)
lines_3d = generate_3d_lines(m)

point = capture_point()

perpendicular_line = perpendicular_lines(lines_2d)
check_if_2dlines_contains_point(perpendicular_line, point)

check_if_3Dlines_contains_others(lines_3d)