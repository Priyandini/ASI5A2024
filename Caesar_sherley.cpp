#include <iostream>
#include <string.h>
using namespace std;

void enkripsi() {
    string plainteks = "", cipherteks = "";
    int i, k;
    char c;

    cout << "Ketikkan pesan: ";
    cin.ignore();  // Hanya jika ada input numerik sebelumnya
    getline(cin, plainteks);
    do {
        cout << "Masukkan jumlah pergeseran (0-25): ";
        cin >> k;
    } while (k < 0 || k > 25);

    for (i = 0; i < plainteks.length(); i++) {
        c = plainteks[i];
        if (isalpha(c)) {
            c = toupper(c);
            c = c - 65;
            c = (c + k) % 26;
            c = c + 65;
        }
        cipherteks = cipherteks + c;
    }
    cout << "Cipherteks: " << cipherteks << endl;
}

void dekripsi() {
    string plainteks = "", cipherteks = "";
    int i, k;
    char c;

    cout << "Ketikkan cipherteks: ";
    cin.ignore();  // Hanya jika ada input numerik sebelumnya
    getline(cin, cipherteks);
    do {
        cout << "Masukkan jumlah pergeseran (0-25): ";
        cin >> k;
    } while (k < 0 || k > 25);

    for (i = 0; i < cipherteks.length(); i++) {
        c = cipherteks[i];
        if (isalpha(c)) {
            c = c - 65;
            c = (c - k + 26) % 26;
            c = c + 65;
        }
        plainteks = plainteks + c;
    }
    cout << "Plainteks: " << plainteks << endl;
}

int main() {
    int pil;
    bool stop = false;

    while (!stop) {
        cout << "Menu " << endl;
        cout << "1. enkripsi " << endl;
        cout << "2. dekripsi " << endl;
        cout << "3. exit " << endl;
        cout << "pilih menu "; 
        cin >> pil;
        cin.ignore();  // Bersihkan buffer setelah input numerik

        switch (pil) {
            case 1: enkripsi(); break;
            case 2: dekripsi(); break;
            case 3: stop = true; break;
            default: cout << "Pilihan tidak valid!" << endl; break;
        }
    }
}
