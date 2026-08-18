#include <iostream>
#include <string>
using namespace std;

class Diary {
private:
    string ownerName;
    int noEnt;
    string lEntry;

public:
    Diary(string owner, int entries, string last) 
        : ownerName(owner), noEnt(entries), lEntry(last) {}

    friend void displayDiary(Diary &d);     // Friend function declaration
};

void displayDiary(Diary &d) {
    cout << "--- Diary Details ---" << endl;
    cout << "Owner Name: " << d.ownerName << endl;
    cout << "Number of Entries: " << d.noEnt<< endl;
    cout << "Last Entry: " << d.lEntry << endl;
}

int main() {
    string ownName;
    int no_of_Ent;
    string last_Entry;
    cout<<"Enter Owner Name, number of entries and your last entry."<<endl;
    cin>>ownName>>no_of_Ent>>last_Entry;

    Diary myDiary(ownName, no_of_Ent, last_Entry);
    displayDiary(myDiary);
    return 0;
}