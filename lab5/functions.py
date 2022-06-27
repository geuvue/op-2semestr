from classes import *
import random


def capture_n():
    n = int(input("How many 2D lines generate: "))

    return n


def capture_m():
    m = int(input("How many 3D lines generate: "))

    return m


def generate_random_2d_line():
    begin_x = random.randint(1,10)
    end_x = random.randint(1,10)
    begin_y = random.randint(1,10)
    end_y = random.randint(1,10)

    line = LineOnPlane(begin_x, begin_y, end_x, end_y)

    return line


def generate_2d_lines(n: int):
    lines = []

    for i in range(n):
        line = generate_random_2d_line()
        lines.append(line)

    return lines


def generate_random_3d_line():
    begin_x = random.randint(1, 10)
    end_x = random.randint(1, 10)
    begin_y = random.randint(1, 10)
    end_y = random.randint(1, 10)
    begin_z = random.randint(1, 10)
    end_z = random.randint(1, 10)

    line = LineInSpace(begin_x, begin_y, begin_z, end_x, end_y, end_z)

    return line


def generate_3d_lines(m: int):
    lines = []

    for i in range(m):
        line = generate_random_3d_line()

        lines.append(line)

    return lines


def capture_point():
    x = int(input("Enter point's x:"))
    y = int(input("Enter point's y:"))

    point = Point2D(x,y)

    return point


def perpendicular_lines(lines_2d: list[LineOnPlane]):
    first_line = lines_2d[0]
    perpendicular_lines = []

    for i in range(len(lines_2d)):
        line = lines_2d[1]
        if first_line.is_perpendicular(line):
            perpendicular_lines.append(line)

    return perpendicular_lines


def check_if_2dlines_contains_point(lines_2d: list[LineOnPlane], point: Point2D):
    if len(lines_2d) == 0:
        print("There's no perpendicular lines to the first 2D line")
    else:
        for i in range(len(lines_2d)):
            line = lines_2d[i]
            if line.is_belongs(point):
                print(f"2D line: {line.get_info()} contains point: {point.get_x()}:{point.get_y()}")
            else:
                print(f"2D line: {line.get_info()} doesn't contain point: {point.get_x()}:{point.get_y()}")


def check_if_3Dlines_contains_others(lines_3d: list[LineInSpace]):
    for i in range(len(lines_3d)):
        for j in range(i+1, len(lines_3d)):
            line1 = lines_3d[i]
            line2 = lines_3d[j]

            if line1.is_perpendicular(line2):
                print(f"3D Line ({line1.get_info()}) is perpendicular to this line: ({line2.get_info()})")
            else:
                print(f"3D Line ({line1.get_info()}) isn't perpendicular to this line: ({line2.get_info()})")
