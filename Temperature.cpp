// Temperatura2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
using namespace std;

class Stad { // Base class
public:
	string Name;
	int Temp;
public: //Constructor
	Stad() {} //27 junio
	Stad(string stad, int temp) {
		Name = stad;
		Temp = temp;
	}

	string GetName() { 
		cout << "Ange stadens name: ";
		cin >> Name;
		return Name;
	}
	int GetTemp() {
		int tempTemporal;
		cout << "Ange temperatur för " << Name << ": " << endl;
		cin >> tempTemporal;
		while (tempTemporal <= -60 || tempTemporal >= 60) {
			cout << "Invalid temperature. Ange temperatur för " << Name << ": " << endl;
			cin >> tempTemporal;
		}
		if (tempTemporal >= -60 && tempTemporal <= 60) {
			Temp = tempTemporal;
		}
		return Temp;
	}
	string ToString() {
		string tempString = to_string(Temp);
		string stadString = Name + " " + tempString;
		return stadString;
	}
};

void getInfo(Stad stader[], int n) {
	for (int i = 0; i <= 3; i++) { //Skriv ut alla elementer i array
		cout << stader[i].Name << " " << stader[i].Temp << endl;
	}
//	cout << "Stad: " << Name << endl;
	//cout << "Temperature: " << Temp << endl;
}
void bubblesort(Stad stader[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (stader[j].Temp > stader[j + 1].Temp) {
					Stad temp;
					temp = stader[j];
					stader[j] = stader[j + 1];
					stader[j + 1] = temp;
			}
		}
	}
}
int linSok(Stad stader[], int n, int soktemp) {
	for (int i = 0; i < n; i++) {
		if (soktemp == stader[i].Temp) {
			return i;
		}
	}
	return -1;
}

int binSok(Stad stader[], int low, int high, int soktemp) {
	
	if (low > high) {
		return -1;
	}
	int mid; 
	mid = (low + high) / 2;

	if (stader[mid].Temp == soktemp) {
		return mid;
	}
	else if (soktemp > stader[mid].Temp) {
		return binSok(stader, mid + 1, high, soktemp);
	}
	else {
		return binSok(stader, low, mid - 1, soktemp);
	}
	return -1;
}

string hogstTemp(Stad stader[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (stader[j].Temp < stader[j + 1].Temp) {
				Stad temp;
				temp = stader[j];
				stader[j] = stader[j + 1];
				stader[j + 1] = temp;
			}
		}
	}
	return stader[0].Name;
}
string lagstTemp(Stad stader[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (stader[j].Temp > stader[j + 1].Temp) {
				Stad temp;
				temp = stader[j];
				stader[j] = stader[j + 1];
				stader[j + 1] = temp;
			}
		}
	}
	return stader[0].Name;
}

int main()
{

	Stad stader[4];

	stader[0].GetName();
	stader[0].GetTemp();

	stader[1].GetName();
	stader[1].GetTemp();

	stader[2].GetName();
	stader[2].GetTemp();

	stader[3].GetName();
	stader[3].GetTemp();

	//Utifall att en vill kolla på array. 
	/*cout << "List av städer och deras temperaturer: " << endl;
	GetInfo(stader, 4);*/

	bubblesort(stader, 4);

	cout << "Sorterade lista av städer: " << endl;
	cout << stader[0].ToString() << endl;
	cout << stader[1].ToString() << endl;
	cout << stader[2].ToString() << endl;
	cout << stader[3].ToString() << endl;

	int soktemp;
	cout << "(LINJÄR SÖKNING)" << endl << "Vilken temperatur söker du ? : " << endl;
	cin >> soktemp;

	int result = linSok(stader, 4, soktemp);
	if (result >= 0) {
		cout << "Temperaturen " << stader[result].Temp << " grader finns i elementet med index " << result << "." << endl;
	}
	else {
		cout << "Temperaturen " << soktemp << " grader hittades inte." << endl << endl;
	}



	int soktemp2;
	cout << "(BINÄR SÖKNING)" << endl << "Vilken temperatur söker du ? : " << endl;
	cin >> soktemp2;

	int result3 = binSok(stader,0, 4, soktemp2);
	if (result3 >= 0) {
		cout << "Temperaturen "  << stader[result3].Temp << " grader finns i elementet med index "  << result3 << ", dvs staden: " << stader[result3].Name << endl;
	}
	else {
		cout << "Temperaturen " << soktemp2 << " grader hittades inte." << endl;
	}

	//För att visa hösgta och lägsta temperaturerna

	string result1 = hogstTemp(stader, 4);
	cout << endl << "Staden med den högsta temperaturen är " << result1 << endl;
	string result2 = lagstTemp(stader, 4);
	cout << endl << "Staden med den lägsta temperaturen är " << result2 << endl;


	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
