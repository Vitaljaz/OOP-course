#include "student.h"

const String& Student::getFirstName()
{
	return firstName;
}

const String& Student::getSecondName()
{
	return secondName;
}

const String& Student::getMiddleName()
{
	return middleName;
}

const uint Student::getAge()
{
	return age;
}

const uint Student::getID()
{
	return ID;
}

const float Student::getAverageScore()
{
	float averageScore = 0.0f;

	for (auto& i : lastGrades)
		averageScore += i;

	averageScore /= lastGrades.size();
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

void Student::setID(const uint& t_ID)
{
	ID = t_ID;
}

void Student::setAge(const uint& t_age)
{
	age = t_age;
}

void Student::setLastGrades(const std::array<int, 5>& t_lastGrades)
{
	lastGrades = t_lastGrades;
}

void Student::increaseGroupJoins()
{
	groupJoins++;
}

void Student::decreaseGroupJoins()
{
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


