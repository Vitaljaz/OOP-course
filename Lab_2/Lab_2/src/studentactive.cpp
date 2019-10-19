#include "studentactive.h"

StudentActive::StudentActive(const std::string & t_firstName, const std::string & t_secondName, unsigned const t_age)
{
	firstName = t_firstName;
	secondName = t_secondName;
	age = t_age;
}

int StudentActive::getExamGrade()
{
	return 1 + rand() % (6 - 2);
}

int StudentActive::getReExamGrade()
{
	return 3 + rand() % (6 - 3);
}
