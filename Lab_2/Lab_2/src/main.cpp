#include <iostream>
#include "studentgroup.h"

int main()
{
	srand(time(nullptr));

	StudentDefault *Mike = new StudentDefault("Mike", "Robin", 18);
	StudentDefault *John = new StudentDefault("John", "Drake", 18);
	StudentDefault *William = new StudentDefault("William", "Tomson", 18);

	StudentWonk *Anthony = new StudentWonk("Antony", "Smith", 18);
	StudentWonk *Zor = new StudentWonk("Zor", "Brasco", 18);
	StudentWonk *Alex = new StudentWonk("Alex", "Johnson", 18);

	StudentActive *Martin = new StudentActive("Martin", "Elder", 19);
	StudentActive *Mark = new StudentActive("Mark", "Wall", 19);
	StudentActive *Evan = new StudentActive("Evan", "Cake", 19);

	StudentActive *AlexActive = Alex->changeToActive();
	StudentDefault *MartinDefault = Martin->changeToDefault();
	StudentWonk *MikeWonk = Mike->changeToWonk();

	StudentGroup group = { "Math", 3333 };

	group.addStudent(MikeWonk);
	group.addStudent(MartinDefault);
	group.addStudent(AlexActive);

	group.addStudent(Mike);
	group.addStudent(John);
	group.addStudent(William);

	group.addStudent(Anthony);
	group.addStudent(Zor);
	group.addStudent(Alex);

	group.addStudent(Martin);
	group.addStudent(Mark);
	group.addStudent(Evan);

	std::cout << group;

	group.sort();

	std::cout << group;

	group.startExam();

	std::cout << group;

	group.startReExam();

	std::cout << group;

	delete Mike, John, William, Anthony, Zor, Alex, Martin, Mark, Evan;
	delete MikeWonk, MartinDefault, AlexActive;
	std::cin.get();
}