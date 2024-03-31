#pragma once
#include <iostream>
using namespace std;
// —труктура жител€ с такими рапаметрами им€/ фамили€/ возаст/ и прв€зка к квартире
struct Sitizen
{
	char name[20];
	char surname[20];
	int age;
	int apartNum;
};
// —труктура квартиры с такими параметрами этаж/номер квартиры/количество комнат/ количество жильцов/ жильцы
struct Apartment
{
	int florNum;
	int apartmentNum;
	int numOfRooms;
	int numRes;
	Sitizen* inhabitant;
};

// ‘ункци€ поиска квартиры по номету - возвращает 1 если есть
bool apartmentSearch(Apartment*& ap, int apSize, int apNum)
{
	for (int i = 0; i < apSize; i++)
	{
		if (ap[i].apartmentNum == apNum && apSize == 0)
		{
			return true;
		}
	}
	return false;
}
// функци€ заполнени€ данных о квартире 
void fillNewApartment(Apartment* ap, int size)
{
	bool check;
	do
	{
		check = false;
		cout << "Enter num of apartment" << endl;
		cin >> ap[size].apartmentNum;
		for (int i = 0; i < size; i++)
		{
			if (ap[size].apartmentNum == ap[i].apartmentNum)
			{
				cout << "An apartment with this number already exists!!" << endl;
				check = true;
			}
		}
	} while (check);
	cout << "Enter num of flor" << endl;
	cin >> ap[size].florNum;
	cout << "Enter number of rooms" << endl;
	cin >> ap[size ].numOfRooms;
	ap[size].numRes = 0;
	ap[size].inhabitant = new Sitizen[ap[size].numRes];
}
// заполнение данных жител€
void fillNewSitizen(Sitizen*& sit, int num)
{
	cout << "Enter sitizen Name" << endl;
	cin >> sit[num].name;
	cout << "Enter sitizen Surname" << endl;
	cin >> sit[num].surname;
	cout << "Enter sitizen Age" << endl;
	cin >> sit[num].age;
	sit[num].apartNum = 0;
}
// добавление новой квартиры
void addNewApartment(Apartment*& ap, int& num)
{
	Apartment* newAp = new Apartment[num + 1];
	for (int i = 0; i < num; i++)
	{
		newAp[i] = ap[i];
	}
	fillNewApartment(newAp, num);
	++num;
	delete[] ap;
	ap = newAp;
}
// добавление нового жител€
void addNewSitizen(Sitizen*& sit, int& quantity)
{
	Sitizen* newSit = new Sitizen[quantity + 1];
	for (int i = 0; i < quantity; i++)
	{
		newSit[i] = sit[i];
	}
	fillNewSitizen(newSit,quantity);
	++quantity;
	delete[] sit;
	sit = newSit;
}
// удаление квартиры
void deleteApartment(Apartment*& ap, int& num, int apID)
{
	Apartment* newAp = new Apartment[num - 1];
	for (int i = 0, j = 0; i < num; i++)
	{
		if (i != apID-1)
		{
			newAp[j] = ap[i];
			j++;
		}
	}
	--num;
	delete[] ap;
	ap = newAp;

}
// ”даление жител€ по ID
void deleteSitizen(Sitizen*& sit, int& num, int delNum)
{
	Sitizen* newSit = new Sitizen[num - 1];
	for (int i = 0, j = 0; i < num; i++)
	{
		if (i != delNum-1) 
		{
			newSit[j] = sit[i];
			j++;
		}
	}
	--num;
	delete[] sit;
	sit = newSit;
}
// ѕрив€зка (прописка) жител€ в квартиру
void addApartmentResident(Apartment*& apart, int apNum, Sitizen*& sit, int sitNum, int addApNum, int addSitNum)
{
	Sitizen* newSit = new Sitizen[apart[addApNum - 1].numRes + 1];
	for (int i = 0; i < apart[addApNum - 1].numRes + 1; i++)
	{
		newSit[i] = apart[addApNum - 1].inhabitant[i];
	}
	newSit[apart[addApNum - 1].numRes] = sit[addSitNum - 1];
	sit[addSitNum - 1].apartNum = apart[addApNum - 1].apartmentNum;
	apart[addApNum - 1].numRes++;
	delete[]  apart[addApNum - 1].inhabitant; 
	apart[addApNum - 1].inhabitant = newSit; 
}

// ¬ыписать жильца
void deleteApartmentResident(Apartment*& apart, int apNum, Sitizen*& sit, int sitNum, int delSitID)
{
	for (int i = 0; i < apNum; i++)
	{
		if (sit[delSitID-1].apartNum == apart[i].apartmentNum)
		{
			int newSize = apart[i].numRes - 1;
			Sitizen* newSit = new Sitizen[newSize];
			for (int j = 0,k = 0; j < newSize; j++)
			{
				if (apart[i].inhabitant[j].name == sit[delSitID-1].name
					&& apart[i].inhabitant[j].surname == sit[delSitID-1].surname 
					&& apart[i].inhabitant[j].age == sit[delSitID-1].age)
				{
					j++;
				}
				else
				{
					newSit[k] = apart[i].inhabitant[j];
					k++;
				}
			}
			apart[i].numRes--;
			sit[delSitID - 1].apartNum=0;
			delete[] apart[i].inhabitant;
			apart[i].inhabitant = newSit;
			i = apNum;
		}
	}
}