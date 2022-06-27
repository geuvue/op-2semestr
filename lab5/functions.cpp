#include "functions.h"


int capture_n(){
    cout << "How many 2D lines generate: ";
    int n;
    cin >> n;


    return n;
}


int capture_m(){
    cout << "How many 3D lines generate: ";
    int m;
    cin >> m;


    return m;
}


LineOnPlane generate_random_2d_line(){
    float begin_x = rand() % 10 + 1;
    float end_x = rand() % 10 + 1;
    float begin_y = rand() % 10 + 1;
    float end_y = rand() % 10 + 1;


    LineOnPlane line(begin_x, begin_y, end_x, end_y);


    return line;
}


vector<LineOnPlane> generate_2d_lines(int n){
    vector<LineOnPlane> vec;


    for (int i = 0; i < n; ++i){
        LineOnPlane line = generate_random_2d_line();


        vec.push_back(line);
    }


    return vec;
}


LineInSpace generate_random_3d_line(){
    float begin_x = rand() % 10 + 1;
    float end_x = rand() % 10 + 1;
    float begin_y = rand() % 10 + 1;
    float end_y = rand() % 10 + 1;
    float begin_z = rand() % 10 + 1;
    float end_z = rand() % 10 + 1;


    LineInSpace line(begin_x, begin_y, begin_z, end_x, end_y, end_z);


    return line;
}


vector<LineInSpace> generate_3d_lines(int m){
    vector<LineInSpace> vec;


    for (int i = 0; i < m; ++i){
        LineInSpace line = generate_random_3d_line();


        vec.push_back(line);
    }


    return vec;
}


Point2D capture_point(){
    cout << "Enter point's x:";
    float x;
    cin >> x;


    cout << "Enter point's y:";
    float y;
    cin >> y;


    Point2D point(x,y);


    return point;
}




vector<LineOnPlane> perpendicular_lines(vector<LineOnPlane> lines_2d){
    LineOnPlane first_line = lines_2d[0];
    vector<LineOnPlane> perpendicular_lines;


    for (int i = 1; i < lines_2d.size(); ++i) {
        LineOnPlane line = lines_2d[1];


        if(first_line.is_perpendicular(line))
            perpendicular_lines.push_back(line);
    }


    return perpendicular_lines;
}




void check_if_2dlines_contains_point(vector<LineOnPlane> lines_2d, Point2D point){
    if(lines_2d.empty()){
        cout << "There's no perpendicular lines to the first 2D line\n";
    }
    else{
        for (int i = 0; i < lines_2d.size(); ++i) {
            LineOnPlane line = lines_2d[i];


            if(line.is_belongs(point))
                cout << "2D line: " << line.get_info() << " contains point: " << point.get_x() << ":" << point.get_y() << endl;
            else
                cout << "2D line: " << line.get_info() << " doesn't contain point: " << point.get_x() << ":" << point.get_y() << endl;
        }
    }
}


void check_if_3Dlines_contains_others(vector<LineInSpace> lines_3d){
    for (int i = 0; i < lines_3d.size(); ++i) {
        for (int j = i + 1; j < lines_3d.size(); ++j) {
            LineInSpace line1 = lines_3d[i];
            LineInSpace line2 = lines_3d[j];


            if(line1.is_perpendicular(line2))
                printf("3D Line (%s) is perpendicular to this line: (%s)\n", line1.get_info().c_str(), line2.get_info().c_str());
            else
                printf("3D Line (%s) isn't perpendicular to this line: (%s)\n", line1.get_info().c_str(), line2.get_info().c_str());
        }
    }
}
