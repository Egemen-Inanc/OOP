#include <iostream>
using namespace std;

class Time{

    private:
    int hour;
    int minutes;

    public:
    class Time addTime(class Time object)
    {
        Time product;
        product.hour = hour + object.hourData();
        product.minutes = minutes + object.minutesData();
        if(product.minutes>=60)
        {
            product.minutes-=60;
            product.hour+=1;
        }
        if(product.hour>=24)
        {
            product.hour-=24;
        }
        
        return product;
    }
    int& hourData();
    int& minutesData();

};

int& Time::hourData()
{
    return hour;
}
int& Time::minutesData()
{
    return minutes;
}

void initializeTime(Time& object, int hours, int minutes)
{
    if(hours<0){
        hours+=24;
    }
    if(hours>=24){
        hours-=24;
    }
    if(minutes<0){
        minutes+=60;
        hours-=1;
    }
    if(minutes>=60){
        minutes-=60;
        hours+=1;
    }

    object.hourData() = hours;
    object.minutesData() = minutes;
}


void Swap(Time& first, Time& second)
{
    Time tmp;
    tmp.hourData() = first.hourData();
    tmp.minutesData() = first.minutesData();

    first.hourData() = second.hourData();
    first.minutesData() = second.minutesData();

    second.hourData() = tmp.hourData();
    second.minutesData() = tmp.minutesData();
}

void operator++(Time& object)
{
    object.hourData()+=1;
    object.minutesData()+=1;
}

void displayTime(Time object)
{
    cout<<"time: "<<object.hourData()<<":"<<object.minutesData()<<endl;
}


int main()
{
    Time test;
    Time test2;
    Time test3;
    initializeTime(test,17,45);
    initializeTime(test2,15,15);
    displayTime(test);
    displayTime(test2);
    swap(test,test2);
    displayTime(test);
    displayTime(test2);
    ++test;
    displayTime(test);
    test3 = test.addTime(test2);
    displayTime(test3);
}