#pragma once
#include <iostream>
#include <vector>

#include "student.h"

class StudentGroup {
private:
	std::vector <Student*> students;
	String course;
	int groupID;
	const int MAX_STUDENTS = 20;
	unsigned int minAge = 0;
	float minAverageScore = 0.0f;

	bool checkStudentInGroup(const Student* s);

public:
	StudentGroup() = delete;

	StudentGroup(String t_course, int t_groupID): 
		course(t_course), groupID(t_groupID) {}

	StudentGroup(String t_course, int t_groupID, unsigned int t_minAge, float t_minAverageScore) :
		course(t_course), groupID(t_groupID), minAge(t_minAge), minAverageScore(t_minAverageScore) {}

	Student* getStudent(const String& t_firstName);
	Student* getStudent(const String& t_firstName, const String& t_secondName);
	Student* getStudent(const String& t_firstName, const String& t_secondName, const String& t_middleName);

	size_t getStudentsCount();
	int getMinAverageScore();
	int getMinAge();
	float getGroupAverageScore();

	void setMinAge(unsigned const int t_minAge);
	void setMinAverageScore(float t_minAverageScore);
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

	~StudentGroup();
};