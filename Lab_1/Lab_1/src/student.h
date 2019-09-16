#pragma once
#include <iostream>
#include <array>
#include <string>

using String = std::string;
using uint = unsigned int;

class Student {
private:
	String firstName;
	String secondName;
	String middleName;

	uint age = 0;
	uint ID = 0;
	uint groupJoins = 0;

	std::array<int, 5>lastGrades;

public:

	Student() = delete;

	Student(const String& t_firstName, const String& t_secondName, const String& t_middleName) :
		firstName(t_firstName), secondName(t_secondName), middleName(t_middleName) {}

	Student(const String& t_firstName, const String& t_secondName, const String& t_middleName, 
		const uint& t_age, const uint& t_ID) : Student(t_firstName, t_secondName, t_middleName) 
	{
		age = t_age;
		ID = t_ID;
	}

	Student(const String& t_firstName, const String& t_secondName, const String& t_middleName, const uint& t_age, 
		const uint& t_ID, std::array <int, 5> t_lastGrades) : Student(t_firstName, t_secondName, t_middleName)
	{
		age = t_age;
		ID = t_ID;
		lastGrades = t_lastGrades;
	}

	const String& getFirstName();
	const String& getSecondName();
	const String& getMiddleName();
	const uint getAge();
	const uint getID();
	const float getAverageScore();

	void setFirstName(const String& t_firstName);
	void setSecondName(const String& t_secondName);
	void setMiddleName(const String& t_middleName);
	void setID(const uint& t_ID);
	void setAge(const uint& t_age);
	void setLastGrades(const std::array<int, 5>& t_lastGrades);

	void increaseGroupJoins();
	void decreaseGroupJoins();
	void printInformation();

	bool operator ==(const Student& other) const;

	~Student() = default;
};