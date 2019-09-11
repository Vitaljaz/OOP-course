#pragma once
#include <iostream>
#include <vector>

#include "student.h"

class StudentGroup {
private:
	std::vector <Student> students;
	String course;
	const int MAX_STUDENTS = 20;
	int groupID;

public:
	StudentGroup() = delete;

	StudentGroup(String t_course, int t_groupID): 
		course(t_course), groupID(t_groupID) {}

	void addStudent(Student& s);
	void removeStudent(Student& s);

	Student getStudent(const String& t_firstName);
	Student getStudent(const String& t_firstName, const String& t_secondName);
	Student getStudent(const String& t_firstName, const String& t_secondName, const String& t_middleName);

	size_t getStudentsCount();

	void printGroup();
	void sortWithSecondName();
	void sortWithAverageScore();
	float getGroupAverageScore();

	~StudentGroup() {}


};