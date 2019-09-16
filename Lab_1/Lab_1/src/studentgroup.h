#pragma once
#include <iostream>
#include <vector>

#include "student.h"

class StudentGroup {
private:
	std::vector <Student*> students;
	String course;
	uint groupID = 0;
	uint minAge = 0;
	const uint MAX_STUDENTS = 20;
	float minAverageScore = 0.0f;

	bool checkStudentInGroup(const Student* s);

public:
	StudentGroup() = delete;

	StudentGroup(const String& t_course, uint& t_groupID):
		course(t_course), groupID(t_groupID) {}

	StudentGroup(const String& t_course, const uint& t_groupID, const uint& t_minAge, const float& t_minAverageScore) : 
		StudentGroup(t_course, groupID) {
		minAge = t_minAge;
		minAverageScore = t_minAverageScore;
	}

	Student* getStudent(const String& t_firstName);
	Student* getStudent(const String& t_firstName, const String& t_secondName);
	Student* getStudent(const String& t_firstName, const String& t_secondName, const String& t_middleName);

	const size_t getStudentsCount();
	const int getMinAge();
	const float getMinAverageScore();
	const float getGroupAverageScore();

	void setMinAge(const uint& t_minAge);
	void setMinAverageScore(const float& t_minAverageScore);
	void addStudent(Student* s);
	void removeStudent(Student* s);
	void removeStudent(const String& t_firstName);
	void removeStudent(const String& t_firstName, const String& t_secondName);
	void removeStudent(const String& t_firstName, const String& t_secondName, const String& t_middleName);
	void printGroup();
	void sortWithSecondName();
	void sortWithAverageScore();
	void checkGrades();
	void checkAges();

	~StudentGroup() = default;
};