#include <iostream>
#include <string>
using namespace std;

const string RESET  = "\033[0m";
const string BOLD   = "\033[1m";
const string MERAH  = "\033[31m";
const string HIJAU  = "\033[32m";
const string KUNING = "\033[33m";
const string BIRU   = "\033[34m";
const string UNGU   = "\033[35m";
const string CYAN   = "\033[36m";
const string PUTIH  = "\033[30m";
const string ABU    = "\033[90m";

const string W_JUDUL = "\033[38;5;25m";   // biru
const string W_MENU  = "\033[38;5;30m";   // teal
const string W_INVES = "\033[38;5;28m";   // hijau
const string W_WAWAN = "\033[38;5;90m";   // ungu
const string W_BUKTI = "\033[38;5;136m";  // emas
const string W_CATAT = "\033[38;5;62m";   // indigo
const string W_PELAK = "\033[38;5;124m";  // merah
const string W_DEDUK = "\033[38;5;166m";  // oranye


const string ART_JUDUL =
R"(
  ____ _    _   _ _____ _   _ _   _ _   _ _____
 / ___| |  | | | | ____| | | | | | | \ | |_   _|
| |   | |  | | | |  _| | |_| | | | |  \| | | |
| |___| |__| |_| | |___|  _  | |_| | |\  | | |
 \____|_____\___/|_____|_| |_|\___/|_| \_| |_|
)";

const string ART_MENU =
R"(
 __  __ ___ _  _ _   _   _   _ _____ _   __  __   _
|  \/  | __| \| | | | | | | | |_   _/_\ |  \/  | /_\
| |\/| | _|| .` | |_| | | |_| | | |/ _ \| |\/| |/ _ \
|_|  |_|___|_|\_|\___/   \___/  |_/_/ \_\_|  |_/_/ \_\
)";

const string ART_INVESTIGASI =
R"(
 ___ _  ___   _____ ___ _____ ___ ___   _   ___ ___
|_ _| \| \ \ / / __/ __|_   _|_ _/ __| /_\ / __|_ _|
 | || .` |\ V /| _|\__ \ | |  | | (_ |/ _ \\__ \| |
|___|_|\_| \_/ |___|___/ |_| |___\___/_/ \_\___/___|
)";

const string ART_WAWANCARA =
R"(
__      _____      ___   _  _  ___   _   ___    _
\ \    / /_\ \    / /_\ | \| |/ __| /_\ | _ \  /_\
 \ \/\/ / _ \ \/\/ / _ \| .` | (__ / _ \|   / / _ \
  \_/\_/_/ \_\_/\_/_/ \_\_|\_|\___/_/ \_\_|_\/_/ \_\
)";

const string ART_BUKTI =
R"(
 ___ _   _ _  _______ ___
| _ ) | | | |/ /_   _|_ _|
| _ \ |_| | ' <  | |  | |
|___/\___/|_|\_\ |_| |___|
)";

const string ART_CATATAN =
R"(
  ___   _ _____ _ _____ _   _  _
 / __| /_\_   _/_\_   _/_\ | \| |
| (__ / _ \| |/ _ \| |/ _ \| .` |
 \___/_/ \_\_/_/ \_\_/_/ \_\_|\_|
)";

const string ART_PELAKU =
R"(
 ___ ___ _      _   _  ___   _
| _ \ __| |    /_\ | |/ / | | |
|  _/ _|| |__ / _ \| ' <| |_| |
|_| |___|____/_/ \_\_|\_\\___/
)";

const string ART_DEDUKSI =
R"(
 ___  ___ ___  _   _ _  _____ ___
|   \| __|   \| | | | |/ / __|_ _|
| |) | _|| |) | |_| | ' <\__ \| |
|___/|___|___/ \___/|_|\_\___/___|
)";

