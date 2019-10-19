#include "studentdefault.h"

StudentDefault::StudentDefault(const std::string & t_firstName, const std::string & t_secondName, unsigned const t_age)
{
	firstName = t_firstName;
	secondName = t_secondName;
	age = t_age;
}

int StudentDefault::getExamGrade()
{
	return 1 + rand() % (6 - 2);
}

int StudentDefault::getReExamGrade()
{
	return 1 + rand() % (6 - 2);
}
