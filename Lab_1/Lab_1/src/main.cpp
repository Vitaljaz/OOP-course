#include <iostream>
#include "studentgroup.h"

int main()
{
	Student* Misha = new Student("Misha", "Ivanov", "Ivanovich", 18, 13, { 2,3,4,4,5 });
	Student* Egor = new Student("Egor", "Semenov", "Sergeevich", 19, 8, { 4,4,4,4,5 });
	Student* Semen = new Student("Semen", "Serkov", "Alekseevich", 18, 4, { 5,5,5,4,5 });
	Student* Igor = new Student("Igor", "Vorobev", "Popovich", 18, 22, { 2,2,3,3,3 });
	Student* Victor = new Student("Victor", "Gusev", "Aleksandrovich", 18, 44, { 3,3,4,4,5 });
	Student* Aleksey = new Student("Aleksey", "Dmitriev", "Antonovich", 20, 31, { 5,3,3,4,5 });
	Student* Evgeniy = new Student("Evgeniy", "Lorikov", "Petrovich", 16, 32, { 5,2,4,2,5 });

	StudentGroup* MathGroup = new StudentGroup("Math", 4312, 18, 3.0f);
	StudentGroup* PhysGroup = new StudentGroup("Phys", 5021, 18, 0);

	Misha->printInformation();

	MathGroup->addStudent(Semen);
	MathGroup->addStudent(Misha);
	MathGroup->addStudent(Egor);
	MathGroup->addStudent(Igor);

	PhysGroup->addStudent(Misha);
	PhysGroup->addStudent(Victor);
	PhysGroup->addStudent(Aleksey);
	PhysGroup->addStudent(Evgeniy);

	Misha->printInformation();

	MathGroup->printGroup();
	
	MathGroup->sortWithSecondName();
	MathGroup->printGroup();

	PhysGroup->printGroup();
	
	PhysGroup->sortWithAverageScore();
	PhysGroup->printGroup();

	PhysGroup->removeStudent(Misha);

	Misha->printInformation();

	PhysGroup->printGroup();

	MathGroup->setMinAverageScore(4.0f);
	MathGroup->checkGrades();

	MathGroup->printGroup();

	delete Misha, Egor, Semen, Igor, Victor, Aleksey, Evgeniy;
	delete MathGroup, PhysGroup;
	std::cin.get();
}