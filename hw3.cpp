/*
PIC 10B 1A, Homework 3
Purpose: text file comparison
Author: Victor He
Date: 5/7/2022
*/

#include<fstream>
#include<iostream>
#include<string>
#include "textfile.h"
using namespace std;

int main()
{
	string file1, file2;
	cout << "Enter the name of file 1: ";
	cin >> file1;
	cout << "Enter the name of file 2: ";
	cin >> file2;

	// initializes textfile objects with file name parameters
	textfile first(file1);
	textfile second(file2);
	
	// opens the Properties text file
	ofstream fout;
	fout.open("Properties.txt");
	
	// prints the two textfile characteristics
	fout << "File Name: " << file1 << endl;
	fout << "Number of Characters: " << first.get_characters() << endl;
	fout << "Number of Words: " << first.get_words() << endl << endl;
	fout << "File Name: " << file2 << endl;
	fout << "Number of Characters: " << second.get_characters() << endl;
	fout << "Number of Words: " << second.get_words() << endl << endl;

	// operator overloading to compare textfiles' number of lines
	if (first>second)
	{
		fout << "The file named " << "\"" << file1 << "\"" " has more lines than " << "\"" << file2 << "\".";
	}
	else if (first == second)
	{
		fout << "Both files have the same amount of lines.";
	}
	else 
	{
		fout << "The file named " << "\"" << file1 << "\"" " has less lines than " << "\"" << file2 << "\".";
	}

	fout.close();

	return 0;
}