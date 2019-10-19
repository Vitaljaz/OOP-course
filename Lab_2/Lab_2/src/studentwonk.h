#pragma once
#include "student.h"

class StudentWonk : public Student
{
public:
	StudentWonk() = default;

	StudentWonk(const std::string& t_firstName, const std::string& t_secondName, unsigned const t_age);

	int getExamGrade() override;
	int getReExamGrade() override;

	virtual ~StudentWonk() = default;
};