const int JUMLAH_TERSANGKA = 3;
const int JUMLAH_PERTANYAAN = 5;
const int JUMLAH_BUKTI      = 7;
const int JUMLAH_ADEGAN     = 10;
const int BIG               = 100000; // batas cin.ignore

void clear() {
    cout << "\033[H\033[2J\033[3J" 
         << flush;
}

void pause(const string& pesan = "Tekan ENTER untuk melanjutkan...") {
    cout << ABU << pesan 
         << RESET;
    cin.get();
}

void garis() {
    cout << ABU   << "===============================================================" 
         << RESET << "\n";
}

int bacaAngka(const string& prompt) {
    cout << KUNING << prompt << RESET;
    int x;
    cin >> x;
    while (cin.fail()) {
        if (cin.eof()) { 
            cout << "\n[Input berakhir. Permainan ditutup.]\n";
            exit(0);
        }
        cin.clear();
        cin.ignore(BIG, '\n');
        cout << MERAH  << "Input harus berupa angka! " << RESET 
             << KUNING << prompt << RESET;
        cin >> x;
    }
    cin.ignore(BIG, '\n');
    return x;
}

struct Tersangka {
    string nama;
    string motif;
    string pertanyaan[JUMLAH_PERTANYAAN];
    string jawaban[JUMLAH_PERTANYAAN];   
    bool pernahDitanya[JUMLAH_PERTANYAAN];
};

Tersangka tersangka[JUMLAH_TERSANGKA] = {
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

        {
            false, 
            false, 
            false, 
            false, 
            false
        }
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
        {
            false, 
            false, 
            false, 
            false, 
            false
        }
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
        {
            false, 
            false, 
            false, 
            false, 
            false
        }
    }
};

struct Bukti {
    string judul;
    string isi;
    bool ditemukan;
};

Bukti daftarBukti[JUMLAH_BUKTI] = {
    {
        "SURAT ANCAMAN", 
        "Surat ancaman ditemukan di meja kerja David. \nTulisan tangan menyerupai Liam.", 
        false
    },
    
    {
        "REKAMAN CCTV KORIDOR", 
        "Liam terlihat berjalan menuju kantor David \nsekitar pukul 22.05.", 
        false
    },

    {
        "DRAFT EMAIL DAVID", 
        "David berencana melaporkan Liam atas dugaan \npenyalahgunaan dana perusahaan.", 
        false
    },

    {
        "SIDIK JARI PADA BOTOL", 
        "Sidik jari Liam ditemukan pada botol minuman korban.", 
        false
    },

    {
        "HASIL FORENSIK", 
        "Racun tidak ditemukan pada botol minuman. \nRacun ditemukan pada es batu.", 
        false
    },

    {
        "CCTV DAPUR", 
        "Lena terlihat berada sendirian di dekat freezer \nbeberapa saat sebelum pesta dimulai.", 
        false
    },

    {
        "DOKUMEN AYAH LENA", 
        "Ditemukan surat pemecatan ayah Lena yang ditandatangani \nDavid bertahun-tahun lalu.", 
        false
    }
};

bool semuaBuktiDianalisis = false;

void intro() {
    cout << W_JUDUL   << BOLD 
         << ART_JUDUL << RESET
         << KUNING    << "              A Mystery Solver Game               \n" 
         << RESET;
    garis();
    pause("Tekan ENTER untuk memulai penyelidikan...");
    cout << "\n";
    clear();

    garis();
    cout << "                     CERITA KASUS                        \n";
    garis();
    cout << "Malam itu, badai besar melanda wilayah pinggiran kota.\n"
         << "Di sebuah mansion mewah, seorang pengusaha kaya bernama David\n"
         << "ditemukan tewas mengenaskan di ruang kerjanya.\n\n"
         << "Anda adalah seorang Detektif yang ditugaskan malam ini juga.\n"
         << "Mansion telah dikunci, dan ada 3 orang tersangka di dalam rumah:\n"
         << "1. Emma Alden (Istri David)\n"
         << "2. Liam (Sahabat David)\n"
         << "3. Lena (Asisten Pribadi David)\n\n"
         << "Gunakan kemampuan analisis Anda untuk memeriksa seluruh bukti\n"
         << "dan mewawancarai tersangka sebelum menuduh pembunuh aslinya!\n";
    garis();
    pause("Tekan ENTER untuk masuk ke Menu Utama...");
    cout << "\n";
}

