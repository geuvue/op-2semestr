from abc import ABC, abstractmethod


class TLine(ABC):
    @abstractmethod
    def get_begin_x(self):
        pass

    @abstractmethod
    def get_begin_y(self):
        pass

    @abstractmethod
    def get_end_x(self):
        pass

    @abstractmethod
    def get_end_y(self):
        pass


class Point2D:
    def __init__(self, x, y):
        self.__x = x
        self.__y = y

    def get_x(self):
        return self.__x

    def get_y(self):
        return self.__y


class LineOnPlane(TLine):
    def __init__(self, begin_x, begin_y, end_x, end_y):
        self.__begin_x = begin_x
        self.__begin_y = begin_y
        self.__end_x = end_x
        self.__end_y = end_y

    def get_begin_x(self):
        return self.__begin_x

    def get_begin_y(self):
        return self.__begin_y

    def get_end_x(self):
        return self.__end_x

    def get_end_y(self):
        return self.__end_y

    def is_parallel(self, line):
        if self.__begin_x - self.__end_x != 0 and line.get_begin_x() - line.get_end_y() != 0:
            main_angular_coefficient = (self.__begin_y - self.__end_y) / (self.__begin_x - self.__end_x)
            line_angular_coefficient = (line.get_begin_y() - line.get_end_y) / (line.get_begin_x() - line.get_end_y())

            if main_angular_coefficient == line_angular_coefficient:
                return True
            else:
                return False
        else:
            return False

    def is_perpendicular(self, line):
        if self.__begin_x - self.__end_x != 0 and line.get_begin_x() - line.get_end_y() != 0:
            main_angular_coefficient = (self.__begin_y - self.__end_y) / (self.__begin_x - self.__end_x)
            line_angular_coefficient = (line.get_begin_y() - line.get_end_y()) / (line.get_begin_x() - line.get_end_y())

            multiply = main_angular_coefficient * line_angular_coefficient

            if multiply == -1:
                return True
            else:
                return False
        else:
            return False

    def is_belongs(self, point: Point2D):
        if self.__end_x - self.__begin_x != 0 and self.__end_y - self.__begin_y != 0:
            is_x = (point.get_x() - self.__begin_x) / (self.__end_x - self.__begin_x)
            is_y = (point.get_y() - self.__begin_y) / (self.__end_y - self.__begin_y)

            if is_x == is_y:
                return True
            else:
                return False
        else:
            return False

    def get_info(self):
        return f"Begin x:{self.__begin_x}, begin y:{self.__begin_y}, end x:{self.__end_x}, end y:{self.__end_y}"


class Vector3D:
    def __init__(self, x, y, z):
        self.__x = x
        self.__y = y
        self.__z = z

    def get_x(self):
        return self.__x

    def get_y(self):
        return self.__y

    def get_z(self):
        return self.__z

    def __mul__(self, other):
        multiply = self.get_x() * other.get_x() + self.get_y() * other.get_y() + self.get_z() * other.get_z()

        return multiply


class LineInSpace(TLine):
    def __init__(self, begin_x, begin_y, begin_z, end_x, end_y, end_z):
        self.__begin_x = begin_x
        self.__begin_y = begin_y
        self.__begin_z = begin_z
        self.__end_x = end_x
        self.__end_y = end_y
        self.__end_z = end_z

    def get_begin_x(self):
        return self.__begin_x

    def get_begin_y(self):
        return self.__begin_y

    def get_begin_z(self):
        return self.__begin_z

    def get_end_x(self):
        return self.__end_x

    def get_end_y(self):
        return self.__end_y

    def get_end_z(self):
        return self.__end_z

    def convert_to_vector(self):
        x = self.__end_x - self.__begin_x
        y = self.__end_y - self.__begin_y
        z = self.__end_z - self.__begin_z

        vector = Vector3D(x, y, z)

        return vector

    def is_parallel(self, line):
        main_vector = self.convert_to_vector()
        line_vector = line.convert_to_vector()

        scalar_multiply = main_vector * line_vector

        if scalar_multiply == 0:
            return True
        else:
            return False

    def is_perpendicular(self, line):
        main_vector = self.convert_to_vector()
        line_vector = line.convert_to_vector()

        if line_vector.get_x() != 0 and line_vector.get_y() != 0 and line_vector.get_z() != 0:
            x_ratio = main_vector.get_x() / line_vector.get_x()
            y_ratio = main_vector.get_y() / line_vector.get_y()
            z_ratio = main_vector.get_z() / line_vector.get_z()

            if x_ratio == y_ratio and x_ratio == z_ratio and y_ratio == y_ratio:
                return True
            else:
                return False
        else:
            return False

    def is_belongs(self, x, y, z):
        if self.__end_x - self.__begin_x != 0 and self.__end_y - self.__begin_y != 0 and self.__end_z - self.__begin_z != 0:
            is_x = (x - self.__begin_x) / (self.__end_x - self.__begin_x)
            is_y = (y - self.__begin_y) / (self.__end_y - self.__begin_y)
            is_z = (z - self.__begin_z) / (self.__end_z - self.__begin_z)

            if is_x == is_y and is_x == is_z and is_y == is_z:
                return True
            else:
                return False
        else:
            return False

    def get_info(self):
        return f"Begin x:{self.__begin_x}, begin y:{self.__begin_y}, begin z: {self.__begin_z}, end x:{self.__end_x}, end y:{self.__end_y}, end z:{self.__end_z}"
