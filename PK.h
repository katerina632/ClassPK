#pragma once
#include <string>
#include<iostream>
using namespace std;


class Motherboard {
private:
	string chipset;
	string connectorType;
	string formFactor;

public:
	Motherboard();
	Motherboard(string chipset, string connectorType, string formFactor);
	
	void Print() const;
	
};

class RAM {
private:
	int capacity;
	string type;
	float supplyVoltage;
public:
	RAM();
	RAM(int capacity, string type, float voltage);
	
	void Print() const;
};

class Processor {
private:
	int bitRate;
	int clockFrequency;
	int numberOfCores;

public:
	Processor();
	Processor(int bitRate, int frequency, int numCores);
	
	void Print() const;	
};


class HardDrive {
private:
	int capacity;
	float formFactor;
	int dataTransferRate;
public:
	HardDrive();
	HardDrive(int cap, float formFactor, int dataTransferRate);

	void Print() const;
	
};

class Videocard {
private:
	int memoryFrequency;
	int memory;
	string graphicsChip;
		
public:
	Videocard();
	Videocard(int frequency,int  memory, string chip);
	
	void Print() const;

};

class Guest {
private:
	string name;
	bool accessToFiles;
public:
	Guest();
	Guest(string name, bool access);
	
	void Print() const;

};

class Admin {
private:
	string name;
	string specialization;

public:
	Admin();
	Admin(string name, string specialization);

	void Print() const;

};

class PK
{
private:
	Motherboard motherboard;
	RAM* ram;
	int countRam;
	Processor processor;
	HardDrive* hardDrives;
	int countHardDrives;
	Videocard videocard;

	Guest* guest;
	Admin* admin;
public:
	PK(int countRam, int countHardDrives);

	~PK();

	void AggregateAdmin(Admin* admin);

	bool RemoveAdmin();

	void AggregateGuest(Guest* guest);

	bool RemoveGuest();

	void Print() const;	
		
};

