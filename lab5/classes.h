

using namespace std;
#include <iostream>


class TLine{
protected:
    float begin_x;
    float begin_y;
    float end_x;
    float end_y;


public:
    virtual float get_begin_x() const = 0;
    virtual float get_begin_y() const = 0;
    virtual float get_end_x() const = 0;
    virtual float get_end_y() const = 0;
};


class Point2D{
private:
    float x;
    float y;
public:
    Point2D(float x, float y);


    float get_x() const;
    float get_y() const;
};


class LineOnPlane : public TLine{
public:
    LineOnPlane(float begin_x, float begin_y, float end_x, float end_y);


    float get_begin_x() const override;
    float get_begin_y() const override;
    float get_end_x() const override;
    float get_end_y() const override;


    bool is_parallel(const LineOnPlane& line) const;
    bool is_perpendicular(const LineOnPlane& line) const;
    bool is_belongs(Point2D point) const;


    string get_info();
};


class Vector3D{
private:
    float x;
    float y;
    float z;
public:
    Vector3D(float x, float y, float z);


    float get_x() const;
    float get_y() const;
    float get_z() const;


    friend float operator * (Vector3D vec1, Vector3D vec2);
};


class LineInSpace : public TLine{
private:
    float begin_z;
    float end_z;


public:
    LineInSpace(float begin_x, float begin_y, float begin_z, float end_x, float end_y, float end_z);


    float get_begin_x() const override;
    float get_begin_y() const override;
    float get_end_x() const override;
    float get_end_y() const override;
    float get_begin_z() const;
    float get_end_z() const;




    bool is_parallel(LineInSpace line) const;
    bool is_perpendicular(LineInSpace line) const;
    bool is_belongs(float x, float y, float z) const;


    string get_info();


    Vector3D convert_to_vector() const;
};
