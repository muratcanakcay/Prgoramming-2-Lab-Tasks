#pragma once
#include <string>
#include <list>
#include "song.h"
using namespace std;

class Playlist
{
protected:
	list<Song> songs;
	string name;

public:
	Playlist(string);

	void add_song(Song);
	void add_songs(list<Song>&);
	void add_songs(Playlist&);
	void insert_song_by_genre(list<Song>);
	void remove_by_genre(Genre);
	void remove_by_author(string);
	void remove_by_length(int);

	friend Playlist merge(string, Playlist[], int);

	friend ostream& operator<<(ostream&, const Playlist&);
};


class LengthCheck
{
	int length;
public:
	//**********************STAGE 3**********************
};