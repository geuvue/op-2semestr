#include <iostream>
#include "classes.h"
using namespace std;


Time::Time(){
    hours = 0;
    minutes = 0;
    seconds = 0;
}


Time::Time(int hours){
    if(hours >= 24){
        int days = hours / 24;
        hours -= days * 24;


    }


    this->hours = hours;
    minutes = 0;
    seconds = 0;
}


Time::Time(int hours, int minutes){
    if(minutes >= 60){
        int exceeded_hours = minutes / 60;
        minutes -= exceeded_hours * 60;


        hours += exceeded_hours;
    }


    if(hours >= 24){
        int days = hours / 24;
        hours -= days * 24;
    }




    this->hours = hours;
    this->minutes = minutes;
    seconds = 0;
}


Time::Time(int hours, int minutes, int seconds){
    if(seconds >= 60){
        int exceeded_minutes = seconds / 60;
        seconds -= exceeded_minutes * 60;


        minutes += exceeded_minutes;
    }


    if(minutes >= 60){
        int exceeded_hours = minutes / 60;
        minutes -= exceeded_hours * 60;


        hours += exceeded_hours;
    }


    if(hours >= 24){
        int days = hours / 24;
        hours -= days * 24;
    }


    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}


int Time::GetHours(){
    return this->hours;
}


int Time::GetMinutes(){
    return this->minutes;
}


int Time::GetSeconds(){
    return this->seconds;
}


void Time::TimeLeft(){
    int seconds_left = 0;
    int minutes_left = 0;
    int hours_left = 0;


    if(this->GetSeconds() > 0){
        seconds_left = 60 - this->seconds;
        minutes_left = 60 - this->minutes - 1;
        hours_left = 24 - this->hours - 1;


    } else if(this->GetMinutes() > 0){
        seconds_left = 60 - this->seconds;
        minutes_left = 60 - this->minutes;
        hours_left = 24 - this->hours - 1;


    } else{
        seconds_left = 60 - this->seconds;
        minutes_left = 60 - this->minutes;
        hours_left = 24 - this->hours;
    }


    printf("Time left until the end of the day: %d hours %d minutes %d seconds\n", hours_left, minutes_left, seconds_left);
}


void Time::ShowInfo(){
    printf("Hours: %d, minutes: %d, seconds: %d\n", this->GetHours(), this->GetMinutes(), this->GetSeconds());
}


void Time::operator+=(int minutes_to_add) {
    Time *main_object = this;
    int new_minutes_value = main_object->GetMinutes() + minutes_to_add;


    int main_hours = main_object->GetHours();
    int main_minutes = new_minutes_value;
    int main_seconds = main_object->GetSeconds();


    Time temp_object(main_hours, main_minutes, main_seconds);


    main_object->hours = temp_object.hours;
    main_object->minutes = temp_object.minutes;
}


Time Time::operator-(Time right_value) {
    Time *left_value = this;


    int left_value_seconds = left_value->GetHours() * 3600 + left_value->GetMinutes() * 60 + left_value->GetSeconds();
    int right_value_seconds = right_value.GetHours() * 3600 + right_value.GetMinutes() * 60 + right_value.GetSeconds();


    if(right_value_seconds > left_value_seconds){
        cout << "Error: right-hand side operand is greater that left-hand side operand. Returning an empty object\n";


        Time empty_time(0);
        return empty_time;
    }
    else{
        int time_difference = left_value_seconds - right_value_seconds;


        Time difference_time(0, 0, time_difference);
        return difference_time;
    }
}