void wawancaraTersangka(int index) {
    Tersangka *ptr = &tersangka[index];
    while (true) {
        clear();
        cout << W_WAWAN << ART_WAWANCARA << RESET;
        garis();
        cout << BOLD  << PUTIH 
             << "        WAWANCARA DENGAN " << ptr->nama 
             << RESET << "\n";
        garis();

        int peta[JUMLAH_PERTANYAAN]; 
        int n = 0;
        cout << "Pilih pertanyaan :\n";
        for (int q = 0; q < JUMLAH_PERTANYAAN; q++) {
            if (!ptr->pernahDitanya[q]) {
                cout << (n + 1) << ". " << ptr->pertanyaan[q] << "\n";
                peta[n] = q;
                n++;
            }
        }

        if (n == 0) {
            garis();
            cout << "(Semua pertanyaan untuk tersangka ini sudah Anda ajukan.)\n";
            garis();
            pause("Tekan ENTER untuk mengakhiri wawancara...");
            clear();
            return;
        }

        cout << (n + 1) << ". Selesai Wawancara\n";
        garis();
        int pilihan = bacaAngka("Pilihan : ");

        if (pilihan == n + 1) { 
            clear();
            return;
        }
        else if (pilihan < 1 || pilihan > n) {
            cout << MERAH << "\nPilihan tidak valid!\n" << RESET;
            pause();
            continue;
        }
        else {
            int q = peta[pilihan - 1];
            clear();
            garis();
            cout << "PERTANYAAN : " << ptr->pertanyaan[q] << "\n\n";
            cout << "JAWABAN    : " << ptr->jawaban[q]    << "\n";
            garis();
            ptr->pernahDitanya[q] = true;
            pause();
        }
    }
}

void menuWawancara() {
    int pilih;
    do {
        clear();
        cout << W_WAWAN << ART_WAWANCARA << RESET;
        garis();
        for (int i = 0; i < JUMLAH_TERSANGKA; i++) {
            int terjawab = 0;
            for (int q = 0; q < JUMLAH_PERTANYAAN; q++)
                if (tersangka[i].pernahDitanya[q]) {
                    terjawab++;
                }
                cout << (i + 1) << ". " << tersangka[i].nama
                     << "  [" << terjawab << "/" 
                     << JUMLAH_PERTANYAAN << " pertanyaan]\n";
        }
        cout << "0. Kembali\n";
        garis();
        pilih = bacaAngka("Pilihan : ");

        if (pilih >= 1 && pilih <= JUMLAH_TERSANGKA) {
            wawancaraTersangka(pilih - 1);
        } 
        else if (pilih == 0) {
            clear();
        } 
        else {
            cout << MERAH << "Pilihan tidak valid!\n" << RESET;
            pause();
        }
    } while (pilih != 0);
}

void analisisBukti() {
    clear();
    cout << W_BUKTI << ART_BUKTI << RESET;
    garis();
    for (int i = 0; i < JUMLAH_BUKTI; i++) {
        cout << "\nBUKTI " << i + 1 << "\n"
             << "---------------------------------------------------------\n"
             << "Judul    : " << daftarBukti[i].judul << "\n"
             << "Analisis : " << daftarBukti[i].isi   << "\n";
        daftarBukti[i].ditemukan = true;
    }
    garis();
    cout << HIJAU << "SEMUA BUKTI BERHASIL DIANALISIS\n" << RESET;
    garis();
    semuaBuktiDianalisis = true;
    pause();
    clear();
}

