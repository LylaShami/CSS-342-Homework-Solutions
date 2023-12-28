#include "TimeSpan.h"
#include <iostream>
#include <string>


using namespace std;


//empty constructor
TimeSpan::TimeSpan()
{
    TsHours= 0;
    TsMinutes = 0;
    TsSeconds = 0;
}
//if three values, should be equal to hours, minutes and seconds
TimeSpan::TimeSpan(double hours, double minutes, double seconds)
{
    TsHours= hours;
    TsMinutes = minutes;
    TsSeconds = seconds;
}

//if two values should be equal to minutes and seconds, hours should be zero
TimeSpan::TimeSpan(double minutes, double seconds)
{
    TsHours= 0;
    TsMinutes = minutes;
    TsSeconds = seconds;
}

//if one value, it should be equal to seconds, hours and minutes should be zero 
TimeSpan::TimeSpan(double seconds)
{
    TsHours= 0;
    TsMinutes = 0;
    TsSeconds = seconds;
}

//updates the time after timespan has been created
void TimeSpan::setTime(double hours, double minutes, double seconds)
{
    TsHours= hours;
    TsMinutes = minutes;
    TsSeconds = seconds;
}

//calculates total time duration in seconds
int TimeSpan::helperTime() const
{
    //convertng the hours to seconds and adding the minutes to remainings seconds
    return TsHours* 3600 + TsMinutes * 60 + TsSeconds;
}

//the unary negation function turns timespan negative 
TimeSpan TimeSpan::operator-() const
{
    TimeSpan temp; //creating temporary value 
    temp.TsHours= -TsHours; //turning hours negative
    temp.TsMinutes = -TsMinutes; //turning minutes negative
    temp.TsSeconds = -TsSeconds; //turning seconds negativve
    return temp; //returing the values stored
} 
//returns the hours in standard time
int TimeSpan::getHours() const
{   
    //divide the calculated seconds from helpertime to get hours
     return helperTime() / 3600;
}
//returns the minutes in standard time
int TimeSpan::getMinutes() const
{
    //using the remaining seconds and dividing by 60 to get minutes
    return (helperTime() % 3600) / 60;
}
//returns the seconds in standard time
int TimeSpan::getSeconds() const
{
    //calculating the remaining seconds after seperating the hours and minutes
    return (helperTime() % 3600) % 60;
}

//adding two timespan durations together and returning result
TimeSpan TimeSpan::operator+(const TimeSpan &other) const
{
    TimeSpan temp; //creating temporary value
    temp.TsHours= TsHours+ other.TsHours; // adding the hours
    temp.TsMinutes = TsMinutes + other.TsMinutes; //adding the minutes
    temp.TsSeconds = TsSeconds + other.TsSeconds; //adding the seconds

    if (temp.TsMinutes >= 60) //if minutes goes passed 60 
    {
        //fix the hours accordingly
        temp.TsMinutes -= 60;
        temp.TsHours+= 1;
    }
    if (temp.TsSeconds >= 60) //if seconds goes past 60
    {
        //fix the minutes accordingly
        temp.TsSeconds -= 60;
        temp.TsMinutes += 1;
    }

    return temp; //return the values stored
}

//adding to timespan 
TimeSpan &TimeSpan::operator+=(const TimeSpan &other)
{
   
    TsHours+= other.TsHours; //add hours to the timespan
    TsMinutes += other.TsMinutes; //add minutes to timespan
    TsSeconds += other.TsSeconds; //add seconds to timespan

    if (TsMinutes >= 60)     //if minutes goes passed 60
    {
        TsMinutes -= 60; // fix hours accordingly
        TsHours+= 1;
    }
    if (TsSeconds >= 60) //if seconds goes passed 60
    {
        TsSeconds -= 60; //fix minutes accordingly 
        TsMinutes += 1;
    }
    return *this; //return refrence 
}

//subtracting two timespan durations
TimeSpan TimeSpan::operator-(const TimeSpan &other) const
{
    TimeSpan temp; //create temporary value

    temp.TsHours= TsHours- other.TsHours; //subtract hours
    temp.TsMinutes = TsMinutes - other.TsMinutes; //subtract minutes
    temp.TsSeconds = TsSeconds - other.TsSeconds; //subtract seconds

    if (temp.TsMinutes < 0) //if the minutes  negative 
    {
        temp.TsMinutes += 60; //fix by taking 60 minutes from hours 
        temp.TsHours-= 1;
    }
    if (temp.TsSeconds < 0) //if seconds are negative 
    {
        temp.TsSeconds += 60; //fix by taking 60 seconds from minutes
        temp.TsMinutes -= 1;
    }

    return temp; //return the values stored
}
//subtracting to timespan 
TimeSpan &TimeSpan::operator-=(const TimeSpan &other)
{
    TsHours-= other.TsHours; //subtracting hours
    TsMinutes -= other.TsMinutes; //subtracting minutes
    TsSeconds -= other.TsSeconds; //subtracting seconds

    if (TsMinutes < 0) // if the minutes are negative 
    {
        TsMinutes += 60; //fix by taking 60 minutes from hours 
        TsHours-= 1;
    }
    if (TsSeconds < 0) ////if seconds are negative 
    {
        TsSeconds += 60; ////fix by taking 60 seconds from minutes
        TsMinutes -= 1;
    }
    return *this; //return the refrence
}

bool TimeSpan::operator==(const TimeSpan &other) const
{   //if the timespan hours and minutes equal eachother 
    if (TsHours== other.getHours() && TsMinutes == other.getMinutes())
    { 
        //if the seconds are equal as well
        if (TsSeconds == other.getSeconds())
        {
            return true; //return result as true 
        }
    } 
    return false; //if not return as false 
}

bool TimeSpan::operator!=(const TimeSpan &other) const
{ 
    //if the time hours and minutes do not equal eachother 
    if (TsHours!= other.getHours() && TsMinutes != other.getMinutes())
    {  
        //if the seconds also do not equal each other
        if (TsSeconds != other.getSeconds())

            return true; //return true
    }
    return false; //return false
}


//output to the stream
ostream &operator<<(ostream &stream, const TimeSpan &other)
{
    //output the timespan hours, minutes and seconds in proper format
    stream << "Hours: " << other.getHours() << ",";
    stream << " Minutes: " << other.getMinutes() << ",";
    stream << " Seconds: " << other.getSeconds();

    return stream; //return to the stream
}

//get the input stream
istream &operator>>(istream &stream, TimeSpan &other)
{
    //getting the input for timespan, hours minutes and secoonds 
    stream >> other.TsHours;
    stream >> other.TsMinutes;
    stream >> other.TsSeconds;

    return stream; //return to the input stream
}


