#include <iostream>
#include <string>
#include <cstdlib> 

using namespace std;

void tentukanPelaku(bool* pWawancara, bool* pBukti);

int main() {
    bool sudahWawancara = true;
    bool semuaBuktiDitemukan = true;

    bool* ptrWawancara = &sudahWawancara;
    bool* ptrBukti = &semuaBuktiDitemukan;

    tentukanPelaku(ptrWawancara, ptrBukti);

    return 0;
}

void tentukanPelaku(bool* pWawancara, bool* pBukti) {
    if (!*pWawancara) {
        cout << "Anda harus mewawancarai seluruh tersangka terlebih dahulu." << endl; 
        return;
    }

    if (!*pBukti) {
        cout << "Masih ada bukti yang belum dianalisis." << endl; 
        return; 
    }

    int pilihanPelaku;
    bool berjalan = true;

    while (berjalan) {
        system("cls"); 

        cout << "Siapakah pelaku pembunuhan David?" << endl;
        cout << "1. Emma Alden" << endl;
        cout << "2. Liam" << endl;
        cout << "3. Lena" << endl;
        cout << "Masukkan pilihan Anda (1-3): ";
        cin >> pilihanPelaku;

        if (pilihanPelaku == 3) {
            cout << "\nAnalisis Anda benar! Lena adalah pelakunya." << endl; 
            cout << "Game Selesai." << endl;
            cin.ignore();
            cin.get();
            return; 
        } 
        else if (pilihanPelaku == 1 || pilihanPelaku == 2) {
            cout << "\nTuduhan salah! Silakan coba lagi dan ulang dari awal." << endl;
            cout << "Tekan ENTER untuk mencoba lagi...";
            cin.ignore();
            cin.get(); 
        } 
        else {
            cout << "\nPilihan tidak valid! Anda harus memasukkan angka 1 sampai 3." << endl;
            cout << "Tekan ENTER untuk mencoba lagi...";
            cin.ignore();
            cin.get(); 
        }
    }
}