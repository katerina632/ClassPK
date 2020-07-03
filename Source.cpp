#include<iostream>
#include "PK.h"
using namespace std;

int main() {

	PK pk1(2,1);

	PK pk2(2, 2);

	Admin admin;
	Guest guest1;

	pk1.AggregateAdmin(&admin);
	pk1.AggregateGuest(&guest1);

	pk1.Print();
	cout << endl << endl;

	pk2.AggregateAdmin(&admin);
	pk2.AggregateGuest(&guest1);

	pk2.Print();

	
	cout << endl << endl;
	pk2.RemoveGuest();
	pk2.Print();


	system("pause");
	return 0;
}