#include "Reservoir.h"
#include <iostream>
using namespace std;

Reservoir::Reservoir() :reservoirName(nullptr), width(0.0), length(0.0), depth(0.0), reservoirType(NONE) {}
Reservoir::Reservoir(const char* name, double w, double l, double d, ResType type)
{
	reservoirName = new char[strlen(name) + 1];
	strcpy_s(reservoirName, strlen(name) + 1, name);

	width = w;
	length = l;
	depth = d;
	reservoirType = type;
}

Reservoir::Reservoir(const Reservoir& copy)
{
	reservoirName = new char[strlen(copy.reservoirName) + 1];
	strcpy_s(reservoirName, strlen(copy.reservoirName) + 1, copy.reservoirName);

	width = copy.width;
	length = copy.length;
	depth = copy.depth;
	reservoirType = copy.reservoirType;
}
Reservoir& Reservoir::operator=(const Reservoir& copy)
{
	if (this == &copy)
	{
		return *this;
	}
	if (reservoirName != nullptr)
	{
		delete[] reservoirName;
	}
	reservoirName = new char[strlen(copy.reservoirName) + 1];
	strcpy_s(reservoirName, strlen(copy.reservoirName) + 1, copy.reservoirName);

	width = copy.width;
	length = copy.length;
	depth = copy.depth;
	reservoirType = copy.reservoirType;

	return *this;
}
Reservoir::~Reservoir()
{
	delete[] reservoirName;
}

char* Reservoir::GetReservoirName()
{
	return reservoirName;
}
double Reservoir::GetWidth()
{
	return width;
}
double Reservoir::GetLength()
{
	return length;
}
double Reservoir::GetDepth()
{
	return depth;
}
ResType Reservoir::GetReservoirType()
{
	return reservoirType;
}

void Reservoir::SetReservoirName(const char* name)
{
	if (reservoirName != nullptr)
	{
		delete[] reservoirName;
	}
	reservoirName = new char[strlen(name) + 1];
	strcpy_s(reservoirName, strlen(name) + 1, name);
}
void Reservoir::SetWidth(double w)
{
	width = w;
}
void Reservoir::SetLength(double l)
{
	length = l;
}
void Reservoir::SetDepth(double d)
{
	depth = d;
}
void Reservoir::SetReservoirType(ResType type)
{
	reservoirType = type;
}

void Reservoir::EnterValues()
{
	const int N = 256;
	char data[N];

	cout << "Enter a reservoir's name: ";
	cin.getline(data, N);
	reservoirName = new char[strlen(data) + 1];
	strcpy_s(reservoirName, strlen(data) + 1, data);

	cout << "Enter a reservoir's width: ";
	cin >> width;
	cin.ignore(1000, '\n');

	cout << "Enter a reservoir's length: ";
	cin >> length;
	cin.ignore(1000, '\n');

	cout << "Enter a reservoir's depth: ";
	cin >> depth;
	cin.ignore(1000, '\n');

	int tempType;
	cout << "Enter a reservoir's type" << endl;
	cout << "(1 - ocean, 2 - sea" << endl;
	cout << " 3 - river 4 - lake" << endl;
	cout << " 5 - pond, 6 - pool" << endl;
	cout << " 7 - fountain) : ";
	cin >> tempType;
	cin.ignore(1000, '\n');
	while (tempType < 0 || tempType >= 7)
	{
		cout << "Invalid value! Enter a number from 0 to 7!" << endl;
		cout << "Number: ";
		cin >> tempType;
		cin.ignore(1000, '\n');
	}
	reservoirType = static_cast<ResType>(tempType);
	cout << "Reservoir has been successfully added!" << endl << endl;
}
void Reservoir::PrintValues()
{
	cout << "Name: " << reservoirName << endl;
	cout << "Width: " << width << " m" << "\n" <<
		"Length: " << length << " m" << "\n" <<
		"Depth: " << depth << " m" << "\n" <<
		"Type: " << reservoirType <<  endl;
	cout << "(1 - ocean, 2 - sea" << endl;
	cout << " 3 - river 4 - lake" << endl;
	cout << " 5 - pond, 6 - pool" << endl;
	cout << " 7 - fountain)" << endl << endl;
}

double Reservoir::GetVolume()
{
	return width * length * depth;
}
double Reservoir::GetArea() const
{
	return width * length;
}

bool Reservoir::operator==(const Reservoir& second)
{
	if (reservoirType == second.reservoirType)
	{
		return true;
	}
	return false;
}
bool Reservoir::operator!=(const Reservoir& second)
{
	if (reservoirType != second.reservoirType)
	{
		return true;
	}
	return false;
}

bool Reservoir::operator>(const Reservoir& second)
{
	if (GetArea() > second.GetArea())
	{
		return true;
	}
	return false;
}
bool Reservoir::operator<(const Reservoir& second)
{
	if (GetArea() < second.GetArea())
	{
		return true;
	}
	return false;
}



