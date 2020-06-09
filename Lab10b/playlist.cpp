#include <iostream>
#include "playlist.h"
using namespace std;

//**********************STAGE 1**********************

Playlist::Playlist(string name) : name(name) {};

ostream& operator<<(ostream& out, const Playlist& pl)
{
	out << "Playlist name: " << pl.name << endl;
	
	if (pl.songs.empty()) 
		out << "There's no songs in this playlist!" << endl;
	else
		for (auto it = pl.songs.begin(); it != pl.songs.end(); it++)
			out << (*it);
	
	out << endl;
	return out;
}

void Playlist::add_song(Song s)
{
	auto it = find(this->songs.begin(), this->songs.end(), s);
	if (it == this->songs.end()) // song does not exist
		this->songs.push_back(s);
}

void Playlist::add_songs(list<Song>& sl)
{
	this->songs.splice(this->songs.end(), sl);
}

void Playlist::add_songs(Playlist& pl)
{
	this->songs.splice(this->songs.end(), pl.songs);
}


//**********************STAGE 2**********************

void Playlist::insert_song_by_genre(list<Song> sl)
{
	Genre genre = sl.begin()->get_genre();
	
	bool added = false;

	for (auto it = (this->songs).begin(); it != (this->songs).end(); it++)
	{
		if (!added && (*it).get_genre() == genre)
		{
			this->songs.insert(it, *(sl.begin()));
			added = true;
		}
		
		if (added) break;
	}

	if (!added)	this->songs.push_back(*(sl.begin()));
}



//**********************STAGE 3**********************

void Playlist::remove_by_genre(Genre g)
{
	for (auto it = this->songs.begin(); it != this->songs.end();)
		if (it->get_genre() == g) it = this->songs.erase(it);
		else it++;	
}

void Playlist::remove_by_author(string a)
{
	for (auto it = this->songs.begin(); it != this->songs.end();)
		if (it->get_author() == a) it = this->songs.erase(it);
		else it++;

}

void Playlist::remove_by_length(int l)
{
	for (auto it = this->songs.begin(); it != this->songs.end();)
		if (it->get_length() > l) it = this->songs.erase(it);
		else it++;
}





//**********************STAGE 4**********************

Playlist merge(string name, Playlist arr[] , int l)
{
	Playlist newpl(name);

	for (int i = 0; i < l; i++)
		newpl.add_songs(arr[i]);
	
	return newpl;
}