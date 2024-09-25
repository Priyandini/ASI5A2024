#include <iostream>
#include <string.h>
using namespace std;

void enkripsi(){

string plainteks, cipherteks;
int i, k;
char c;

cout << "Ketikkan pesan: ";
cin.ignore();
getline(cin, plainteks);
cout << "Masukkan jumlah pergeseran (0-25): ";
cin >> k;

for(i = 0; i < plainteks.length(); i++){
    c = plainteks[i];
    if(isalpha(c)){
        c = toupper(c);
        c = c - 65;
        c = (c + k) % 26;
        c = c + 65;
    }
    cipherteks = cipherteks + c;
}
cout << "Cipherteks: " << cipherteks << endl;
}

void dekripsi(){
string plainteks, cipherteks;
int i, k;
char c;

cout << "Ketikkan cipherteks: ";
cin.ignore();
getline(cin, cipherteks);
cout << "Masukkan jumlah pergeseran (0-25): ";
cin >> k;

for(i = 0; i < cipherteks.length(); i++){
    c = cipherteks[i];
    if(isalpha(c)){
        c = c - 65;
        c = (c - k + 26) % 26;
        c = c + 65;
        c = tolower(c);
    }
    plainteks = plainteks + c;
}
cout << "Plainteks: " << plainteks << endl;
}

int main() {
int pil; 
bool stop;
stop = false;
while(!stop){
    cout << "Menu " << endl;
    cout << "1. enkripsi " << endl;
    cout << "2. dekripsi " << endl;
    cout << "3. exit " << endl;
    cout << "pilih menu "; cin >> pil;
    switch(pil){
        case 1: enkripsi(); break;
        case 2: dekripsi(); break;
        case 3: stop = true; break;
}
}
}
