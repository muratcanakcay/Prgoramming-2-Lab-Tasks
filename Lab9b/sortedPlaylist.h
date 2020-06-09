#pragma once
#include "playlist.h"
using namespace std;

enum class SortOrder
{
	ASCENDING, DESCENDING
};

enum class SortLabel
{
	AUTHOR, TITLE
};

class SortedPlaylist : public Playlist
{
	SortOrder sortOrder;
	SortLabel sortLabel;

	void sortPlaylist();
public:
	SortedPlaylist(string, SortOrder, SortLabel);

	void add_song(Song);
	void add_songs(list<Song>&);
	void add_songs(Playlist&);
	void insert_song_by_genre(list<Song>);

	void set_sort_settings(SortOrder, SortLabel);
};
