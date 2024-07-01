# City Temperature Management System
## Description
This project is a C++ program that manages and processes temperature data for different cities. It allows users to input city names and their corresponding temperatures, sort these cities based on temperature, and perform both linear and binary searches to find cities with specific temperatures. The program also identifies the city with the highest and lowest temperatures.

## Features
### Input City Data:
Allows users to input city names and their corresponding temperatures.
### Temperature Validation:
Ensures that the temperature input is within a valid range (-60 to 60 degrees).
### Data Display:
Displays the list of cities and their temperatures.
### Sorting: 
Sorts the cities based on their temperatures using bubble sort.
### Searching: 
Supports both linear and binary search to find cities with specific temperatures.
### Temperature Extremes:
Identifies and displays the city with the highest and lowest temperatures.

## Usage
The program will prompt you to enter the name and temperature for four cities.
After entering the data, the program will sort the cities based on their temperatures.
You can perform a linear search to find a city with a specific temperature.
You can perform a binary search to find a city with a specific temperature.
The program will display the city with the highest and lowest temperatures.
## Limitations
### Development Status: 
This program is currently under development and may have bugs or incomplete features.
### Fixed Number of Cities: 
The program is hardcoded to handle exactly four cities. This can be modified to handle more or fewer cities dynamically.
### Limited Input Validation: 
The temperature validation is limited to a specific range (-60 to 60 degrees), which may not cover all realistic scenarios.
### Efficiency: 
The sorting algorithm used (bubble sort) is not the most efficient for large datasets.
## Code Overview
### Class: 
City: Represents a city with its name and temperature.

### Methods:
City(): Default constructor.

City(string city, int temp): Parameterized constructor.

GetName(): Prompts the user to enter the city's name.

GetTemp(): Prompts the user to enter the city's temperature with validation.

ToString(): Returns a string representation of the city's name and temperature.

### Functions:
getInfo(City cities[]): Displays the list of cities and their temperatures.

bubblesort(City cities[], int n): Sorts the cities based on temperature using bubble sort.

linSearch(City cities[], int n, int searchtemp): Performs a linear search for a city with the specified temperature.

binSearch(City cities[], int low, int high, int searchtemp): Performs a binary search for a city with the specified temperature.

hogstTemp(City cities[], int n): Finds the city with the highest temperature.

lagstTemp(City cities[], int n): Finds the city with the lowest temperature.

## Main Function
Collects city data from the user.

Sorts the cities by temperature.

Performs searches and displays the results.

Displays the cities with the highest and lowest temperatures.

## Future Improvements
### Dynamic City Handling: 
Allow the user to input any number of cities.
### Advanced Sorting: 
Implement more efficient sorting algorithms for larger datasets.
### User Interface: 
Develop a graphical user interface for better user experience.
### Enhanced Validation: 
Implement more comprehensive input validation and error handling.
#
This README provides an overview of the current functionality and limitations of the City Temperature Management System. As the project is under development, further enhancements and bug fixes will be implemented in future iterations.
