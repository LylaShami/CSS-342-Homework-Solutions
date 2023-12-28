#include <iostream>
#include <cstdlib>
using namespace std;

int getCatalanInput(int);
long int catalanCalculator(int inputFromUser);


// get the input from the user, make sure that the input is between 0-20
int getCatalanInput(int userInput)
{
    int input = userInput; 

    while (input < 0 || input > 20)
    { // ensuring the input will be in the do-able range

        cout << "\nPlease input a number between 0 - 20." << endl;

        // store input
        cin >> input; // get the input from the user
    }
    return input; 
}

// recursive function to find the catalan number based on the user's  input
long int catalanCalculator(int inputFromUser)

{

    // base case, 0 the lowest acceptable value
    if (inputFromUser == 0)
        return 1;
    else
    {
        long int returnValue = 0;

        // calculate nth catalan number for n>0
        int i = 0;
        while (i < inputFromUser)
        {
            returnValue = returnValue + (catalanCalculator(i) * catalanCalculator(inputFromUser - 1 - i));
            i++;
        }
        return returnValue;
    }
}

int main(int argc, char *argv[]) // argc is the num of arguments, argv is an array of the args
{
  if(argc < 1){ // if the user did not pass in the values
    cout << "/n Please restart program by calling executable with an argument to calculate the Catalan number. Thanks :D /n";
    return 0;

  } else{

    // helper for getting and validating the input
    int inputFromUser = getCatalanInput(atoi(argv[1]));

    cout << "\nThe Catalan number for your input of " << inputFromUser << ", is equal to:  " << catalanCalculator(inputFromUser) << endl;
    cout << "\nThanks for playing :D \n"
         << endl;
  }

return 0;
}

