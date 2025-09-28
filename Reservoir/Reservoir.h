#pragma once

enum ResType
{
	OCEAN = 1,
	SEA,
	RIVER,
	LAKE,
	POND,
	POOL,
	FOUNTAIN,
	NONE = 0
};

class Reservoir
{
	char* reservoirName;
	double width, length, depth;
	ResType reservoirType;
public:
	Reservoir();
	Reservoir(const char* name, double w, double l, double d, ResType type);

	Reservoir(const Reservoir& copy);
	Reservoir& operator=(const Reservoir& copy);
	~Reservoir();

	char* GetReservoirName();
	double GetWidth();
	double GetLength();
	double GetDepth();
	ResType GetReservoirType();

	void SetReservoirName(const char* name);
	void SetWidth(double w);
	void SetLength(double l);
	void SetDepth(double d);
	void SetReservoirType(ResType type);

	void EnterValues();
	void PrintValues();

	double GetVolume();
	double GetArea() const;

	bool operator==(const Reservoir& second);
	bool operator!=(const Reservoir& second);

	bool operator>(const Reservoir& second);
	bool operator<(const Reservoir& second);
};