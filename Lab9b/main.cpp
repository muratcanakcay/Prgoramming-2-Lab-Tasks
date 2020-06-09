#pragma once
#include <iostream>
#include <list>
#include "song.h"
#include "playlist.h"
#include "sortedPlaylist.h"
using namespace std;

//DO NOT CHANGE THE CODE, ONLY UNCOMMENT EACH STAGE
int main()
{
	cout << endl;
	cout << "*********************** STAGE 1 (2p) *********************** " << endl << endl;

	Song s1("Bon Jovi", "Livin' On A Prayer", Genre::Rock, 248);
	Song s2("Mark Ronson ft. Bruno Mars", "Uptown Funk", Genre::Pop, 271);
	Song s3("Camellia", "Crystallized", Genre::Electronic, 277);
	Song s4("B.B. King", "The Thrill Is Gone", Genre::Blues, 329);
	Song s5("Johnny Cash", "Ring of Fire", Genre::Country, 155);

	cout << s1 << s2 << s3 << s4 << s5 << endl;
	Song s6("The Verve", "Bitter Sweet Symphony", Genre::Pop, 277);

	Song sa1[]
	{
		{"R.E.M.", "Losing My Religion", Genre::Rock, 268},
		{"Nirvana", "Smells Like Teen Spirit", Genre::Rock, 301},
		{"Guns N' Roses", "Welcome To The Jungle", Genre::Rock, 274},
		{"AC/DC", "Highway To Hell", Genre::Rock, 210},
		{"The Rolling Stones", "Paint It Black", Genre::Rock, 224},
		{"The Who", "Baba O'Riley", Genre::Rock, 304},
		{"Deep Purple", "Smoke On The Water", Genre::Rock, 338},
		{"Scorpions", "Rock You Like A Hurricane", Genre::Rock, 256},
		{"Metallica", "Master Of Puppets", Genre::Rock, 516},
		{"System Of A Down", "Chop Suey!", Genre::Rock, 210},
		{"Scorpions", "Wind Of Change", Genre::Rock, 313}
	};

	Song sa2[]
	{
		{"Miley Cyrus", "Wrecking Ball", Genre::Pop, 221},
		{"Carly Rae Jepsen", "Call Me Maybe", Genre::Pop, 193},
		{"Maroon 5", "One More Night", Genre::Pop, 219},
		{"Maroon 5", "Animals", Genre::Pop, 231},
		{"Adele", "Rolling In The Deep", Genre::Pop, 228},
		{"Ariana Grande", "One Last Time", Genre::Pop, 197}
	};
	
	Song sa3[]
	{
		{"Camellia", "Killerbeast", Genre::Electronic, 247},
		{"Camellia", "Blackmagik Blazing", Genre::Electronic, 272},
		{"Camellia", "Arche", Genre::Electronic, 322},
		{"Camellia", "SECRET BOSS", Genre::Electronic, 271},
		{"Camellia", "NUCLEAR-STAR", Genre::Electronic, 292},
		{"Camellia", "Darkness Overload", Genre::Electronic, 267}
	};

	Playlist p1("Sad, empty playlist");
	Playlist p2("Lil' mix");
	p2.add_song(s1);
	p2.add_song(s2);
	p2.add_song(s3);
	p2.add_song(s4);
	p2.add_song(s5);
	p2.add_song(s6);
	p2.add_song(s5);
	p2.add_song(s6);

	list<Song> l1;
	l1.push_back(s1);
	for (int i = 0; i < 11; i++)
	{
		l1.push_back(sa1[i]);
	}
	
	Playlist p3("Rock playlist");
	p3.add_songs(l1);

	list<Song> l2;
	l2.push_back(s6);
	for (int i = 0; i < 6; i++)
	{
		l2.push_back(sa2[i]);
	}

	Playlist p4("Pop playlist");
	p4.add_songs(l2);

	list<Song> l3;
	l3.push_back(s3);
	for (int i = 0; i < 6; i++)
	{
		l3.push_back(sa3[i]);
	}
	Playlist temp("Temp playlist (should be empty)");
	temp.add_songs(l3);

	Playlist p5("Camellia Playlist");
	p5.add_songs(temp);

	cout << p1 << p2;

	cout << "List of rock songs (should be empty): " 
		<< (l1.empty() ? "EMPTY" : "NOT EMPTY") << endl << endl;
	cout << p3 << p4 << temp << p5;

	cout << "*********************** STAGE 2 (1p) *********************** " << endl << endl;

	for (int i = 0; i < 6; i++)
	{
		l2.push_back(sa2[i]);
	}

	for (int i = 0; i < 6; i++)
	{
		l3.push_back(sa3[i]);
	}
	cout << p2;

	cout << "Adding a pop song to Lil' mix:" << endl;
	p2.insert_song_by_genre(l2);

	cout << "...and an electronic one:" << endl << endl;
	p2.insert_song_by_genre(l3);

	cout << p2; 

	cout << "Adding a pop song to Camellia playlist" << endl << endl;
	p5.insert_song_by_genre(l2);

	cout << p5;

	cout << "*********************** STAGE 3 (2p) *********************** " << endl << endl;

	cout << "Removing pop songs from Lil' mix: " << endl;
	p2.remove_by_genre(Genre::Pop);
	cout << p2;

	cout << "Removing Scorpions' songs from Rock playlist: " << endl;
	p3.remove_by_author("Scorpions");
	cout << p3;

	cout << "Removing songs from Rock playlist that are longer than 5 minutes: " << endl;
	p3.remove_by_length(300);
	cout << p3;

	cout << "*********************** STAGE 4 (1p) *********************** " << endl << endl;

	Playlist arr[]{ p2, p3, p4 };
	Playlist merged = merge("Merged Playlist", arr, 3);
	cout << merged;

	cout << "*********************** STAGE 5 (2p) *********************** " << endl << endl;

	SortedPlaylist sp1("Ascending by author", SortOrder::ASCENDING, SortLabel::AUTHOR);
	sp1.add_song(s1);
	sp1.add_song(s2);
	sp1.add_song(s3);
	sp1.add_song(s4);

	SortedPlaylist sp2("Sorted Merged Playlist", SortOrder::ASCENDING, SortLabel::TITLE);
	sp2.add_songs(merged);

	cout << "Sorted by AUTHOR, ASCENDING: " << endl << sp1 << endl;
	cout << "Sorted by TITLE, ASCENDING: " << endl << sp2 << endl;
	sp2.set_sort_settings(SortOrder::DESCENDING, SortLabel::AUTHOR);
	cout << "Sorted by AUTHOR, DESCENDING: " << endl << sp2 << endl;

	//system("pause");
	return 0;
}
