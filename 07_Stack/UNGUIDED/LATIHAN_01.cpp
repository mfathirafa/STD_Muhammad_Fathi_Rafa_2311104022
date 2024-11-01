#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isPalindrome(const string &str) {
    stack<char> s;
    string cleanedStr = "";

    // Menghilangkan spasi dan karakter non-alphabet serta menambahkan ke stack
    for (char c : str) {
        if (isalpha(c)) {
            cleanedStr += tolower(c);
            s.push(tolower(c));
        }
    }

    // Membandingkan karakter dengan urutan stack
    for (char c : cleanedStr) {
        if (c != s.top()) {
            return false;
        }
        s.pop();
    }

    return true;
}

int main() {
    string input;
    cout << "Masukkan kalimat: ";
    getline(cin, input);

    if (isPalindrome(input)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }

    return 0;
}
