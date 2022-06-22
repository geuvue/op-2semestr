#pragma once

class CircleOnPlane{
private:
    float radius;
    int x_coordinates;
    int y_coordinates;
public:
    CircleOnPlane(float , int, int);
    float GetArea() const;
    void DisplayInfo() const;
};
