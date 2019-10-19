#pragma once
#include <iostream>
#include <string>
#include <vector>

class StudentDefault;
class StudentActive;
class StudentWonk;

class Student
{
public:
	Student() {}

	Student(const std::string& t_firstName, const std::string& t_secondName, unsigned const t_age)
		: firstName(t_firstName), secondName(t_secondName), age(t_age) {}

	StudentDefault* changeToDefault();
	StudentActive* changeToActive();
	StudentWonk* changeToWonk();

	const std::string& getFirstName();
	const std::string& getSecondName();
	unsigned getAge();

	void setFirstName(const std::string& firstName);
	void setSecondName(const std::string& secondName);
	void setAge(unsigned age);

	void increaseGroupJoins();
	void decreaseGroupJoins();

	virtual int getExamGrade() = 0;
	virtual int getReExamGrade() = 0;

	virtual ~Student() = default;

protected:
	std::string firstName;
	std::string secondName;

	unsigned groupJoins = 0;
	unsigned age = 0;
};