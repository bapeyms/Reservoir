#include <iostream>
#include "Reservoir.h"
using namespace std;

enum MENU
{
	ADD_RESERVOIR = 1,
	SHOW_ALL_RESERVOIRS,
	VOLUME,
	AREA,
	TYPES_COMPARISON,
	AREA_COMPAROSON,
	OBJ_COPY,
	EXIT = 0
};

int MenuChoice()
{
	int menuChoice;
	cout << "Enter the menu number to perform a desired action" << endl;
	cout << "Number: ";
	cin >> menuChoice;
	cin.ignore(1000, '\n');
	while (menuChoice < 0 || menuChoice >= 7)
	{
		cout << "Enter a number from 0 to 7!" << endl;
		cout << "Number: ";
		cin >> menuChoice;
		cin.ignore(1000, '\n');
	}
	cout << endl;
	return menuChoice;
}

int main()
{
	cout << "--- RESERVOIR PROGRAM ---" << endl << endl;
	Reservoir* allRes = nullptr;
	double* volumeArr = nullptr;
	int allResCount = 0;
	
	while (true)
	{
		cout << "-- MENU --" << endl;
		cout << "1. Add the reservoir" << endl;
		cout << "2. Show all reservoirs" << endl;
		cout << "3. Calculate the volume of the reservoir" << endl;
		cout << "4. Calculate the area of the reservoir" << endl;
		cout << "5. Compare reservoir's types" << endl;
		cout << "6. Compare reservoir's area" << endl;
		cout << "7. Copy the reservoir" << endl;
		cout << "0. Exit" << endl;
		int menuChoice = MenuChoice();
		switch (menuChoice) {
		case ADD_RESERVOIR: {
			cout << "- RESERVOIR ADDITION -" << endl;
			Reservoir* tempRes = new Reservoir[allResCount + 1];
			double* tempVol = new double[allResCount + 1];
			for (int i = 0; i < allResCount; i++)
			{
				tempRes[i] = allRes[i];
				tempVol[i] = volumeArr[i];
			}
			tempRes[allResCount].EnterValues();
			tempVol[allResCount] = -1;

			delete[] allRes;
			delete[] volumeArr;

			allRes = tempRes;
			volumeArr = tempVol;
			allResCount++;

			break;
		}
		case SHOW_ALL_RESERVOIRS: {
			cout << "- RESERVOIR DISPLAY -" << endl;
			if (allResCount == 0)
			{
				cout << "No reservoirs have been added yet! " << endl << endl;
			}
			else
			{
				for (int i = 0; i < allResCount; i++)
				{
					cout << "Reservoir #" << 1 + i << endl;
					allRes[i].PrintValues();
				}
			}
			break;
		}
		case VOLUME: {
			cout << "- RESERVOIR'S VOLUME -" << endl;
			int choice1;
			cout << "Choose the reservoir to calculate the volume: ";
			cin >> choice1;
			cin.ignore(1000, '\n');
			while (choice1 < 0 || choice1 > allResCount)
			{
				cout << "Invalid value! Enter a number from 0 to " << allResCount << "!" << endl;
				cout << "Number: ";
				cin >> choice1;
				cin.ignore(1000, '\n');
			}
			int index1 = choice1 - 1;
			if (volumeArr[index1] < 0)
			{
				volumeArr[index1] = *allRes[index1];
			}
			cout << "Volume of Reservoir #" << choice1 << " = " << volumeArr[index1] << endl;
			break;
		}
		case AREA:
			break;
		case TYPES_COMPARISON:
			break;
		case AREA_COMPAROSON:
			break;
		case OBJ_COPY:
			break;
		case EXIT:
			cout << "Exiting program. Goodbye!" << endl;
			return 0;
		}
	}
}