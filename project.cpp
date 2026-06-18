#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

struct Tersangka {
    std::string nama;
    std::string motif;
    std::string pertanyaan[6];
    std::string jawaban[6];

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
            "Siapa yang terakhir Anda lihat bersama David?",
            "Apakah Anda masuk ke ruang kerja malam itu?"
        },
        {
            "Saya berada di ruang tamu bersama para tamu.",
            "Hubungan kami sedang kurang baik akhir-akhir ini.",
            "Saya mengetahui sebagian isi wasiatnya.",
            "Kami sempat berdebat beberapa hari sebelumnya.",
            "Saya melihat Liam berbicara dengannya.",
            "Tidak, saya tidak masuk ke ruang kerja."
        },
        false
    },

    {
        "Liam",
        "Terlibat penggelapan dana perusahaan",
        {
            "Di mana Anda saat kejadian?",
            "Apa hubungan Anda dengan korban?",
            "Apakah Anda mengetahui email David?",
            "Apakah Anda memiliki masalah dengan David?",
            "Mengapa Anda terlihat di koridor?",
            "Apakah Anda masuk ke ruang kerja?"
        },
        {
            "Saya sedang berbicara dengan beberapa tamu.",
            "Kami sahabat sekaligus rekan kerja.",
            "Tidak, saya tidak mengetahui email tersebut.",
            "Tidak ada masalah serius antara kami.",
            "Saya hanya mencari toilet.",
            "Tidak, saya tidak masuk ke ruang kerja."
        },
        false
    },

    {
        "Lena",
        "Menyimpan rahasia masa lalu keluarganya",
        {
            "Di mana Anda saat kejadian?",
            "Sudah berapa lama Anda bekerja?",
            "Apa hubungan Anda dengan David?",
            "Mengapa Anda berada di dapur?",
            "Apa isi dokumen lama itu?",
            "Apakah Anda pernah mengancam David?"
        },
        {
            "Saya sedang membantu persiapan pesta.",
            "Saya sudah bekerja selama tujuh tahun.",
            "Beliau adalah atasan saya.",
            "Saya mengambil minuman untuk para tamu.",
            "Dokumen itu berkaitan dengan ayah saya.",
            "Tidak pernah."
        },
        false
    }
};

void clear () {
    std::cout << "\033[2J\033[H";
}

void garis() {
    std::cout << std::endl
              << "=================================================" << std::endl;
}

void wawancaraTersangka(int index) {
    clear ();
    Tersangka *ptr = &tersangka[index];
    garis ();
    std::cout << "WAWANCARA DENGAN "
              << ptr->nama;

    int nomor[6] = {0,1,2,3,4,5};
    for (int iterasi = 0; iterasi < 6; iterasi++) {
        int pertanyaan    = rand() % 6;
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
    while(sisaPertanyaan > 0)
    {
        garis ();
        std::cout << "Pilih pertanyaan : " << std::endl;
        int nomorMenu   = 1;
        for (int indeks = 0; indeks < 3; indeks++) {
            if (!sudahDitanya[indeks]) {
                std::cout << nomorMenu
                          << ". "
                          << ptr->pertanyaan[pertanyaanAcak[indeks]]
                          << std::endl;
                nomorMenu++;
            }
        }

        std::cout << nomorMenu
                  << ". Selesai Wawancara" << std::endl;
        garis ();

        int pilihan;
        std::cout << std::endl
                  << "Pilihan : ";
        std::cin >> pilihan;
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
            std::cout << std::endl 
                      << "Pilihan tidak valid!" << std::endl;
            continue;
        }

        garis();
        std::cout << "PERTANYAAN : "
                  << ptr->pertanyaan[pertanyaanAcak[indeksPertanyaan]]
                  << std::endl 
                  << std::endl
                  << "JAWABAN : "
                  << std::endl
                  << ptr->jawaban[pertanyaanAcak[indeksPertanyaan]]
                  << std::endl;
        sudahDitanya[indeksPertanyaan] = true;
        sisaPertanyaan--;
    }
    ptr->sudahWawancara = true;
    garis ();
    std::cout << "Wawancara selesai." << std::endl;
}

void menuWawancara() {
    int pilih;
    do {
        garis ();
        std::cout << "MENU WAWANCARA";
        garis ();
        std::cout << "1. Emma Alden"  << std::endl
                  << "2. Liam" << std::endl
                  << "3. Lena" << std::endl
                  << "4. Kembali";
        garis ();
        std::cout << "Pilihan : ";
        std::cin >> pilih;
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
                std::cout << "Pilihan tidak valid!" << std::endl;
                           system("pause");system("cls");
   

        }

    }
    while(pilih != 4);
}

int main()
{
    menuWawancara ();
    return 0;
}