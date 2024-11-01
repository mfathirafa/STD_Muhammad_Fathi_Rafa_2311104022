#include <iostream>
#include <stack>
#include <string>

using namespace std;

void reverseString(const string &str) {
    stack<char> s;

    // Masukkan setiap karakter ke dalam stack
    for (char c : str) {
        s.push(c);
    }

    cout << "Kalimat setelah dibalik: ";
    // Keluarkan karakter dari stack untuk membalik urutan karakter
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

int main() {
    string input;
    cout << "Masukkan kalimat: ";
    getline(cin, input);

    reverseString(input);

    return 0;
}
