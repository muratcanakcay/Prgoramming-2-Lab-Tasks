#include <iostream>
#include "song.h"
using namespace std;

//**********************STAGE 1**********************

Song::Song(string author, string title, Genre genre, int length) : author(author), title(title), genre(genre), length(length) {}

bool operator==(const Song& s1, const Song& s2)
{
	return (s1.author == s2.author && s1.title == s2.title);
}

ostream& operator<<(ostream& out, const Song& s)
{
	out << s.author << " - " << s.title << " (";
	
	int minutes = s.length / 60;
	int seconds = s.length % 60;
			
	out << minutes << ":" << (seconds < 10  ? "0" : "") << seconds << ") [";
	
	switch (s.genre) 
	{
	case Genre::Pop:
		out << "Pop"; break;
	case Genre::Rock:
		out << "Rock"; break;
	case Genre::Electronic:
		out << "Electronic"; break;
	case Genre::Country:
		out << "Country"; break;
	case Genre::Blues:
		out << "Blues"; break;
	}

	out << "]" << endl;
	return out;
}