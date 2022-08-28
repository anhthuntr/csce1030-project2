#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;
	
const int NUM_TEST=5; //global integer constant for number of tests

enum Type {Add=1, Remove=2, Display=3, Search=4, Result=5, Quit=6}; //list of menu choices

//Structure for Student Information
struct Student
{
	string name;
	int numtest;
	int sID;
	double avg_score;
	int* numlist; //declare a pointer
};

int getNumber();
int findMinimum(int arr[], int sz);
void add_Student();
void remove_Student(int remove_ID);
void display_Student();
void search();
void exportResults();
