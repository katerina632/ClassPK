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
	PK(int countRam, int countHardDrives) : countRam(countRam), countHardDrives(countHardDrives)
	{
		ram = new RAM[this->countRam];
		hardDrives = new HardDrive[this->countHardDrives];
		guest = nullptr;
		admin= nullptr;
	}

	void AggregateAdmin(Admin* admin) {
		this->admin = admin;
	}
	bool RemoveAdmin() {
		if (admin != nullptr) {
			admin = nullptr;
			return true;
		}
		else {
			return false;
		}
	}

	void AggregateGuest(Guest* guest) {
		this->guest = guest;
	}
	bool RemoveGuest() {
		if (guest != nullptr) {
			guest = nullptr;
			return true;
		}
		else {
			return false;
		}
	}

	void Print() const {
	
		if (admin != nullptr)
			admin->Print();
		if (guest != nullptr)
			guest-> Print();

		motherboard.Print();
		processor.Print();
		videocard.Print();

		cout << "Characteristics of RAM:" << endl;
		for (int i = 0; i < countRam; i++) {
			cout << i + 1 << ")";
			ram->Print();
		}

		cout << "Characteristics of hard drive:" << endl;
		for (int i = 0; i < countHardDrives; i++) {
			cout << i + 1 << ")";
			hardDrives->Print();
		}		
	}
};

