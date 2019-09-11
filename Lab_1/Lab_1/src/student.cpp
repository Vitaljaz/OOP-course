#include "student.h"

String Student::getFirstName()
{
	return firstName;
}

String Student::getSecondName()
{
	return secondName;
}

String Student::getMiddleName()
{
	return middleName;
}

int Student::getAge()
{
	return age;
}

int Student::getID()
{
	return ID;
}

float Student::getAverageScore()
{
	float averageScore = 0.0f;

	for (auto& i : lastGrades)
		averageScore += i;

	averageScore /= 5;
	return averageScore;
}

void Student::setFirstName(const String& t_firstName)
{
	firstName = t_firstName;
}

void Student::setSecondName(const String& t_secondName)
{
	secondName = t_secondName;
}

void Student::setMiddleName(const String& t_middleName)
{
	middleName = t_middleName;
}

void Student::setID(unsigned const int& t_ID)
{
	ID = t_ID;
}

void Student::setAge(unsigned const int& t_age)
{
	age = t_age;
}

void Student::setLastGrades(const std::array<int, 5> t_lastGrades)
{
	lastGrades = t_lastGrades;
}

void Student::updateGroupJoins(int mode)
{
	if (mode == 1)
		groupJoins++;

	if (mode == 0)
		groupJoins--;
}

void Student::printInformation()
{
	std::cout << "\n * Information about student: " << secondName << " " << firstName << " " << middleName << " " << std::endl;
	std::cout << " * ID: " << ID << std::endl;
	std::cout << " * Age: " << age << std::endl;
	std::cout << " * Consists of " << groupJoins << " groups. " << std::endl;
	std::cout.precision(5);
	std::cout << " * Average score: " << getAverageScore() << std::endl;
	std::cout << " * Last grades: ";
	for (auto& i : lastGrades)
		std::cout << i << " ";
	std::cout << "\n\n";
}

bool Student::operator==(const Student& other) const
{
	return (firstName == other.firstName) && (secondName == other.secondName) && (middleName == other.middleName)
		&& (ID == other.ID) && (age == other.age);
}


