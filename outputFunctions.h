#pragma once
#include <iostream>
using namespace std;

// Печать данных про квартиру
void printApart(Apartment& ap, int num)
{
	cout << "==================================" << endl;
	cout << "Apartment ID: " << num + 1 << endl;
	cout << "Num of apartment: " << ap.apartmentNum << endl;
	cout << "Num of flor: " << ap.florNum << endl;
	cout << "Num of rooms: " << ap.numOfRooms << endl;
	cout << "Num of inhabitants: " << ap.numRes << endl;
	cout << "==================================" << endl;
	cout << endl;
}
// Печать данных про квартиры
void printAllApart(Apartment*& ap, int num)
{
	for (int i = 0; i < num; i++)
	{
		printApart(ap[i], i);
	}
}
// Печать всех данных про жильца
void printSit(Sitizen& sit, int num)
{
	cout << "==================================" << endl;
	cout << "Inhabitant ID :" << num + 1 << endl;
	cout << "Inhabitan Name: " << sit.name << endl;
	cout << "Inhabitan Surname:  " << sit.surname << endl;
	cout << "Inhabitan Age: " << sit.age << endl;
	cout << "==================================" << endl;
}
// Печать всех данных про жильцов
void printAllSit(Sitizen*& sit, int num)
{
	for (int i = 0; i < num; i++)
	{
		printSit(sit[i], i);
		cout << endl;
	}
}
// список жителей с пропиской
void printResidentWithRegistration(Sitizen*& sit, int num)
{
	for (int i = 0; i < num; i++)
	{
		if (sit[i].apartNum != 0)
		{
			printSit(sit[i], i);
			cout << endl;
		}
	}
}
// список жителей без прописки
void printResidentWithoutRegistration(Sitizen*& sit, int num)
{
	for (int i = 0; i < num; i++)
	{
		if (sit[i].apartNum == 0)
		{
			printSit(sit[i], i);
			cout << endl;
		}
	}
}
// печать всей информации про квартиру + жильцы
void printInfoApartment(Apartment*& ap, int num, int apNum)
{
	for (int i = 0; i < num; i++)
	{
		if (ap[i].apartmentNum == apNum)
		{
			cout << "==================================" << endl;
			cout << "Num of apartment: " << ap[i].apartmentNum << endl;
			cout << "Num of flor: " << ap[i].florNum << endl;
			cout << "Num of rooms: " << ap[i].numOfRooms << endl;
			cout << "Num of inhabitants: " << ap[i].numRes << endl;
			if (ap[i].numRes > 0)
			{
				for (int j = 0; j < ap[i].numRes; j++)
				{
					cout << "___________________" << endl;
					cout << "resident Name : " << ap[i].inhabitant[j].name << endl;
					cout << "resident Surname : " << ap[i].inhabitant[j].surname << endl;
					cout << "resident Age : " << ap[i].inhabitant[j].age << endl;
					cout << "___________________" << endl;
					cin.ignore(20, '\n');
				}
			}
			cout << "==================================" << endl;
		}
	}
}
// печать всей информации по этажу
void printFlorInfo(Apartment*& ap, int num, int florNum)
{
	for (int i = 0; i < num; i++)
	{
		if (ap[i].florNum == florNum)
		{
			cout << "==================================" << endl;
			cout << "Num of apartment: " << ap[i].apartmentNum << endl;
			cout << "Num of flor: " << ap[i].florNum << endl;
			cout << "Num of rooms: " << ap[i].numOfRooms << endl;
			cout << "Num of inhabitants: " << ap[i].numRes << endl;
			cout << "==================================" << endl;
			if (ap[i].numRes > 0)
			{
				for (int j = 0; j < ap[i].numRes; j++)
				{
					cout << "==================================" << endl;
					cout << "resident Name : " << ap[i].inhabitant[j].name << endl;
					cout << "resident Surname : " << ap[i].inhabitant[j].surname << endl;
					cout << "resident Age : " << ap[i].inhabitant[j].age << endl;
					cout << "==================================" << endl;
					cin.ignore(20, '\n');
				}
			}
		}
	}
}