#include "classes.h"
#include <iostream>


float LineOnPlane::get_begin_x() const {
    return begin_x;
}


float LineOnPlane::get_begin_y() const {
    return begin_y;
}


float LineOnPlane::get_end_x() const {
    return end_x;
}


float LineOnPlane::get_end_y() const {
    return end_y;
}




bool LineOnPlane::is_parallel(const LineOnPlane& line) const {
    if(begin_x - end_x != 0 && line.get_begin_x() - line.get_end_x() != 0) {
        float main_angular_coefficient = (begin_y - end_y) / (begin_x - end_x);
        float line_angular_coefficient = (line.get_begin_y() - line.get_end_y()) / (line.get_begin_x() - line.get_end_x());


        if (main_angular_coefficient == line_angular_coefficient)
            return true;
        else return false;
    }
    else return false;
}


bool LineOnPlane::is_perpendicular(const LineOnPlane& line) const {
    if(begin_x - end_x != 0 && line.get_begin_x() - line.get_end_x() != 0){
        double main_angular_coefficient = (begin_y - end_y) / (begin_x - end_x);
        double line_angular_coefficient = (line.get_begin_y() - line.get_end_y()) / (line.get_begin_x() - line.get_end_x());


        double multiply = main_angular_coefficient * line_angular_coefficient;


        if (multiply == -1)
            return true;
        else return false;
    }
    else return false;
}


bool LineOnPlane::is_belongs(Point2D point) const {
    if(end_x - begin_x != 0 && end_y - begin_y != 0) {
        float is_x = (point.get_x() - begin_x) / (end_x - begin_x);
        float is_y = (point.get_y() - begin_y) / (end_y - begin_y);


        if (is_x == is_y)
            return true;
        else return false;
    }
    else return false;
}


LineOnPlane::LineOnPlane(float begin_x, float begin_y, float end_x, float end_y) {
    this->begin_x = begin_x;
    this->begin_y = begin_y;
    this->end_x = end_x;
    this->end_y = end_y;
}


string LineOnPlane::get_info() {
    return "Begin x:" + to_string(int(begin_x)) + " begin y:" + to_string(int(begin_y)) + " end x:" + to_string(int(end_x)) + " end y:" +
           to_string(int(end_y));
}




LineInSpace::LineInSpace(float begin_x, float begin_y, float begin_z, float end_x, float end_y, float end_z){
    this->begin_x = begin_x;
    this->begin_y = begin_y;
    this->end_x = end_x;
    this->end_y = end_y;
    this->begin_z = begin_z;
    this->end_z = end_z;
}


float LineInSpace::get_begin_x() const {
    return begin_x;
}


float LineInSpace::get_begin_y() const {
    return begin_y;
}


float LineInSpace::get_end_x() const {
    return end_x;
}


float LineInSpace::get_end_y() const {
    return end_y;
}


float LineInSpace::get_begin_z() const {
    return begin_z;
}


float LineInSpace::get_end_z() const {
    return end_z;
}


Vector3D LineInSpace::convert_to_vector() const {
    float x = end_x - begin_x;
    float y = end_y - begin_y;
    float z = end_z - begin_z;


    Vector3D vector(x,y,z);


    return vector;
}


bool LineInSpace::is_parallel(LineInSpace line) const {
    Vector3D main_vector = this->convert_to_vector();
    Vector3D line_vector = line.convert_to_vector();


    float scalar_multiply = main_vector * line_vector;


    if(scalar_multiply == 0)
        return true;
    else return false;
}


bool LineInSpace::is_perpendicular(LineInSpace line) const {
    Vector3D main_vector = this->convert_to_vector();
    Vector3D line_vector = line.convert_to_vector();


    if(line_vector.get_x() != 0 && line_vector.get_y() != 0 && line_vector.get_z() != 0) {
        float x_ratio = main_vector.get_x() / line_vector.get_x();
        float y_ratio = main_vector.get_y() / line_vector.get_y();
        float z_ratio = main_vector.get_z() / line_vector.get_z();


        if (x_ratio == y_ratio && x_ratio == z_ratio && y_ratio == y_ratio)
            return true;
        else return false;
    }
    else return false;
}


bool LineInSpace::is_belongs(float x, float y, float z) const {
    if(end_x - begin_x != 0 && end_y - begin_y != 0 && end_z - begin_z != 0) {
        float is_x = (x - begin_x) / (end_x - begin_x);
        float is_y = (y - begin_y) / (end_y - begin_y);
        float is_z = (z - begin_z) / (end_z - begin_z);


        if (is_x == is_y && is_x == is_z && is_y == is_z)
            return true;
        else return false;
    }
    else return false;
}


string LineInSpace::get_info() {
    return "Begin x:"  + to_string(int(begin_x)) + " begin y:"  + to_string(int(begin_y)) + " begin z:"  + to_string(int(begin_z)) + " end x:" + to_string(int(end_x)) + " end y:" + to_string(int(end_y)) + " end z:" + to_string(int(end_z));
}




Vector3D::Vector3D(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}


float Vector3D::get_x() const {
    return x;
}


float Vector3D::get_y() const {
    return y;
}


float Vector3D::get_z() const {
    return z;
}


float operator*(Vector3D vec1, Vector3D vec2) {
    float multiply = vec1.get_x() * vec2.get_x() + vec1.get_y() * vec2.get_y() + vec1.get_z() * vec2.get_z();


    return multiply;
}




Point2D::Point2D(float x, float y) {
    this->x = x;
    this->y = y;
}


float Point2D::get_x() const {
    return x;
}


float Point2D::get_y() const {
    return y;
}
