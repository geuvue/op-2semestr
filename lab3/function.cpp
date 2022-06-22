#include "function.h"

#include <iostream>
#include <vector>
using namespace std;


int GetCirclesAmount(){
    int amount = 0;

    cout << "Enter cirles amount: ";
    cin >> amount;

    return amount;
}

CircleOnPlane GenerateCircle(int i){
    float radius = 0;
    cout << "Enter a radius of circle #" << i+1 << ": ";
    cin >> radius;

    int x = 0;
    cout << "Enter x coordinate of circle #" << i+1 << ": ";
    cin >> x;

    int y = 0;
    cout << "Enter y coordinate of circle #" << i+1 << ": ";
    cin >> y;

    CircleOnPlane circle(radius, x, y);

    return circle;
}

vector<CircleOnPlane> GenerateCirlesVector(int circles_amount){
    vector<CircleOnPlane> circles;

    for(int i = 0; i< circles_amount; i++){
        CircleOnPlane circle = GenerateCircle(i);

        circles.push_back(circle);
    }

    return circles;
}

CircleOnPlane FindLargestCirce(const vector<CircleOnPlane>& circles){
    // об'єкт круга
    CircleOnPlane largest_circle = circles[0];
    // площа круга
    float largest_circle_area = largest_circle.GetArea();

    for(int i = 1; i < circles.size(); i++){
        // об'єкт круга
        CircleOnPlane circle = circles[i];
        // площа круга
        float circe_area = circles[i].GetArea();

        if(circe_area > largest_circle_area){
            largest_circle = circle;
            largest_circle_area = circe_area;
        }
    }

    return largest_circle;
}
