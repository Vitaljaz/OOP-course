#include "studentgroup.h"
#include <algorithm>

bool StudentGroup::findStudentInGroup(Student * s)
{
	for (auto it = students.begin(); it != students.end(); ++it)
		if (*it == s)
			return true;

	return false;
}

Student * StudentGroup::getStudent(const std::string & t_firstName, const std::string & t_secondName)
{
	for (auto& i : students)
		if ((i->getFirstName() == t_firstName) && (i->getSecondName() == t_secondName))
			return i;

	return nullptr;
}

const size_t StudentGroup::getStudentsCount()
{
	return students.size();
}

const std::string& StudentGroup::getCourse()
{
	return course;
}

const int StudentGroup::getGroupID()
{
	return groupID;
}

void StudentGroup::sort()
{
	std::sort(students.begin(), students.end(), [](Student* a, Student* b)
	{
		return a->getSecondName() < b->getSecondName();
	});
}

void StudentGroup::startExam()
{
	for (auto& i : students)
		if (i->getExamGrade() <= 2)
			reExamList.push_back(i);
}

void StudentGroup::startReExam()
{
	for (auto it = reExamList.begin(); it != reExamList.end(); ++it)
		if ((*it)->getReExamGrade() <= 2)
			removeStudent(*it);

	reExamList.clear();
}

void StudentGroup::addStudent(Student * s)
{
	if (students.size() >= MAX_STUDENTS)
		return;

	if (findStudentInGroup(s))
		return;

	s->increaseGroupJoins();
	students.push_back(s);
}

void StudentGroup::removeStudent(Student * s)
{
	for (auto it = students.begin(); it != students.end(); ++it)
	{
		if (*it == s)
		{
			s->decreaseGroupJoins();
			students.erase(it);
			return;
		}
	}
}

const std::vector<Student*>& StudentGroup::getStudentsList()
{
	return students;
}

std::ostream & operator<<(std::ostream & out, StudentGroup & group)
{
	std::vector<Student*> s = group.getStudentsList();
	out << "\n >> List of students of group " << group.getCourse() << "[" << group.getGroupID() << "]: \n";
	
	for (auto& i : s)
		out << " * " << i->getSecondName() << " " << i->getFirstName() << std::endl;;

	out << "Students in group: " << group.getStudentsCount() << ".\n";

	return out;
}
