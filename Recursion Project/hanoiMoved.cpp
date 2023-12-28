#include <iostream>
#include <sys/time.h>
#include <cmath>

using namespace std;
int countMoves;  //global variable to count number of moves
bool printFlag = true; //global flag to control whether to print or not  

//helper function to reset count of moves
void resetCountHelper()
{
    countMoves = 0;
}

//helper function to reset print flag
void resetPrintFlag() 
{
    printFlag = true;
}

//recursive function
void hanoiMoves(int n, char initialRod, char passedRod, char middleRod)
{
    if (n == 0)
    {
        return; // base case
    }
    countMoves++; // increment count of moves
    hanoiMoves(n - 1, initialRod, middleRod, passedRod); //move n-1 disks from initial rod to middle rod
    if (printFlag) //if true
    {
        cout << "Move disk " << n << " from " << initialRod << " to " << passedRod << endl; //print moves
    }
    hanoiMoves(n - 1, middleRod, passedRod, initialRod); //move the rest of the n-1 disks from moved rod to passed rod
}

//calculating the elasped time in between the start time and end time
long long int getElapsedTime(const timeval &startTime, const timeval &endTime) // long long int to take in big amout
{
    return (endTime.tv_sec - startTime.tv_sec) * 1000000 + (endTime.tv_usec - startTime.tv_usec);
}

int main()

{
   
    resetCountHelper();

    int singleInput = 4; 
    cout << "Displaying individual disk moves, for a single value of : " << singleInput << endl;
    hanoiMoves(singleInput, 'A', 'C', 'B'); 

    cout << "\n\nDisplaying from n = 1 to n = 15 for viewing time complexity:" << endl;
    cout << "(will not display disk moves when n > 3)\n" << endl;

    for (int n = 1; n <= 15; n++)
    {
        timeval startTime, endTime;
        gettimeofday(&startTime, nullptr); 
        if (n > 3)
        {
            printFlag = false;
        }

        hanoiMoves(n, 'A', 'C', 'B'); // run

        gettimeofday(&endTime, nullptr);                                
        long long int elapsedTime = getElapsedTime(startTime, endTime); 

        cout << "\nNumber of moves for " << n << ": " << countMoves << endl;
        cout << "Elapsed time for " << n << ": " << elapsedTime << " microseconds \n\n"
             << endl;
        
        resetCountHelper();
        resetPrintFlag();
    }

    return 0;
}