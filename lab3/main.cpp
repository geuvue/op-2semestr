#include <iostream>
#include <vector>

#include "function.h"
using namespace std;


int main() {
    // кількість кругів
    int circles_amount = GetCirclesAmount();

    // вектор з об'єктами кругів
    vector<CircleOnPlane> circles = GenerateCirlesVector(circles_amount);

    // круг, з найбільшою площею
    CircleOnPlane largest_circe = FindLargestCirce(circles);

    cout << "Information about largest circle:\n";
    // виводимо інформацію про коло з найбільшою площею
    largest_circe.DisplayInfo();

    system("pause");
}
