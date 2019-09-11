#pragma once
#include <iostream>
#include <array>
#include <string>

using String = std::string;

class Student {
private:
	String firstName;
	String secondName;
	String middleName;

	unsigned int age;
	unsigned int ID;
	unsigned int groupJoins = 0;

	std::array<int, 5>lastGrades;

public:

	Student() = delete;

	Student(String t_firstName, String t_secondName, String t_middleName) :
		firstName(t_firstName), secondName(t_secondName), middleName(t_middleName) {}

	Student(String t_firstName, String t_secondName, String t_middleName, unsigned int t_age, unsigned int t_ID) :
		firstName(t_firstName), secondName(t_secondName), middleName(t_middleName), age(t_age), ID(t_ID) {}

	Student(String t_firstName, String t_secondName, String t_middleName, unsigned int t_age, unsigned int t_ID, std::array <int, 5> t_lastGrades) :
		firstName(t_firstName), secondName(t_secondName), middleName(t_middleName), age(t_age), ID(t_ID), lastGrades(t_lastGrades) {}

	~Student() {}

	String getFirstName();
	String getSecondName();
	String getMiddleName();
	int getAge();
	int getID();
	float getAverageScore();

	void setFirstName(const String& t_firstName);
	void setSecondName(const String& t_secondName);
	void setMiddleName(const String& t_middleName);
	void setID(unsigned const int& t_ID);
	void setAge(unsigned const int& t_age);
	void setLastGrades(const std::array<int, 5> t_lastGrades);

	void updateGroupJoins(int mode);
	void printInformation();

	bool operator ==(const Student & other) const;
};