#include "studentgroup.h"

void StudentGroup::addStudent(Student& s)
{
	if (students.size() >= MAX_STUDENTS)
	{
		std::cout << " * Can't add new student. Group is full.\n";
		return;
	}
	s.updateGroupJoins(1);
	students.push_back(s);
	std::cout << " * Student " << s.getSecondName() << " " << s.getFirstName() << " " << s.getMiddleName() << " ";
	std::cout << "added to group " << course << "[" << groupID << "]\n";
}

void StudentGroup::removeStudent(Student& s)
{
	for (auto it = students.begin(); it != students.end(); ++it)
	{
		if (*it == s)
		{
			s.updateGroupJoins(0);
			students.erase(it);
			std::cout << " * Student " << s.getSecondName() << " " << s.getFirstName() << " " << s.getMiddleName() << " ";
			std::cout << "removed from group " << course << "[" << groupID << "]\n";
			return;
		}
	}
}

Student StudentGroup::getStudent(const String& t_firstName)
{
	for (auto& i : students)
		if (i.getFirstName() == t_firstName)
			return i;
}

Student StudentGroup::getStudent(const String& t_firstName, const String& t_secondName)
{
	for (auto& i : students)
		if ((i.getFirstName() == t_firstName) && (i.getSecondName() == t_secondName))
			return i;
}

Student StudentGroup::getStudent(const String& t_firstName, const String& t_secondName, const String& t_middleName)
{
	for (auto& i : students)
		if ((i.getFirstName() == t_firstName) && (i.getSecondName() == t_secondName) && (i.getMiddleName() == t_middleName))
			return i;
}

size_t StudentGroup::getStudentsCount()
{
	return students.size();
}

void StudentGroup::printGroup()
{
	std::cout << "\n >> List of students of group " << course << "[" << groupID << "]: \n";
	for (auto& i : students)
	{
		std::cout << " * " << "[" << i.getID() << "] "<< i.getSecondName() << " " << i.getFirstName() << " " << i.getMiddleName() << " ";
		std::cout << "[" << i.getAge() << " y.o., " << i.getAverageScore() << " average score].\n";

	}
	std::cout << " >> Group average rating: " << getGroupAverageScore();
	std::cout << "\n\n";
}

void StudentGroup::sortWithSecondName()
{
	std::cout << " * Group sorted by second name. \n";
	std::sort(students.begin(), students.end(), [](Student& a, Student& b) 
	{
		return a.getSecondName() < b.getSecondName();
	});
}

void StudentGroup::sortWithAverageScore()
{
	std::cout << " * Group sorted by individual average score. \n";
	std::sort(students.begin(), students.end(), [](Student& a, Student& b)
	{
		return a.getAverageScore() > b.getAverageScore();
	});
}

float StudentGroup::getGroupAverageScore()
{
	float groupAverageScore = 0.0f;

	for (auto& i : students)
		groupAverageScore += i.getAverageScore();

	groupAverageScore /= students.size();
	return groupAverageScore;
}
