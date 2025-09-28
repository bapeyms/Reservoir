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
	AREA_COMPAR²SON,
	EXIT = 0
};

int MenuChoice()
{
	int menuChoice;
	cout << "Enter the menu number to perform a desired action" << endl;
	cout << "Number: ";
	cin >> menuChoice;
	cin.ignore(1000, '\n');
	while (menuChoice < 0 || menuChoice > 6)
	{
		cout << "Enter a number from 0 to 6!" << endl;
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
	double* areaArr = nullptr;
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
		cout << "0. Exit" << endl;
		int menuChoice = MenuChoice();
		switch (menuChoice) {
		case ADD_RESERVOIR: {
			cout << "- RESERVOIR ADDITION -" << endl;
			Reservoir* tempRes = new Reservoir[allResCount + 1];
			double* tempVol = new double[allResCount + 1];
			double* tempArea = new double[allResCount + 1];
			for (int i = 0; i < allResCount; i++)
			{
				tempRes[i] = allRes[i];
				tempVol[i] = volumeArr[i];
				tempArea[i] = areaArr[i];
			}
			tempRes[allResCount].EnterValues();
			tempVol[allResCount] = -1;
			tempArea[allResCount] = -1;

			delete[] allRes;
			delete[] volumeArr;
			delete[] areaArr;

			allRes = tempRes;
			volumeArr = tempVol;
			areaArr = tempArea;
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
			if (allResCount == 0)
			{
				cout << "No reservoirs have been added yet! " << endl << endl;
			}
			else
			{
				int choice1;
				cout << "Choose the reservoir to calculate the volume: ";
				cin >> choice1;
				cin.ignore(1000, '\n');
				while (choice1 < 0 || choice1 > allResCount)
				{
					cout << "Invalid value! Enter a number from 1 to " << allResCount << "!" << endl;
					cout << "Number: ";
					cin >> choice1;
					cin.ignore(1000, '\n');
				}
				int index1 = choice1 - 1;
				if (volumeArr[index1] < 0)
				{
					volumeArr[index1] = allRes[index1].GetVolume();
				}
				cout << "Volume of Reservoir " << allRes[index1].GetReservoirName() << " = " << volumeArr[index1] << endl;
			}
			break;
		}
		case AREA: {
			cout << "- RESERVOIR'S AREA -" << endl;
			if (allResCount == 0)
			{
				cout << "No reservoirs have been added yet! " << endl << endl;
			}
			else
			{
				int choice2;
				cout << "Choose the reservoir to calculate the area: ";
				cin >> choice2;
				cin.ignore(1000, '\n');
				while (choice2 < 0 || choice2 > allResCount)
				{
					cout << "Invalid value! Enter a number from 1 to " << allResCount << "!" << endl;
					cout << "Number: ";
					cin >> choice2;
					cin.ignore(1000, '\n');
				}
				int index2 = choice2 - 1;
				if (areaArr[index2] < 0)
				{
					areaArr[index2] = allRes[index2].GetArea();
				}
				cout << "Area of Reservoir " << allRes[index2].GetReservoirName() << " = " << areaArr[index2] << endl;
			}
			break;
		}
		case TYPES_COMPARISON:
		{
			cout << "- RESERVOIR'S TYPES COMPARISON -" << endl;
			if (allResCount < 2)
			{
				cout << "Not enough reservoirs to compare! " << endl << endl;
			}
			else
			{
				int typesComp1;
				cout << "Choose the first reservoir to compare a type: ";
				cin >> typesComp1;
				cin.ignore(1000, '\n');
				while (typesComp1 < 1 || typesComp1 > allResCount)
				{
					cout << "Invalid value! Enter a number from 1 to " << allResCount << "!" << endl;
					cout << "Number: ";
					cin >> typesComp1;
					cin.ignore(1000, '\n');
				}
				int typesComp2;
				cout << "Choose the second reservoir to compare a type: ";
				cin >> typesComp2;
				cin.ignore(1000, '\n');
				while (typesComp2 < 1 || typesComp2 > allResCount)
				{
					cout << "Invalid value! Enter a number from 0 to " << allResCount << "!" << endl;
					cout << "Number: ";
					cin >> typesComp2;
					cin.ignore(1000, '\n');
				}
				while (typesComp1 == typesComp2)
				{
					cout << "Invalid value! Identical reservoir were choosen!" << 
						"Enter any number for the second reservoir, except for " << typesComp1 << "!" << endl;
					cout << "Number: ";
					cin >> typesComp2;
					cin.ignore(1000, '\n');
				}
				cout << "Type comparison result: ";
				if (allRes[typesComp1 - 1] == allRes[typesComp2 - 1])
				{
					cout << allRes[typesComp1 - 1].GetReservoirName() << " == " <<
						allRes[typesComp2 - 1].GetReservoirName();
					cout << endl << endl;
				}
				else if (allRes[typesComp1 - 1] != allRes[typesComp2 - 1])
				{
					cout << allRes[typesComp1 - 1].GetReservoirName() << " != " <<
						allRes[typesComp2 - 1].GetReservoirName();
					cout << endl << endl;
				}
			}
			break;
		}
		case AREA_COMPAR²SON: {
			cout << "- RESERVOIR'S AREA COMPARISON -" << endl;
			int areaCount = 0;
			for (int i = 0; i < allResCount; i++)
			{
				if (areaArr[i] != -1)
				{
					areaCount++;
				}
			}

			if (areaCount < 2)
			{
				cout << "Not enough reservoirs' areas to compare! " << endl << endl;
			}
			else
			{
				int areaComp1;
				cout << "Choose the first reservoir to compare an area: ";
				cin >> areaComp1;
				cin.ignore(1000, '\n');
				while (areaComp1 < 1 || areaComp1 > allResCount)
				{
					cout << "Invalid value! Enter a number from 1 to " << allResCount << "!" << endl;
					cout << "Number: ";
					cin >> areaComp1;
					cin.ignore(1000, '\n');
				}
				int areaComp2;
				cout << "Choose the second reservoir to compare an area: ";
				cin >> areaComp2;
				cin.ignore(1000, '\n');
				while (areaComp2 < 1 || areaComp2 > allResCount)
				{
					cout << "Invalid value! Enter a number from 0 to " << allResCount << "!" << endl;
					cout << "Number: ";
					cin >> areaComp2;
					cin.ignore(1000, '\n');
				}
				while (areaComp1 == areaComp2)
				{
					cout << "Invalid value! Identical reservoir were choosen!" <<
						"Enter any number for the second reservoir, except for " << areaComp1 << "!" << endl;
					cout << "Number: ";
					cin >> areaComp2;
					cin.ignore(1000, '\n');
				}
				cout << "Area comparison result: ";
				if (areaArr[areaComp1 - 1] > areaArr[areaComp2 - 1])
				{
					cout << allRes[areaComp1 - 1].GetReservoirName() << " (" << areaArr[areaComp1 - 1] << ") > "
						<< allRes[areaComp2 - 1].GetReservoirName() << " (" << areaArr[areaComp2 - 1] << ")";
					cout << endl << endl;
				}
				else if (areaArr[areaComp1 - 1] < areaArr[areaComp2 - 1])
				{
					cout << allRes[areaComp1 - 1].GetReservoirName() << " (" << areaArr[areaComp1 - 1] << ") < "
						<< allRes[areaComp2 - 1].GetReservoirName() << " (" << areaArr[areaComp2 - 1] << ")";
					cout << endl << endl;
				}
				else
				{
					cout << allRes[areaComp1 - 1].GetReservoirName() << " (" << areaArr[areaComp1 - 1] << ") == "
						<< allRes[areaComp2 - 1].GetReservoirName() << " (" << areaArr[areaComp2 - 1] << ")";
					cout << endl << endl;
				}
			}
			break;
		}
		case EXIT:
			cout << "Exiting program. Goodbye!" << endl;
			return 0;
		}
	}
}