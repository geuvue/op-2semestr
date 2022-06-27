#include "functions.h"


void test_getters(Time T3){
    cout << "\nTesting getters (T3):\n";
    printf("%d:%d:%d", T3.GetHours(), T3.GetMinutes(), T3.GetSeconds());
}


void test_t1_increment(Time &T1){
    printf("\n\nT1 before incrementing:\n");
    T1.ShowInfo();
    printf("T1 after incrementing:\n");
    T1 += 17;
    T1.ShowInfo();
}


void test_t2_increment(Time &T2){
    printf("\nT2 before incrementing:\n");
    T2.ShowInfo();
    printf("T2 after incrementing:\n");
    T2 += 34;
    T2.ShowInfo();
}


void test_time_difference(Time T1, Time T2){
    printf("\nTime differece between T2 and T1:\n");
    Time T4 = T2 - T1;
    T4.ShowInfo();
}


void test_time_left(Time T3){
    printf("\nTime left until the end of the day (T3):\n");
    T3.TimeLeft();
}
