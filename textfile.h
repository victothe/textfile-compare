/*
PIC 10B 1A, Homework 3
Purpose: text file comparison
Author: Victor He
Date: 5/7/2022
*/

#ifndef TEXTFILE_H
#define TEXTFILE_H
#include<fstream>
#include<iostream>
#include<string>
using namespace std;

class textfile
{
public:
	// initializes textfile object with name a
	textfile(string a);

	// returns true if both textfiles have the same linecount
	friend bool operator==(const textfile& a, const textfile& b);

	// returns true if textfile a has more lines than textfile b
	friend bool operator>(const textfile& a, const textfile& b);

	// returns chcount
	int get_characters();

	// return linecount
	int get_lines();

	// returns wordcount
	int get_words();

	// returns name
	string get_name();

private:   
	ifstream fin;
	string s;
	int linecount;
	int chcount;
	int wordcount;
	string name;
};

#endif

