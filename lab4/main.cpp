#include "classes.h"
#include "functions.h"


int main() {
    Time T1(14);
    T1.ShowInfo();


    Time T2(15,45);
    T2.ShowInfo();


    Time T3(19, 24,16);
    T3.ShowInfo();


    test_getters(T3);


    test_t1_increment(T1);


    test_t2_increment(T2);


    test_time_difference(T1, T2);


    test_time_left(T3);
}
