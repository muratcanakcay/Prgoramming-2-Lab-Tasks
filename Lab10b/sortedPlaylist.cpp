#include <iostream>
#include "sortedPlaylist.h"
using namespace std;

//**********************STAGE 5**********************

SortedPlaylist::SortedPlaylist(string name, SortOrder so, SortLabel sl) : Playlist(name), sortOrder(so), sortLabel(sl) {};

void SortedPlaylist::add_song(Song s)
{
	Playlist::add_song(s);
	sortPlaylist();
}

void SortedPlaylist::add_songs(list<Song>& sl)
{
	Playlist::add_songs(sl);
	sortPlaylist();
}

void SortedPlaylist::add_songs(Playlist& pl)
{
	Playlist::add_songs(pl);
	sortPlaylist();
}

void SortedPlaylist::insert_song_by_genre(list<Song> sl)
{
	Playlist::insert_song_by_genre(sl);
	sortPlaylist();
}

void SortedPlaylist::set_sort_settings(SortOrder so, SortLabel sl)
{
	sortOrder = so;
	sortLabel = sl;
	sortPlaylist();
}

void SortedPlaylist::sortPlaylist()
{
	if (sortLabel == SortLabel::AUTHOR)
	{
		if (sortOrder == SortOrder::ASCENDING)
			this->songs.sort([&](Song& s1, Song& s2) {return s1.get_author() < s2.get_author(); });
		else 
			this->songs.sort([&](Song& s1, Song& s2) {return s1.get_author() > s2.get_author(); });
	}
		else 
	{
		if (sortOrder == SortOrder::ASCENDING)
			this->songs.sort([&](Song& s1, Song& s2) {return s1.get_title() < s2.get_title(); });
		else 
			this->songs.sort([&](Song& s1, Song& s2) {return s1.get_title() > s2.get_title(); });
	}
}