void catatanDetektif() {
    clear();
    cout << W_CATAT << ART_CATATAN << RESET;
    garis();
    int wawancaraSelesai = 0;
    for (int i = 0; i < JUMLAH_TERSANGKA; i++) {
        if (tersangka[i].pernahDitanya) {
            wawancaraSelesai++;
        }
    }
    cout << "Progres wawancara : " << wawancaraSelesai << "/" << JUMLAH_TERSANGKA << " tersangka diperiksa\n"
         << "Status bukti      : " << (semuaBuktiDianalisis ? "Sudah dianalisis" : "Belum dianalisis") << "\n";
    garis();

    for (int i = 0; i < JUMLAH_TERSANGKA; i++) {
        cout << "\nTersangka : " << tersangka[i].nama << "\n";
        bool ada = false;
        for (int j = 0; j < JUMLAH_PERTANYAAN; j++) {
            if (tersangka[i].pernahDitanya[j]) {
                ada = true;
                cout << "\n  T : " << tersangka[i].pertanyaan[j] << "\n"
                     << "  J : "   << tersangka[i].jawaban[j]    << "\n";
            }
        }
        if (!ada) cout << "  (Belum ada pertanyaan yang diajukan.)\n";
        garis();
    }
    pause();
    clear();
    cout << W_CATAT << ART_CATATAN << RESET;
    garis();
    cout << "\nBUKTI YANG SUDAH DIANALISIS :\n";
    bool adaBukti = false;
    for (int i = 0; i < JUMLAH_BUKTI; i++) {
        if (daftarBukti[i].ditemukan) {
            adaBukti = true;
            cout << "- " << daftarBukti[i].judul << "\n  " 
                 << daftarBukti[i].isi << "\n";
        }
    }
    if (!adaBukti) cout << "  (Belum ada bukti yang dianalisis.)\n";
    garis();
    pause();
    clear();
}

void investigasi() {
    int pilih;
    do {
        clear();
        cout << W_INVES << ART_INVESTIGASI << RESET;
        garis();
        cout << "1. Wawancara Tersangka\n"
             << "2. Analisis Bukti\n"
             << "0. Kembali\n";
        garis();
        pilih = bacaAngka("Pilih menu : ");
        switch (pilih) {
            case 1: 
                menuWawancara(); 
                break;
            case 2: 
                analisisBukti(); 
                break;
            case 0: 
                clear(); 
                break;
            default:
                cout << MERAH << "Menu tidak valid!\n" << RESET;
                pause();
        }
    } while (pilih != 0);
}

