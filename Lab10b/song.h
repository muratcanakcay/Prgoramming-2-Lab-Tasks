#pragma once
#include <string>
using namespace std;

enum class Genre
{
	Pop, Rock, Electronic, Country, Blues
};

class Song
{
private:
	string author;
	string title;
	Genre genre;
	int length;

public:
	Song(string, string, Genre, int);

	Genre get_genre() const { return genre; }
	string get_author() const { return author; }
	string get_title() const { return title; }
	int get_length() const { return length; }

	friend bool operator==(const Song&, const Song&);
	friend ostream& operator<<(ostream&, const Song&);
};

