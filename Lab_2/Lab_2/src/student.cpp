#include "student.h"
#include "studentdefault.h"
#include "studentactive.h"
#include "studentwonk.h"

StudentDefault * Student::changeToDefault()
{
	return new StudentDefault(firstName, secondName, age);
}

StudentActive * Student::changeToActive()
{
	return new StudentActive(firstName, secondName, age);
}

StudentWonk * Student::changeToWonk()
{
	return new StudentWonk(firstName, secondName, age);
}

const std::string & Student::getFirstName()
{
	return this->firstName;
}

const std::string & Student::getSecondName()
{
	return this->secondName;
}

unsigned Student::getAge()
{
	return this->age;
}

void Student::setFirstName(const std::string & firstName)
{
	this->firstName = firstName;
}

void Student::setSecondName(const std::string & secondName)
{
	this->secondName = secondName;
}

void Student::setAge(unsigned age)
{
	this->age = age;
}

void Student::increaseGroupJoins()
{
	groupJoins++;
}

void Student::decreaseGroupJoins()
{
	groupJoins--;
}
