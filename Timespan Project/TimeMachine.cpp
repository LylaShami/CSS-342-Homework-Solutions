#include <iostream>
#include <cmath>
#include "TimeSpan.h"

using namespace std;

int main()
{
    cout << "----------------------------TIMESPAN TEST-----------------------------" << endl << endl;

    cout << "Constructors:   " << endl << endl;

    TimeSpan duration1(50, 30, 20);

    cout << "Correct answer-> Hours: 50, Minutes: 30, Seconds: 20" << endl;

    cout << "My answer is---> "  << duration1 << endl << endl;

    TimeSpan duration2(6, -30, 2);

    cout << "Correct Answer-> Hours: 5, Minutes: 30, Seconds: 2 " << endl;

    cout << "My answer is---> " << duration2 << endl << endl;

    TimeSpan duration3(7, 150, 8902);

      cout << "Correct Answer-> Hours: 11, Minutes: 58, Seconds: 22 " << endl;

      cout << "My answer is---> " << duration3 << endl << endl;

    TimeSpan duration4(4, -56);

      cout << "Correct Answer-> Hours: 0, Minutes: 3, Seconds: 4 " << endl;

      cout << "My answer is---> " << duration4 << endl << endl;

    TimeSpan duration5(98765);

    cout << "Correct Answer-> Hours: 27, Minutes: 26, Seconds: 5 " << endl;

    cout << "My answer is---> " << duration5 << endl << endl;


     TimeSpan duration6(0, 0, 456);

    cout << "Correct Answer-> Hours: 0, Minutes: 7, Seconds: 36 " << endl;

    cout << "My answer is---> " << duration6 << endl << endl;

    cout << "Constructors are working :)" << endl << endl;

    cout << "Negative Input:  " << endl << endl;

    TimeSpan duration7(5, 10, 30);

    TimeSpan duration8;

    duration8 = -duration7;

    cout << "Correct Answer-> Hours: -5, Minutes: -10, Seconds: -30" << endl;

    cout << "My answer is---> " << duration8 << endl << endl;

    cout << "Correct Answer-> Hours: 5, Minutes: 10, Seconds: 30" << endl;

    cout << "My answer is---> " << duration7 << endl << endl;

    cout << "Negative Numbers are working:)" << endl << endl;

    cout << "Get and Set:  " << endl << endl;

    duration7.setTime(3, 6, 9);

    cout << "Correct Answer-> Hours: 3, Minutes: 6, Seconds: 9 " << endl;

    cout << "My answer is---> " << duration7 << endl << endl;

    duration8.setTime(200, 0, 78);

    cout << "Correct Answer-> Hours: 200, Minutes: 1, Seconds: 18 " << endl;

    cout << "My answer is---> " << duration8 << endl << endl;

    cout << "Getters and Setters are working:) " << endl << endl;


    cout << "Addition and Subtraction test:  " << endl << endl;

    TimeSpan duration10(6, 25, 36);
    TimeSpan duration11(0, 30, 25);
    TimeSpan duration12;

    duration12 = duration10 + duration11;

    cout << "Correct Answer-> Hours: 6, Minutes: 56, Seconds: 1" << endl;

    cout << "My answer is---> " << duration12 << endl << endl;
    
    cout << "Add tests are working:)" << endl << endl;

    TimeSpan duration13(12, 45, 9);
    TimeSpan duration14(25, 4, 0);
    TimeSpan duration15;

    duration15 = duration13 - duration14;

    cout << "Correct Answer-> Hours: -12, Minutes: -18, Seconds: -51" << endl;

    cout << "My answer is---> " << duration15 << endl << endl;

    cout  << "Subtract tests are working:)" << endl  << endl;


     cout << "Addition Overload Test:   " << endl << endl;

    TimeSpan duration16(1, 30, 45);
    TimeSpan duration17(0, 45, 15);

    duration16 += duration17;

    cout << "Correct Answer-> Hours: 2, Minutes: 16, Seconds: 0" << endl;

    cout << "My answer is---> " << duration16 << endl << endl;  

    cout << "Addition overload tests working:) " << endl << endl;


    cout << "Subtraction Overload Test: " << endl << endl;

    TimeSpan duration18(10, 25, 45);
    TimeSpan duration19(3, 15, 20);

    duration18 -= duration19;

    cout << "Correct Answer-> Hours: 7, Minutes: 10, Seconds: 25" << endl;

    cout << "My answer is---> " << duration18 << endl << endl;  

    cout << "Subtraction Overload tests are working :)" << endl << endl;

    cout << "Equals and not Equals Test: " << endl << endl;

    TimeSpan duration26(5, 10, 30);
    TimeSpan duration27(5, 10, 30);
    TimeSpan duration28(7, 15, 45);

    bool result1 = (duration26 == duration27);
    bool result2 = (duration26 == duration28);

   cout << "Correct Answer -> Result 1: 1, Result 2: 0" << endl;

   cout << "My answer is ---> Result 1: " << result1 << ", Result 2: " << result2 << endl << endl;


   cout << "Not Equals Operator Test: " << endl << endl;

  bool result3 = (duration26 != duration27);

  bool result4 = (duration26 != duration28);

  cout << "Correct Answer -> Result 3: 0, Result 4: 1" << endl;

  cout << "My answer is ---> Result 3: " << result3 << ", Result 4: " << result4 << endl << endl;

  cout << "Cin and Cout Tests" << endl;

  TimeSpan duration30;

  cout << "Enter time in the following format: hours mintues seconds" << endl;

  cin >> duration30;

  cout << duration30 << endl << endl;
    
  cout << "Cin and cout test are working:)" << endl << endl;

    return 0;
}
