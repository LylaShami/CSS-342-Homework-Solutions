#ifndef TIME_SPAN_H_
#define TIME_SPAN_H_
#include <iostream>
using namespace std;
 

class TimeSpan
{
public:

//outsream to stream to the terminal
    friend ostream &operator<<(ostream &stream, const TimeSpan& other);
//istream to take input from terminal 
    friend istream &operator>>(istream &stream, TimeSpan& other);


//constructors 
    TimeSpan(); //empty constrcutor
    TimeSpan(double hours, double minutes, double seconds); //taking in all three durations
    TimeSpan(double minutes, double seconds); //taking in just two 
    TimeSpan(double seconds); //taking in one

  //setter
    void setTime(double hours, double minutes, double seconds); //setting the time
   
    // the helper time divided by 3600 will give ne the hours
    int getHours() const;
    //helper time mod 3600 divided by 60 will give me the minutes
    int getMinutes() const;
    //the helper time mod 3600 mod 60 will give me the seconds
    // (total time % 3600) % 60 will be seconds
    int getSeconds() const;
    
   //the unaury operator will return if any time is passed in as negative 
    TimeSpan operator-() const; 
   
   //the addition operator will add durations together
    TimeSpan operator+(const TimeSpan &other) const;
    //doing addition on timespan 
    TimeSpan &operator+=(const TimeSpan &other);
    //the minus operator will subtract the durations together
    TimeSpan operator-(const TimeSpan &other) const;
    //doing subtraction on timespan
    TimeSpan &operator-=(const TimeSpan &other);
   //the equals operator will check if the timespan durations are the same 
    bool operator==(const TimeSpan &other) const;
    //the notequals operator will check if the timespan durations are not the same
    bool operator!=(const TimeSpan &other) const;
    
    
   
    private:
    //the helpertime function calculates the time altogether
    int helperTime() const;
    //private data variables
    double TsHours;
    double TsMinutes;
    double TsSeconds;

};
#endif