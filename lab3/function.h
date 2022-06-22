#pragma once

#include <iostream>
#include <vector>

#include "classes.h"
using namespace std;


int GetCirclesAmount();


CircleOnPlane GenerateCircle(int i);


vector<CircleOnPlane> GenerateCirlesVector(int circles_amount);


CircleOnPlane FindLargestCirce(const vector<CircleOnPlane>& circles);
