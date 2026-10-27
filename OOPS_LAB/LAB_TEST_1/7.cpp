#include <iostream>
using namespace std;

int main() {
    char sentence[] = "Yahello! Kindly Grant me FULL marks";
    const char *ptr = sentence;

    int uppercaseCount = 0;
    int lowercaseCount = 0;
    int spaceCount = 0;

    while (*ptr != '\0') {
        if (*ptr >= 'A' && *ptr <= 'Z') {
            uppercaseCount++;
        } else if (*ptr >= 'a' && *ptr <= 'z') {
            lowercaseCount++;
        } else if (*ptr == ' ') {
            spaceCount++;
        }
        ptr++;
    }

    cout << "Sentence: " << sentence << endl;
    cout << "Uppercase letters: " << uppercaseCount << endl;
    cout << "Lowercase letters: " << lowercaseCount << endl;
    cout << "Spaces: " << spaceCount << endl;

    return 0;
}