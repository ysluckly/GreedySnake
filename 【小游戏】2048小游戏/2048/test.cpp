
#include "2048.h"

int map[4][4] = { 0 };

int main()
{

	Add(0);
	while (1)
	{
		system("cls");
		Print();
		Move();

	}

	return 0;
}
