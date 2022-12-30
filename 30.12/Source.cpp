#include "Header.h"

int main()
{
	setlocale(0, "ru");
	Players** arr = new Players * [3];
	arr[0] = new Human(100, 2);
	arr[1] = new Cat(30, 2.5);
	arr[2] = new Robot(50, 1);
	Competition** arr1 = new Competition * [4];
	arr1[0] = new Run(20);
	arr1[1] = new Wall(1);
	arr1[2] = new Run(30);
	arr1[3] = new Wall(2);
	for (int i = 0; i < 3; i++)
	{
		int score = 0;
		bool fail = false;
		for (int j = 0; j < 4; j++)
		{
			if (arr1[j]->TypeCompetition() == "Wall")
			{
				if (arr[i]->GetJump() >= arr1[j]->GetCompetition())
					continue;
				else
					fail = true;
			}
			else
			{
				score += arr1[j]->GetCompetition();
				if (arr[i]->GetDistance() >= score)
					continue;
				else
					fail = true;
			}
			if (fail)
			{
				cout << "Èãðîê " << arr[i]->GetName() << " íå ïðîø¸ë èñïûòàíèå " << arr1[j]->TypeCompetition() << " (èñïûòàíèå ¹" << j + 1 << ")\n";
				if (arr1[j]->TypeCompetition() == "Wall")
				{
					cout << "Èãðîê " << arr[i]->GetName() << " ìîæåò ïðûãíóòü â âûñîòó " << arr[i]->GetJump() << " ì, à âûñîòà ñòåíû " << arr1[j]->GetCompetition()
						<< " ì\n\n";
				}
				else
				{
					cout << "Èãðîê " << arr[i]->GetName() << " ìîæåò ïðîáåæàòü " << arr[i]->GetDistance() << " êì, à îáùàÿ äèñòàíèÿ ýòîãî èñïûòàíèÿ " << score
						<< " êì\n\n";
				}
			}
		}
		if (!fail)
			cout << "Èãðîê " << arr[i]->GetName() << " ïðîø¸ë âñå èñïûòàíèÿ\n\n";
	}
}