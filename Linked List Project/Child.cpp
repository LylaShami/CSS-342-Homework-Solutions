
#include "Child.h"
#include <iostream>

Child::Child() : firstName(""), lastName(""), childAge(0)
{
}

Child::Child(string thefName, string thelName, int thechildAge) : firstName(thefName), lastName(thelName), childAge(thechildAge)
{
}

Child::~Child()
{
}

string Child::getfName() const
{
	return firstName;
}

string Child::getlName() const
{
	return lastName;
}

int Child::getchildAge() const
{
	return childAge;
}

void Child::setfName(const string &firstName)
{
	this->firstName = firstName;
}

void Child::setlName(const string &lastName)
{
	this->lastName = lastName;
}

void Child::setchildAge(const int &childAge)
{
	this->childAge = childAge;
}

bool Child::operator==(const Child &secondChild) const
{
	// returning true, if names passed in are equal
	return (lastName == secondChild.lastName &&
			firstName == secondChild.firstName &&
			childAge == secondChild.childAge);
}

bool Child::operator!=(const Child &secondChild) const
{
	// using equal operator but returning true if names are not equal
	return !(*this == secondChild);
}

bool Child::operator>(const Child &secondChild) const
{
	// using less than operator to return true of the second child is less
	return !(*this < secondChild);
}

bool Child::operator>=(const Child &secondChild) const
{
	// using both operators equal and less than to return true if child is equal or not less than
	return (*this == secondChild) || !(*this < secondChild);
}
bool Child::operator<(const Child &secondChild) const
{
	// checking between the current child and second child
	if (lastName != secondChild.lastName)
	{
		// if the current last name is less than seconds child last name return true
		return lastName < secondChild.lastName;
	}
	// checking between the first name of the current child and second child
	if (firstName != secondChild.firstName)
	{
		// if current first name is less than second first name return true
		return firstName < secondChild.firstName;
	}
	// if both conditions above are met, then return if current child is less than second
	return childAge < secondChild.childAge;
}

bool Child::operator<=(const Child &secondChild) const
{
	// Using both operators less than and equal to check the current child is less than or equal to the second child
	return (*this < secondChild || *this == secondChild);
}

Child &Child::operator=(const Child &secondChild)
{
	// assigning the names and ages
	lastName = secondChild.lastName;
	firstName = secondChild.firstName;
	childAge = secondChild.childAge;
	return *this;
}

ostream &operator<<(ostream &stream, const Child &child)
{
	// printing out to the stream in desired output
	stream << child.getfName() << child.getlName() << child.getchildAge();
	return stream;
}

istream &operator>>(istream &stream, Child &child)
{
	// declaing the variables for age, first name and last name
	int childAge;
	string firstName, lastName;
	// taking input from stream  first, last name and child
	stream >> firstName >> lastName >> childAge;

	// setting the inputs taken out to the stream to the feilds
	child.setfName(firstName);
	child.setlName(lastName);
	child.setchildAge(childAge);
	return stream;
}