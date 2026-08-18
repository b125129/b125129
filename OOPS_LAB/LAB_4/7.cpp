
#include <iostream>
#include <string>
using namespace std;

class Player {
private:
    string playerName;
    int health;
    int score;
    int level;

public:
    Player(string name, int h, int s, int l) {
        playerName=name;
        health=h;
        score=s;
        level=l;
    }
    friend class GameManager;
};

class GameManager {
public:
    void displayDetails(Player& p) {
        cout << "--- Player Details ---" << endl;
        cout << "Name: " << p.playerName << endl;
        cout << "Health: " << p.health << endl;
        cout << "Score: " << p.score << endl;
        cout << "Level: " << p.level << endl;
    }

    void checkIsAlive(Player& p) {
        if (p.health > 0) {
            cout << p.playerName << " is Alive!" << endl;
        } else {
            cout << p.playerName << " is Dead!" << endl;
        }
    }

    void displayLevelAndScore(Player& p) {
        cout << p.playerName << "'s Level: " << p.level << " | Score: " << p.score << endl;
    }
};

int main() {
    string playerName;
    int health;
    int score;
    int level;

    cout<<"Enter player name, health, score and level."<<endl;
    cin>>playerName>>health>>score>>level;

    Player p(playerName,health,score,level);
    GameManager gm;

    gm.displayDetails(p);
    cout << endl;
    gm.checkIsAlive(p);
    gm.displayLevelAndScore(p);

    return 0;
}
