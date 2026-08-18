#include <iostream>
#include <string>
using namespace std;

class Song {
private:
    string songName;
    string artistName;
    int duration; 

public:
    Song(string name, string artist, int sec) {
        songName=name;
        artistName=artist;
        duration=sec;
    }

    // Friend function declaration
    friend void compareSongs(Song& s1, Song& s2);
};

void compareSongs(Song& s1, Song& s2) {
    cout << "Comparing \"" << s1.songName << "\" and \"" << s2.songName << "\":" << endl;
    if (s1.duration > s2.duration) {
        cout << "\"" << s1.songName << "\" is longer." << endl;
    } else if (s2.duration > s1.duration) {
        cout << "\"" << s2.songName << "\" is longer." << endl;
    } else {
        cout << "Both songs have the same duration." << endl;
    }
}

int main() {
    string songName;
    string artistName;
    int duration; 

    cout<<"Enter song name, artist name and duration of the song 1: "<<endl;
    cin>>songName>>artistName>>duration;
    Song s1(songName,artistName,duration);

    cout<<"Enter song name, artist name and duration of the song 2: "<<endl;
    cin>>songName>>artistName>>duration;
    Song s2(songName,artistName,duration);

    compareSongs(s1, s2);
    return 0;
}