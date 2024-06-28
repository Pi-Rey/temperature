
#include <iostream>
#include <string>
using namespace std;

class City { // Base class
public:
	string Name;
	int Temp;
public: //Constructor
	City() {} //27 junio
	City(string city, int temp) {
		Name = city;
		Temp = temp;
	}

	string GetName() { 
		cout << "Enter city's name: ";
		cin >> Name;
		return Name;
	}
	int GetTemp() {
		int tempTemporal;
		cout << "Enter temperature for " << Name << ": " << endl;
		cin >> tempTemporal;
        
		while (tempTemporal <= -60 || tempTemporal >= 60) {
			cout << "Invalid temperature. Enter temperature for " << Name << ": " << endl;
			cin >> tempTemporal;
		}
		if (tempTemporal >= -60 && tempTemporal <= 60) {
			Temp = tempTemporal;
		}
		return Temp;
	}
	string ToString() {
		string tempString = to_string(Temp);
		string cityString = Name + " " + tempString;
		return cityString;
	}
};

void getInfo(City cities[]) {
	for (int i = 0; i <= 3; i++) { //Skriv ut alla elementer i array
		cout << cities[i].Name << " " << cities[i].Temp << endl;
	}
//	cout << "Stad: " << Name << endl;
	//cout << "Temperature: " << Temp << endl;
}
void bubblesort(City cities[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (cities[j].Temp > cities[j + 1].Temp) {
					City temp;
					temp = cities[j];
					cities[j] = cities[j + 1];
					cities[j + 1] = temp;
			}
		}
	}
}
int linSearch(City cities[], int n, int searchtemp) {
	for (int i = 0; i < n; i++) {
		if (searchtemp == cities[i].Temp) {
			return i;
		}
	}
	return -1;
}

int binSearch(City cities[], int low, int high, int searchtemp) {
	
	if (low > high) {
		return -1;
	}
	int mid; 
	mid = (low + high) / 2;

	if (cities[mid].Temp == searchtemp) {
		return mid;
	}
	else if (searchtemp > cities[mid].Temp) {
		return binSearch(cities, mid + 1, high, searchtemp);
	}
	else {
		return binSearch(cities, low, mid - 1, searchtemp);
	}
	return -1;
}

string hogstTemp(City cities[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (cities[j].Temp < cities[j + 1].Temp) {
				City temp;
				temp = cities[j];
				cities[j] = cities[j + 1];
				cities[j + 1] = temp;
			}
		}
	}
	return cities[0].Name;
}
string lagstTemp(City cities[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (cities[j].Temp > cities[j + 1].Temp) {
				City temp;
				temp = cities[j];
				cities[j] = cities[j + 1];
				cities[j + 1] = temp;
			}
		}
	}
	return cities[0].Name;
}

int main()
{

	City cities[4];

	cities[0].GetName();
	cities[0].GetTemp();

	cities[1].GetName();
	cities[1].GetTemp();

	cities[2].GetName();
	cities[2].GetTemp();

	cities[3].GetName();
	cities[3].GetTemp();

	//Utifall att en vill kolla p� array. 
	/*cout << "List av st�der och deras temperaturer: " << endl;
	GetInfo(cities, 4);*/

	bubblesort(cities, 4);

	cout << "sorted list of cities: " << endl;
	cout << cities[0].ToString() << endl;
	cout << cities[1].ToString() << endl;
	cout << cities[2].ToString() << endl;
	cout << cities[3].ToString() << endl;

	int searchtemp;
	cout << "(LINEAR SEARCH)" << endl << "Which temperature are you looking for?: " << endl;
	cin >> searchtemp;

	int result = linSearch(cities, 4, searchtemp);
	if (result >= 0) {
		cout << "Temperature " << cities[result].Temp << " degrees is at the element with index " << result << "." << endl;
	}
	else {
		cout << "Temperaturen " << searchtemp << " degrees was not found." << endl << endl;
	}



	int searchtemp2;
	cout << "(BINARY SEARCH)" << endl << "Which temperature are you looking for?: " << endl;
	cin >> searchtemp2;

	int result3 = binSearch(cities,0, 4, searchtemp2);
	if (result3 >= 0) {
		cout << "Temperature "  << cities[result3].Temp << " degrees is at the element with index "  << result3 << ", i.e city: " << cities[result3].Name << endl;
	}
	else {
		cout << "Temperature " << searchtemp2 << " degrees was not found." << endl;
	}

	//F�r att visa h�sgta och l�gsta temperaturerna

	string result1 = hogstTemp(cities, 4);
	cout << endl << "The city with the highest temperature is " << result1 << endl;
	string result2 = lagstTemp(cities, 4);
	cout << endl << "The city with the lowest temperature is " << result2 << endl;


	return 0;
}
