#ifndef CHILD_H_
#define CHILD_H_
#include <string>
using namespace std;

class Child
{
public:
	// public constructors
	// empty constructor
	Child();			
	// constuctor takes firstName, lastName and int childAge									
	Child(string firstName, string lastName, int childAge); 
	//  virtual destructor for child class
	virtual ~Child();										

	// getters
	string getfName() const;
	string getlName() const;
	int getchildAge() const;
	// setters
	void setfName(const string &firstName);
	void setlName(const string &lastName);
	void setchildAge(const int &childAge);

	// operators
	bool operator==(const Child &secondChild) const;
	bool operator!=(const Child &secondChild) const;
	bool operator>(const Child &secondChild) const;
	bool operator>=(const Child &secondChild) const;
	bool operator<(const Child &secondChild) const;
	bool operator<=(const Child &secondChild) const;
	Child &operator=(const Child &secondChild);

//inout and output to the stream
	friend ostream &operator<<(ostream &stream, const Child &child);
	friend istream &operator>>(istream &stream, const Child &child);

private:
	// private constructors
	string firstName;
	string lastName;
	int childAge;
};
#endif