void tampilEnding() {
    struct Adegan { 
        string narasi; 
    };
    string pembatas = "---------------------------------------------------------\n";

    clear();
    cout << "\n\n"
         << "                  ... hujan masih turun ...\n\n"
         << "              malam itu tidak akan pernah usai\n\n";
    pause();
    clear();

    Adegan cerita[JUMLAH_ADEGAN] = {
        {
            "Polisi mengumpulkan semua tersangka di ruang tamu mansion.\n"
            "Tidak ada yang berani bicara. Hanya suara hujan yang mengetuk\n"
            "jendela, pelan, seolah ikut berkabung. Sang detektif berdiri\n"
            "di tengah ruangan, dan meletakkan berkas-berkas itu di meja."
        },

        {
            "\"Awalnya... kami mengira pelakunya adalah Liam.\"\n\n"
            "Liam menundukkan kepala. Motif, surat ancaman, sidik jari\n"
            "pada botol, rekaman CCTV koridor. Semua menunjuk satu nama.\n"
            "Terlalu rapi. Terlalu sempurna untuk menjadi kebetulan."
        },

        {
            "\"Tapi ada satu hal yang tidak bisa dijelaskan.\"\n\n"
            "Detektif mengangkat gelas korban. \"Racun tidak berasal dari\n"
            "botol minuman. Racun itu ada di dalam ES BATU di gelas David.\"\n\n"
            "Ruangan membeku. Liam menatap kosong, tak lagi mengerti."
        },

        {
            "Sebuah foto rekaman dapur diletakkan di atas meja.\n\n"
            "\"Dan hanya satu orang yang menyentuh es itu sebelum pesta.\"\n\n"
            "Perlahan, satu per satu kepala menoleh ke arah yang sama.\n"
            "Ke arah Lena. Lena, yang masih berdiri tenang di sudut ruangan."
        },

        {
            "Detektif mengeluarkan sebuah kotak tua, usang dimakan waktu.\n"
            "Di dalamnya: dokumen lama, dan selembar foto seorang pria\n"
            "paruh baya yang tersenyum lelah.\n\n"
            "\"Pria ini... adalah ayah Anda.\"\n\n"
            "Untuk pertama kalinya malam itu, wajah Lena retak."
        },

        {
            "\"Belasan tahun lalu ia dipecat dari perusahaan David. Dituduh\n"
            "atas kesalahan yang tak pernah ia perbuat. Hidupnya runtuh.\n"
            "Ia tenggelam dalam depresi, lalu pergi untuk selamanya.\"\n\n"
            "\"Di catatan hariannya hanya ada satu kalimat yang berulang:\n"
            "'Aku tidak bersalah.'\""
        },

        {
            "\"Tujuh tahun Anda bekerja di sisi orang yang menghancurkan\n"
            "ayah Anda. Tujuh tahun tersenyum, melayani, menunggu. Lalu di\n"
            "malam pesta, Anda meletakkan racun itu pada es. David sendiri\n"
            "yang menuangkannya. Anda bahkan tak perlu menyentuhnya.\"\n\n"
            "Itulah mengapa pintu tetap terkunci dari dalam."
        },

        {
            "Hening. Lalu Lena tertawa pelan. Tawa yang patah.\n\n"
            "\"Akhirnya...\"\n\n"
            "Air matanya jatuh tanpa ia tahan lagi.\n\n"
            "\"Tujuh tahun aku menunggu hari ini. Ayahku tidak bersalah.\n"
            "Tapi tidak ada yang peduli. Tidak seorang pun.\"\n\n"
            "\"Aku hanya... ingin seseorang membayar untuk itu.\""
        },

        {
            "Detektif menatapnya lama. Tidak ada kemarahan di matanya.\n"
            "Hanya lelah.\n\n"
            "\"Aku mengerti lukamu. Tapi ini tidak akan mengembalikannya.\"\n\n"
            "Lena tidak menjawab. Ia tahu itu benar. Ia selalu tahu."
        },

        {
            "Dua petugas mendekat. Lena tak melawan. Ia hanya memandang\n"
            "foto ayahnya untuk terakhir kali, lalu tersenyum sangat tipis.\n\n"
            "Saat borgol mengunci pergelangannya, ia berbisik:\n\n"
            "\"Setidaknya sekarang... Ayah bisa beristirahat dengan tenang.\""
        }
    };

    Adegan *ptr = cerita;
    for (int i = 0; i < JUMLAH_ADEGAN; i++) {
        cout << pembatas
             << "\n" << ptr->narasi << "\n\n"
             << pembatas;
        pause();
        clear();
        ptr++;
    }

    string pelaku   = "LENA";
    string *pPelaku = &pelaku;
    cout << "\n\n"
         << "        Pintu mansion tertutup. Hujan belum juga reda.\n\n"
         << "        Malam ini keadilan ditegakkan ...\n"
         << "        tapi tak seorang pun merasa menang.\n\n";
    pause();
    clear();

    cout << "\n\n";
    garis();
    cout << HIJAU << BOLD << "                  K A S U S   D I T U T U P              \n" 
         << RESET;
    garis();
    cout << "\n"
         << "   Pelaku : " << *pPelaku << " - sang asisten yang setia.\n"
         << "   Korban : David Alden.\n\n"
         << "   Seorang ayah difitnah, dan mati membawa luka.\n"
         << "   Seorang anak mencintainya, dan kehilangan segalanya.\n"
         << "   Dan keadilan datang... terlambat tujuh tahun.\n\n";
    garis();

    cout << "\n";
    cout << HIJAU << BOLD << "                      - T A M A T -\n\n" 
         << RESET;
    pause();
}

