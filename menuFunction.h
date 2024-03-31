#pragma once
#include <iostream>
using namespace std;
void pogramMenu()
{

	//system("cls"); //�������� ��������
	setlocale(LC_ALL, "");
	cout << "����� ����������" << endl;
	int apartmentQuantity = 0;
	Apartment* newBuilding = new Apartment[apartmentQuantity];
	int sizeListOfResidents = 0;
	Sitizen* resList = new Sitizen[sizeListOfResidents];
	bool progWork = true;
	int choice;
	while (progWork)
	{
		printMenu1();
		cout << "Enter comand!: " << endl;
		cin >> choice;
		system("cls");
		switch (choice)
		{
		case 1:
		{
			//�������� ��������
			addNewApartment(newBuilding, apartmentQuantity);
			break;
		}
		case 2:
		{
			//������� �������� 
			int apartmentID;
			printAllApart(newBuilding, apartmentQuantity);
			cout << "Enter ID of apartment to delete, or '0' to cancel" << endl;
			cin >> apartmentID;
			if (apartmentID > 0 && apartmentID < apartmentQuantity)
			{
				deleteApartment(newBuilding, apartmentQuantity, apartmentID);
			}
			else
			{
				cout << "There is no such apartment in the house!" << endl;
			}
			break;
		}
		case 3:
		{
			//�������� ������
			addNewSitizen(resList, sizeListOfResidents);
			system("cls");
			break;
		}
		case 4:
		{
			//������� ������ �� ID
			if (sizeListOfResidents > 0)
			{
				printAllSit(resList, sizeListOfResidents);
				int delSitID;
				cout << " Enter inhabitan ID to delete:  " << endl;
				cin >> delSitID;
				deleteSitizen(resList, sizeListOfResidents, delSitID);
				if (delSitID > 0 && delSitID < sizeListOfResidents)
				{
					deleteSitizen(resList, sizeListOfResidents, delSitID);
				}
				else
				{
					cout << "No such resident exists!" << endl;
				}
			}
			else
			{
				cout << "There are no residents at the moment!" << endl;
			}
			system("cls");
			break;
		}
		case 5:
		{
			//��������� ������ �� ���������
			int addApID, addSitID;
			printAllApart(newBuilding, apartmentQuantity);
			cout << "Enter ID of apartment" << endl;
			cin >> addApID;
			system("cls");
			printResidentWithoutRegistration(resList, sizeListOfResidents);
			cout << "Enter ID of sitizen" << endl;
			cin >> addSitID;
			system("cls");
			addApartmentResident(newBuilding, apartmentQuantity, resList, sizeListOfResidents, addApID, addSitID);
			system("cls");
			break;
		}
		case 6:
		{
			//�������� ������ � ��������
			int dellSitID;
			cout << "List resident with registration" << endl;
			printResidentWithRegistration(resList, sizeListOfResidents);
			cout << "Enter ID of sitizen" << endl;
			cin >> dellSitID;
			deleteApartmentResident(newBuilding, apartmentQuantity, resList, sizeListOfResidents, dellSitID);

			break;
		}
		case 7:
		{
			//������ � �����������

			system("cls");
			printMenu2();
			int choice2;
			cout << "Enter comand!: " << endl;
			cin >> choice2;
			switch (choice2)
			{
			case 1:
			{
				//��������� ���������� � ����
				writeToFile(newBuilding, apartmentQuantity, resList, sizeListOfResidents);
				break;
			}
			case 2:
			{
				//��������� ���������� � �����
				readFromFile(newBuilding, apartmentQuantity, resList, sizeListOfResidents);
				break;
			}
			case 3:
			{
				//������� ���� ������ �������
				printAllApart(newBuilding, apartmentQuantity);
				break;
			}
			case 4:
			{
				//������� ���� ������ �������
				printAllSit(resList, sizeListOfResidents);
				break;
			}
			case 5:
			{
				//������� ���������� �� ��������
				int apartNum;
				cout << "Eenter the apartment number to receive information: " << endl;
				cin >> apartNum;
				printInfoApartment(newBuilding, apartmentQuantity, apartNum);
				break;
			}
			case 6:
			{
				//���������� ��� �������� �� �����
				int florNum;
				cout << "Eenter flor number to receive information: " << endl;
				cin >> florNum;
				printFlorInfo(newBuilding, apartmentQuantity, florNum);
				break;
			}
			case 7:
			{
				//���������� ��� ���������� ��������(�� ���������� ������)
				int numOfRoom;
				cout << "Eenter number of rooms in apartment: " << endl;
				cin >> numOfRoom;
				for (int i = 0; i < apartmentQuantity; i++)
				{
					if (newBuilding[i].numOfRooms == numOfRoom)
					{
						printApart(newBuilding[i], i);
					}
				}
				break;
			}
			default:
			{
				system("cls");
				break;
			}
			}
			break;
		}
		case 8:
		{
			progWork = false;
			system("cls");
			break;
		}
		default:
		{
			progWork = false;
			system("cls");
			break;
		}
		}
	}
}