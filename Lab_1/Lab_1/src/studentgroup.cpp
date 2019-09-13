#include "studentgroup.h"

bool StudentGroup::checkStudentInGroup(const Student* s)
{
	for (auto it = students.begin(); it != students.end(); ++it)
		if (*it == s)
			return true;

	return false;
}

void StudentGroup::addStudent(Student* s)
{
	if (students.size() >= MAX_STUDENTS)
	{
		std::cout << " * Can't add new student " << s->getSecondName() << " .Group is full.\n";
		return;
	}

	if (checkStudentInGroup(s))
	{
		std::cout << " * Student " << s->getSecondName() << " " << s->getFirstName() << " " << s->getMiddleName() << " is already in the group.\n";
		return;
	}

	if (minAge != 0)
	{
		if (minAge > s->getAge())
		{
			std::cout << " * Student " << s->getSecondName() << " is less than necessary age.\n";
			return;
		}
	}

	if (minAverageScore != 0.0f)
	{
		if (minAverageScore > s->getAverageScore())
		{
			std::cout << " * Student " << s->getSecondName() << " has a low average score for this group.\n";
			return;
		}
	}

	s->updateGroupJoins(1);
	students.push_back(s);
	std::cout << " * Student " << s->getSecondName() << " " << s->getFirstName() << " " << s->getMiddleName() << " ";
	std::cout << "added to group " << course << "[" << groupID << "]\n";
}

void StudentGroup::removeStudent(Student* s)
{
	for (auto it = students.begin(); it != students.end(); ++it)
	{
		if (*it == s)
		{
			s->updateGroupJoins(0);
			students.erase(it);
			std::cout << " * Student " << s->getSecondName() << " " << s->getFirstName() << " " << s->getMiddleName() << " ";
			std::cout << "removed from group " << course << "[" << groupID << "]\n";
			return;
		}
	}
	std::cout << " * Student " << s->getSecondName() << " " << s->getFirstName() << " " << s->getMiddleName() << " is not a member of this group.\n";
}

void StudentGroup::removeStudent(const String & t_firstName)
{
	removeStudent(getStudent(t_firstName));
}

void StudentGroup::removeStudent(const String & t_firstName, const String & t_secondName)
{
	removeStudent(getStudent(t_firstName, t_secondName));
}

void StudentGroup::removeStudent(const String & t_firstName, const String & t_secondName, const String & t_middleName)
{
	removeStudent(getStudent(t_firstName, t_secondName, t_middleName));
}

Student* StudentGroup::getStudent(const String& t_firstName)
{
	for (auto& i : students)
		if (i->getFirstName() == t_firstName)
			return i;

	std::cout << "* Student " << t_firstName << " not found!\n";
	return nullptr;
}

Student* StudentGroup::getStudent(const String& t_firstName, const String& t_secondName)
{
	for (auto& i : students)
		if ((i->getFirstName() == t_firstName) && (i->getSecondName() == t_secondName))
			return i;

	std::cout << "* Student " << t_firstName << " " << t_secondName << " not found!\n";
	return nullptr;
}

Student* StudentGroup::getStudent(const String& t_firstName, const String& t_secondName, const String& t_middleName)
{
	for (auto& i : students)
		if ((i->getFirstName() == t_firstName) && (i->getSecondName() == t_secondName) && (i->getMiddleName() == t_middleName))
			return i;

	std::cout << "* Student " << t_firstName << " " << t_secondName << " " << t_middleName << " not found!\n";
	return nullptr;
}

size_t StudentGroup::getStudentsCount()
{
	return students.size();
}

int StudentGroup::getMinAverageScore()
{
	return minAverageScore;
}

int StudentGroup::getMinAge()
{
	return minAge;
}

void StudentGroup::printGroup()
{
	std::cout << "\n >> List of students of group " << course << "[" << groupID << "]: \n";
	for (auto& i : students)
	{
		std::cout << " * " << "[" << i->getID() << "] "<< i->getSecondName() << " " << i->getFirstName() << " " << i->getMiddleName() << " ";
		std::cout << "[" << i->getAge() << " y.o., " << i->getAverageScore() << " average score].\n";

	}
	std::cout << " >> Group average rating: " << getGroupAverageScore();
	std::cout << "\n\n";
}

void StudentGroup::sortWithSecondName()
{
	std::cout << " * Group " << course << " sorted by second name. \n";
	std::sort(students.begin(), students.end(), [](Student* a, Student* b) 
	{
		return a->getSecondName() < b->getSecondName();
	});
}

void StudentGroup::sortWithAverageScore()
{
	std::cout << " * Group " << course << " sorted by individual average score. \n";
	std::sort(students.begin(), students.end(), [](Student* a, Student* b)
	{
		return a->getAverageScore() > b->getAverageScore();
	});
}

void StudentGroup::checkGrades()
{
	for (auto& i : students)
	{
		if (minAverageScore > i->getAverageScore())
		{
			std::cout << " * Student " << i->getSecondName() << " kicked out from group, because low average score. \n";
			removeStudent(i);
		}
	}
}

void StudentGroup::checkAges()
{
	for (auto& i : students)
	{
		if (minAge > i->getAge())
		{
			std::cout << " * Student " << i->getSecondName() << " kicked out from group, because small age. \n";
			removeStudent(i);
		}
	}
}

float StudentGroup::getGroupAverageScore()
{
	float groupAverageScore = 0.0f;

	for (auto& i : students)
		groupAverageScore += i->getAverageScore();

	groupAverageScore /= students.size();
	return groupAverageScore;
}

void StudentGroup::setMinAge(unsigned const int t_minAge)
{
	minAge = t_minAge;
}

void StudentGroup::setMinAverageScore(float t_minAverageScore)
{
	minAverageScore = t_minAverageScore;
}
