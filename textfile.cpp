/*
PIC 10B 1A, Homework 3
Purpose: text file comparison
Author: Victor He
Date: 5/7/2022
*/
#include "textfile.h"

textfile::textfile(string a)
{
	name = a;

	fin.open(a);

	if (fin.fail())
	{
		cout << "Can't open file ";
		fin.close();
	}

	chcount = 0;
	linecount = 0;
	wordcount = 0;

	while (getline(fin, s))
	{
		for (int i = 0; i < s.length(); i++)
		{
			int j = i + 1;
			if (j > s.length())
			{
				continue;
			}
			if (s[i] == ' ' && s[j] != ' ')
			{
				wordcount++; // if last ch in string is a space and the next ch is not, then wordcount++
			}
			chcount++; // chcount++ for each ch in string
		}

		linecount++; // linecount++ for each line read 
	}

	fin.close();
}

int textfile::get_characters()
{
	return chcount;
}

int textfile::get_lines()
{
	return linecount;
}

int textfile::get_words()
{
	return wordcount;
}

string textfile::get_name()
{
	return name;
}

bool operator==(const textfile& a, const textfile& b)
{
	return a.linecount == b.linecount;
}
bool operator>(const textfile& a, const textfile& b)
{
	return a.linecount > b.linecount;
}