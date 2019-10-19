#pragma once
#include "student.h"

class StudentDefault : public Student
{
public:
	StudentDefault() {}

	StudentDefault(const std::string& t_firstName, const std::string& t_secondName, unsigned const t_age);

	int getExamGrade() override;
	int getReExamGrade() override;

	virtual ~StudentDefault() = default;
};