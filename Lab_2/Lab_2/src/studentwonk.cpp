#include "studentwonk.h"

StudentWonk::StudentWonk(const std::string & t_firstName, const std::string & t_secondName, unsigned const t_age)
{
	firstName = t_firstName;
	secondName = t_secondName;
	age = t_age;
}

int StudentWonk::getExamGrade()
{
	return 4 + rand() % (6 - 4);
}

int StudentWonk::getReExamGrade()
{
	return 4 + rand() % (6 - 4);
}