void tampilEndingGagal() {
    clear();
    garis();
    cout << MERAH << BOLD << "                K A S U S   D I T U T U P   P A K S A\n" 
         << RESET;
    garis();

    cout << "\n"
         << "   Tuduhan Anda meleset terlalu jauh. Tekanan publik memaksa\n"
         << "   kasus ini ditutup tanpa kepastian.\n\n"
         << "   Pelaku sebenarnya, LENA, menyimpan racun itu pada es batu\n"
         << "   di gelas David - balas dendam atas ayahnya yang difitnah.\n"
         << "   Ia melenggang pergi, dan keadilan tak pernah datang.\n\n"
         << "   Seorang detektif sejati membaca bukti, bukan menebak.\n\n";
    garis();

    cout << "\n";
    cout << MERAH << BOLD << "                  - K A S U S   G A G A L -\n\n" 
         << RESET;
    pause();
}

bool tentukanPelaku() {
    bool semuaWawancara = true;
    int totalPertanyaan = 0;

    for (int i = 0; i < JUMLAH_TERSANGKA; i++) {
        int jumlahPertanyaanTersangka = 0;
        for (int q = 0; q < JUMLAH_PERTANYAAN; q++) {
            if (tersangka[i].pernahDitanya[q]) {
                jumlahPertanyaanTersangka++;
                totalPertanyaan++;
            }
        }

        if (jumlahPertanyaanTersangka == 0) {
            semuaWawancara = false;
        }
    }

    if (!semuaWawancara) {
        clear();
        garis();
        cout << KUNING << "Anda harus mewawancarai seluruh tersangka terlebih dahulu.\n" 
             << RESET;
        garis();
        pause();
        clear();
        return false;
    }

    if (!semuaBuktiDianalisis) {
        clear();
        garis();
        cout << KUNING << "Masih ada bukti yang belum dianalisis.\n" 
             << RESET;
        garis();
        pause();
        clear();
        return false;
    }

    const int PELAKU_BENAR = 3; // Lena
    int sisaKesempatan     = 2;
    int skor               = 0;
    bool tertangkap        = false;

    while (sisaKesempatan > 0) {
        clear();
        cout << W_PELAK << ART_PELAKU << RESET;
        garis();
        cout << "Sisa kesempatan menuduh : " << sisaKesempatan << "\n";
        garis();
        cout << "Siapakah pelaku pembunuhan David?\n"
             << "1. Emma Alden\n"
             << "2. Liam\n"
             << "3. Lena\n";
        garis();
        int pilihan = bacaAngka("Tuduhan Anda (1-3) : ");

        if (pilihan == PELAKU_BENAR) {
            garis();
            cout << HIJAU << BOLD << "\nAnalisis Anda benar! Lena adalah pelakunya...\n" 
                 << RESET;
            garis();

            skor += (sisaKesempatan == 2 ? 50 : 25);
            tertangkap = true;
            pause();
            break;
        } 
        else if (pilihan == 1 || pilihan == 2) {
            sisaKesempatan--;
            garis();
            cout << MERAH << "\nTuduhan salah! Bukti tidak mendukung tuduhan itu.\n" 
                 << RESET;
            garis();
            if (sisaKesempatan > 0)
                cout << "Periksa kembali catatan Anda. Sisa kesempatan: " << sisaKesempatan << "\n";
            pause();
        } 
        else {
            garis();
            cout << MERAH << "\nPilihan tidak valid! Masukkan angka 1 sampai 3.\n" 
                 << RESET;
            garis();
            pause();
        }
    }

    if (!tertangkap) {
        tampilEndingGagal();
        return true; 
    }

    clear();
    cout << W_DEDUK << ART_DEDUKSI << RESET;
    garis();
    cout << "Menyebut nama saja tidak cukup. Buktikan deduksi Anda.\n";
    garis();

    cout << "\nBagaimana cara David diracun?\n"
         << "1. Melalui botol minuman\n"
         << "2. Melalui makanan saat makan malam\n"
         << "3. Melalui es batu di dalam gelasnya\n"
         << "4. Melalui asap rokok\n";
    garis();
    int caraJawab = bacaAngka("Jawaban Anda (1-4) : ");

    if (caraJawab == 3) {
        cout << HIJAU << "\nTepat. Racun ada pada es batu, bukan botolnya.\n" 
             << RESET;
        skor += 25;
    } 
    else {
        cout << KUNING << "\nKurang tepat. Forensik menunjukkan racun ada pada es batu.\n" 
             << RESET;
    }
    garis();
    pause();

    clear();
    cout << W_DEDUK << ART_DEDUKSI << RESET;
    garis();
    cout << "Apa motif sebenarnya di balik pembunuhan ini?\n"
         << "1. Ingin mewarisi seluruh harta David\n"
         << "2. Menutupi kasus penggelapan dana\n"
         << "3. Balas dendam atas ayahnya yang difitnah David\n"
         << "4. Cintanya yang ditolak oleh David\n";
    garis();
    int motifJawab = bacaAngka("Jawaban Anda (1-4) : ");

    if (motifJawab == 3) {
        cout << HIJAU << "\nTepat. Ayah Lena dahulu difitnah dan dipecat oleh David.\n" 
             << RESET;
        skor += 25;
    } 
    else {
        cout << KUNING << "\nKurang tepat. Motifnya adalah balas dendam atas sang ayah.\n" 
             << RESET;
    }
    garis();
    pause();

    int bonusTeliti = totalPertanyaan * 2;
    skor += bonusTeliti;

    string rank;
    if (skor >= 110)      rank = "DETEKTIF LEGENDARIS";
    else if (skor >= 85)  rank = "DETEKTIF HANDAL";
    else if (skor >= 60)  rank = "DETEKTIF JUNIOR";
    else                  rank = "DETEKTIF MAGANG";

    clear();
    garis();
    cout << "                   HASIL INVESTIGASI\n";
    garis();
    cout << "Pertanyaan diajukan : " << totalPertanyaan << "/"
         << (JUMLAH_TERSANGKA * JUMLAH_PERTANYAAN)      << "\n"
         << "Skor akhir          : " << HIJAU << BOLD   << skor << RESET << "\n"
         << "Peringkat           : " << CYAN  << BOLD   << rank << RESET << "\n";
    garis();
    pause("Tekan ENTER untuk menyaksikan epilog penutupan kasus...");
    tampilEnding();
    return true; 
}

int inputMenu() {
    cout << W_MENU << ART_MENU << RESET;
    garis();
    cout << "1. Investigasi\n"
         << "2. Catatan Detektif\n"
         << "3. Tentukan Pelaku\n"
         << "0. Keluar\n";
    garis();
    return bacaAngka("Pilih menu : ");
}

int main() {
    intro();
    clear();
    int pilihan;
    do {
        pilihan = inputMenu();
        switch (pilihan) {
            case 1:
                investigasi();
                break;
            case 2:
                catatanDetektif();
                break;
            case 3:
                if (tentukanPelaku()) {
                    pilihan = 0; 
                }
                break;
            case 0:
                garis();
                cout << "Keluar dari permainan...\n";
                garis();
                break;
            default:
                garis();
                cout << MERAH << "Menu tidak valid!\n" << RESET;
                garis();
                pause();
        }
    } while (pilihan != 0);
    return 0;
}