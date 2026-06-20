#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void tampilEnding() {

    struct Adegan {
        string narasi;
    };

    
    string garis = "---------------------------------------------------------\n";

   
    system("cls");
    cout << "\n\n";
    cout << "                  ... hujan masih turun ...\n\n";
    cout << "              malam itu tidak akan pernah usai\n\n";
    cin.get();
    system("cls");

   
    Adegan cerita[10] = {
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

    const int JUMLAH_ADEGAN = 10;

    
    Adegan* ptr = cerita;

    for (int i = 0; i < JUMLAH_ADEGAN; i++) {
        cout << garis;
        cout << "\n" << ptr->narasi << "\n\n";
        cout << garis;
        cin.get();
        system("cls");
        ptr++;
    }

   
    string pelaku   = "LENA";
    string* pPelaku = &pelaku;

    cout << "\n\n";
    cout << "        Pintu mansion tertutup. Hujan belum juga reda.\n\n";
    cout << "        Malam ini keadilan ditegakkan ...\n";
    cout << "        tapi tak seorang pun merasa menang.\n\n";
    cin.get();
    system("cls");

    cout << "\n\n";
    cout << garis;
    cout << "                  K A S U S   D I T U T U P              \n";
    cout << garis;
    cout << "\n";
    cout << "   Pelaku : " << *pPelaku << " - sang asisten yang setia.\n";
    cout << "   Korban : David Alden.\n\n";
    cout << "   Seorang ayah difitnah, dan mati membawa luka.\n";
    cout << "   Seorang anak mencintainya, dan kehilangan segalanya.\n";
    cout << "   Dan keadilan datang... terlambat tujuh tahun.\n\n";
    cout << garis;
    cout << "\n";
    cout << "                      - T A M A T -\n\n";
    cin.get();
}

/*  main untuk tes mandiri (boleh dihapus saat digabung)  */
int main() {
    tampilEnding();
    return 0;
}
