#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

#include "student.h"
#include "studentdefault.h"
#include "studentactive.h"
#include "studentwonk.h"

class StudentGroup
{
public:
	StudentGroup() = delete;

	StudentGroup(const std::string& t_course, unsigned const t_groupID) :
		course(t_course), groupID(t_groupID) {}

	Student* getStudent(const std::string& t_firstName, const std::string& t_secondName);


	const size_t getStudentsCount();
	const std::string& getCourse();
	const int getGroupID();
	
	void sort();
	void startExam();
	void startReExam();
	void addStudent(Student* s);
	void removeStudent(Student* s);

	const std::vector<Student*>& getStudentsList();

	virtual ~StudentGroup() = default;

private:
	std::vector<Student*> students;
	std::vector<Student*> reExamList;

	std::string course;
	unsigned groupID;
	unsigned const MAX_STUDENTS = 20;

	bool findStudentInGroup(Student* s);
};

std::ostream& operator<< (std::ostream& out, StudentGroup& group);