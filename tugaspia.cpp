#include <iostream>
#include <string>

using namespace std;

struct Tersangka {
    string nama;
    string motif;
    string alibi;
    string pernyataan;
    bool sudahDiwawancarai;
};

struct Bukti {
    string nama;
    string deskripsi;
    bool sudahDitemukan;
};

void tampilJudul();
void tampilCeritaKasus();
void inisialisasiData(Tersangka daftarTersangka[], Bukti daftarBukti[]);
void menuUtama(Tersangka daftarTersangka[], Bukti daftarBukti[]);

int main() {
    Tersangka daftarTersangka[3];
    Bukti daftarBukti[7];

    inisialisasiData(daftarTersangka, daftarBukti);
    tampilJudul();
    tampilCeritaKasus();
    menuUtama(daftarTersangka, daftarBukti);

    return 0;
}
void tampilJudul() {
    cout << "=========================================================\n";
    cout << "                    C L U E H U N T                      \n";
    cout << "             Murder Mystery Detective Game               \n";
    cout << "=========================================================\n";
    cout << "Tekan ENTER untuk memulai penyelidikan...";
    cin.get(); // Menunggu pemain menekan tombol enter
    cout << endl;
}
void tampilCeritaKasus() {
    cout << "---------------------------------------------------------\n";
    cout << "                     CERITA KASUS                        \n";
    cout << "---------------------------------------------------------\n";
    cout << "Malam itu, badai besar melanda wilayah pinggiran kota.\n";
    cout << "Di sebuah mansion mewah, seorang pengusaha kaya bernama David\n";
    cout << "ditemukan tewas mengenaskan di ruang kerjanya.\n\n";
    cout << "Anda adalah seorang Detektif yang ditugaskan malam ini juga.\n";
    cout << "Mansion telah dikunci, dan ada 3 orang tersangka di dalam rumah:\n";
    cout << "1. Emma Alden (Istri David)\n";
    cout << "2. Liam (Asisten Keuangan David)\n";
    cout << "3. Lena (Pelayan Mansion)\n\n";
    cout << "Gunakan kemampuan analisis Anda untuk memeriksa seluruh bukti\n";
    cout << "dan mewawancarai tersangka sebelum menuduh pembunuh aslinya!\n";
    cout << "---------------------------------------------------------\n";
    cout << "Tekan ENTER untuk masuk ke Menu Utama...";
    cin.get();
    cout << endl;
}
void inisialisasiData(Tersangka daftarTersangka[], Bukti daftarBukti[]) {
    // Data Awal untuk 3 Tersangka
    daftarTersangka[0] = {"Emma Alden", "Perselingkuhan, Warisan", "Di taman belakang", "Memiliki motif warisan & perselingkuhan, namun menyangkal keterlibatan", false};
    daftarTersangka[1] = {"Liam", "Pemalsuan laporan keuangan", "Di ruang makan", "Mengaku punya masalah dengan David, namun menyangkal pembunuhan", false};
    daftarTersangka[2] = {"Lena", "Dendam atas pemecatan ayahnya oleh David", "Menyiapkan dokumen", "Menyimpan dendam karena ayahnya pernah dipecat oleh David", false};

    // Data Awal untuk 7 Barang Bukti
    daftarBukti[0] = {"Surat Ancaman", "Bertuliskan: 'Kau akan membayar semuanya malam ini'. Tulisan tangan mirip Liam.", false};
    daftarBukti[1] = {"Rekaman CCTV Koridor", "Menunjukkan pergerakan tersangka di sekitar waktu kejadian.", false};
    daftarBukti[2] = {"Draft Email David", "Berisi rencana David yang mungkin memicu konflik dengan tersangka.", false};
    daftarBukti[3] = {"Sidik Jari Botol", "Sidik jari Liam ditemukan pada botol yang diduga media pembunuhan.", false};
    daftarBukti[4] = {"Hasil Forensik", "Racun tidak berasal dari botol, melainkan dari media lain (plot twist).", false};
    daftarBukti[5] = {"CCTV Dapur", "Menampilkan Lena berada di freezer sebelum pesta dimulai.", false};
    daftarBukti[6] = {"Dokumen Ayah Lena", "Membuktikan ayah Lena pernah dipecat oleh David (motif dendam).", false};
}
void menuUtama(Tersangka daftarTersangka[], Bukti daftarBukti[]) {
    cout << "\n[Pesan Sistem]: Anda telah berhasil masuk ke fungsi menuUtama().\n";
    cout << "Pondasi data awal array milik Anggota 1 sudah berhasil dimuat.\n";
    cout << "Game Selesai (Program Berakhir dengan Sukses).\n";
}