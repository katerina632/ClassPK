#include "PK.h"
#include<iostream>
using namespace std;

Motherboard::Motherboard()
	: chipset("Intel"), connectorType("Socket 1151"), formFactor("MicroATX") {}

Motherboard::Motherboard(string chipset, string connectorType, string formFactor)
	: chipset(chipset), connectorType(connectorType), formFactor(formFactor) {}

void Motherboard::Print() const
{
	cout << "Characteristics of motherboard:" << endl;
	cout << "Chipset - " << chipset << endl;
	cout << "Connector type - " << connectorType << endl;
	cout << "Form factor - " << formFactor << endl;
	cout << "----------------------------------" << endl;
}

RAM::RAM() : capacity(2), type("DDR2"), supplyVoltage(1.8) {}

RAM::RAM(int capacity, string type, float voltage)
	: capacity(capacity), type(type), supplyVoltage(voltage) {}

void RAM::Print() const
{
	cout << "Capacity - " << capacity <<" GB"<< endl;
	cout << "Type - " << type << endl;
	cout << "Supply voltage - " << supplyVoltage <<" V"<< endl;
	cout << "----------------------------------" << endl;
}

Processor::Processor() : bitRate(32), clockFrequency(3), numberOfCores(2) {}

Processor::Processor(int bitRate, int frequency, int numCores)
	: bitRate(bitRate), clockFrequency(frequency), numberOfCores(numCores) {}




void Processor::Print() const
{
	cout << "Characteristics of processor:" << endl;
	cout << "Bit rate - " << bitRate << " bit" << endl;
	cout << "Clock frequency - " << clockFrequency <<" GHz"<< endl;
	cout << "Number of cores - " << numberOfCores << endl;
	cout << "----------------------------------" << endl;
}

HardDrive::HardDrive() : capacity(500), formFactor(3.5), dataTransferRate(194) {}

HardDrive::HardDrive(int cap, float formFactor, int dataTransferRate)
	: capacity(cap), formFactor(formFactor), dataTransferRate(dataTransferRate) {}

void HardDrive::Print() const
{
	cout << "Capacity - " << capacity << " GB" << endl;
	cout << "Form factor - " << formFactor << " inch" << endl;
	cout << "Data transfer rate - " << dataTransferRate << " MB/sec"<< endl;
	cout << "----------------------------------" << endl;
}

Videocard::Videocard()
	: memoryFrequency(6008), memory(1), graphicsChip("GeForce") {}

Videocard::Videocard(int frequency, int memory, string chip)
	: memoryFrequency(frequency), memory(memory), graphicsChip(chip) {}

void Videocard::Print() const
{
	cout << "Characteristics of videocard:" << endl;
	cout << "Memory frequency - " << memoryFrequency << " MHz" << endl;
	cout << "Memory - " << memory << " GB" << endl;
	cout << "Graphics chip - " << graphicsChip  << endl;
	cout << "----------------------------------" << endl;
}

Guest::Guest() : name("Guest"), accessToFiles(false) {}

Guest::Guest(string name, bool access) : name(name), accessToFiles(access) {}


void Guest::Print() const
{
	cout << "Guest name - " << name << endl;
	cout << "Access to files - " << accessToFiles << endl;
	cout << endl;

}

Admin::Admin() : name("Admin"), specialization("System administrator") {}

Admin::Admin(string name, string specialization)
	: name(name), specialization(specialization) {}

void Admin::Print() const
{
	cout << "Admin name - " << name << endl;
	cout << "Admin specialization - " << specialization << endl;
	cout << endl;
}

PK::PK(int countRam, int countHardDrives) : countRam(countRam), countHardDrives(countHardDrives)
{
	ram = new RAM[this->countRam];
	hardDrives = new HardDrive[this->countHardDrives];
	guest = nullptr;
	admin = nullptr;
}

PK::~PK()
{
	if (hardDrives != nullptr)
		delete[] hardDrives;
	if (ram != nullptr)
		delete[] ram;
}

void PK::AggregateAdmin(Admin* admin)
{
	this->admin = admin;
}

bool PK::RemoveAdmin()
{
	if (admin != nullptr) {
		admin = nullptr;
		return true;
	}
	else {
		return false;
	}
}

void PK::AggregateGuest(Guest* guest)
{
	this->guest = guest;
}

bool PK::RemoveGuest()
{
	if (guest != nullptr) {
		guest = nullptr;
		return true;
	}
	else {
		return false;
	}
}

void PK::Print() const
{
	if (admin != nullptr)
		admin->Print();
	if (guest != nullptr)
		guest->Print();

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
}
