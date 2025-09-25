#pragma once
class Reservoir
{
	char* name;
	double width;
	double length;
	double depth;

public:
	Reservoir();
	Reservoir(const char* name);

	Reservoir(const Reservoir& copy);
	Reservoir& operator=(const Reservoir& copy);
	~Reservoir();

	double Volume(double w, double l, double d);
	double Area(double w, double l);
	bool operator==(Reservoir& obj);
	bool operator>(Reservoir& obj);
};
