#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Tersangka {
    string nama;
    string motif;
    string pertanyaan[6];
    string jawaban[6];

    bool sudahWawancara;
};

Tersangka tersangka[3] = {
    {
        "Emma Alden",
        "Mewarisi seluruh aset David",
        {
            "Di mana Anda saat kejadian?",
            "Bagaimana hubungan Anda dengan David?",
            "Apakah Anda mengetahui isi wasiat David?",
            "Apakah Anda bertengkar dengan David?",
            "Siapa yang terakhir Anda lihat bersama David?"
        },
        {
            "Saya berada di taman belakang sedang \nbercengkrama bersama para tamu.",
            "Hubungan kami sedang kurang baik \nakhir-akhir ini, David berselingkuh dari saya.",
            "Saya mengetahui sebagian isi wasiatnya.\nIsi wasiatnya adalah semua kekayaan akan jadi milik saya",
            "Kami sempat berdebat beberapa hari sebelumnya, \nkarena perselingkuhanya diketahui.",
            "Saya melihat Liam berbicara dengannya."
        },
        false
    },

    {
        "Liam",
        "Terlibat penggelapan dana perusahaan",
        {
            "Di mana Anda saat kejadian?",
            "Apa hubungan Anda dengan korban?",
            "Apakah Anda memiliki masalah dengan David?",
            "Apakah Anda masuk ke ruang kerja?",
            "Apa yang kamu lakukan terakhir kali bertemu korban?"
        },
        {
            "Saya sedang berada di ruang makan ketika lampu padam.",
            "Kami sahabat baik sekaligus rekan kerja.",
            "Kami memiliki masalah, David ingin \nmelaporkan saya ke polisi karena penggelapan dana.",
            "Tidak, saya tidak masuk ke ruang kerja.",
            "Saya hanya melaporkan situasi di kantor."
        },
        false
    },

    {
        "Lena",
        "Menyimpan rahasia masa lalu keluarganya",
        {
            "Di mana Anda saat kejadian?",
            "Sudah berapa lama Anda bekerja dengan korban?",
            "Apa hubungan Anda dengan David?",
            "Mengapa Anda berada di dapur?",
            "Apa isi dokumen yang telah kamu siapkan?"
        },
        {
            "Saya sedang menyiapkan dokumen di lantai 2.",
            "Saya sudah bekerja selama tujuh tahun.",
            "Beliau adalah atasan saya.",
            "Saya mengambil minuman untuk para tamu.",
            "Dokumen itu berkaitan dengan kejadian \nkematian ayah saya."
        },
        false
    }
};

void clear() {
    cout << "\033[H\033[J";
    cout.flush ();
}

void garis() {
    cout << "========================================================" << endl;
}

void wawancaraTersangka(int index) {
    system ("pause");
    clear ();
    garis ();
    Tersangka *ptr = &tersangka[index];
    cout << "WAWANCARA DENGAN "
              << ptr->nama << endl;

    int nomor[5] = {0,1,2,3,4};
    for (int iterasi = 0; iterasi < 5; iterasi++) {
        int pertanyaan    = rand() % 5;
        int sementara     = nomor[iterasi];
        nomor[iterasi]    = nomor[pertanyaan];
        nomor[pertanyaan] = sementara;
    }

    int pertanyaanAcak[3];
    for(int indeks = 0; indeks < 3; indeks++) {
        pertanyaanAcak[indeks] = nomor[indeks];
    }

    bool sudahDitanya[3] = {false,false,false};
    int sisaPertanyaan   = 3;
    while(sisaPertanyaan > 0) {
        garis ();
        cout << "Pilih pertanyaan : " << endl;
        int nomorMenu   = 1;
        for (int indeks = 0; indeks < 3; indeks++) {
            if (!sudahDitanya[indeks]) {
                cout << nomorMenu
                          << ". "
                          << ptr->pertanyaan[pertanyaanAcak[indeks]]
                          << endl;
                nomorMenu++;
            }
        }

        cout << nomorMenu
                  << ". Selesai Wawancara" << endl;
        garis ();

        int pilihan;
        cout << "Pilihan : ";
        cin >> pilihan;
        if (pilihan == nomorMenu) {
            break;
        }

        int indeksPertanyaan = -1;
        int hitung           = 1;
        for (int iterasi = 0; iterasi < 3; iterasi++) {
            if (!sudahDitanya[iterasi]) {
                if(hitung == pilihan) {
                    indeksPertanyaan = iterasi;
                    break;
                }
                hitung++;
            }
        }

        if(indeksPertanyaan == -1) {
            cout << endl 
                      << "Pilihan tidak valid!" << endl;
            continue;
        }

        garis();
        cout << "PERTANYAAN : "
                  << ptr->pertanyaan[pertanyaanAcak[indeksPertanyaan]]
                  << endl 
                  << endl
                  << "JAWABAN : "
                  << ptr->jawaban[pertanyaanAcak[indeksPertanyaan]]
                  << endl;
        sudahDitanya[indeksPertanyaan] = true;
        sisaPertanyaan--;
    }
    ptr->sudahWawancara = true;
    clear ();
    garis ();
    cout << "Wawancara selesai." << endl;
}

void menuWawancara() {
    int pilih;
    do {
        garis ();
        cout << "MENU WAWANCARA" << endl;
        garis ();
        cout << "1. Emma Alden"  << endl
                  << "2. Liam" << endl
                  << "3. Lena" << endl
                  << "4. Kembali" << endl;
        garis ();
        cout << "Pilihan : ";
        cin >> pilih;
           if (std ::cin.fail()) {
        std :: cin.clear();
        std ::cin.ignore(1000, '\n');
        pilih = -1;
    }
        switch(pilih) {
            case 1:
                wawancaraTersangka(0);
                break;
            case 2:
                wawancaraTersangka(1);
                break;
            case 3:
                wawancaraTersangka(2);
                break;
            case 4:
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                           system("pause");
                           system("cls");
        }
    }
    while(pilih != 4);
}

int main() {
    menuWawancara ();
    return 0;
}