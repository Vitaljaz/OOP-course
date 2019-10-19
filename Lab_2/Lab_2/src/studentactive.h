#pragma once
#include "student.h"
#include "studentdefault.h"

class StudentActive : public StudentDefault
{
public:
	StudentActive() = delete;

	StudentActive(const std::string& t_firstName, const std::string& t_secondName, unsigned const t_age);

	int getExamGrade() override;
	int getReExamGrade() override;

	virtual ~StudentActive() = default;
};