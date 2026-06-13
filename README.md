# 🔍 ClueHunt : A Mystery Solver Game

<p align="center">
  <b>Selamat datang di ClueHunt : A Mystery Solver Game!</b><br>
  Sebuah game investigasi kriminal yang mengajak pemain menjadi seorang detektif untuk mengungkap misteri pembunuhan David Alden.
</p>

---

# 📖 Daftar Isi

- ⁠[Tentang Project](#-tentang-project)
- ⁠[Latar Belakang Cerita](#-latar-belakang-cerita)
- ⁠[Fitur Utama](#-fitur-utama)
- ⁠[Alur Permainan](#-alur-permainan)
- ⁠[Struktur Menu](#-struktur-menu)
- ⁠[Konsep C++ yang Digunakan](#-konsep-c-yang-digunakan)
- ⁠[Cara Menjalankan Program](#-cara-menjalankan-program)

---

# 🎬 Tentang Project

*ClueHunt* adalah game investigasi kriminal berbasis *C++* yang mengajak pemain berperan sebagai detektif untuk mengungkap kematian misterius David Alden. Dengan mengumpulkan bukti, mewawancarai tersangka, dan menganalisis petunjuk yang ada, pemain harus menemukan pelaku sebenarnya di balik kasus pembunuhan yang terjadi di sebuah mansion saat pesta perayaan perusahaan.

---

# 🕵️ Latar Belakang Cerita

David Alden, pendiri perusahaan teknologi terbesar di kota, ditemukan meninggal dunia di ruang kerjanya saat pesta perayaan ulang tahun perusahaan yang ke-25.

Kasus ini menjadi sangat misterius karena:

•⁠  ⁠🚪 Ruangan terkunci dari dalam
•⁠  ⁠🔒 Tidak ada tanda pembobolan
•⁠  ⁠🗡️ Tidak ditemukan senjata pembunuhan
•⁠  ⁠👤 Tidak ada orang asing yang memasuki mansion

Sebagai detektif, pemain harus mengungkap kebenaran di balik kematian David Alden dengan memeriksa seluruh bukti dan tersangka yang ada.

---

# ✨ Fitur Utama

| Fitur | Deskripsi |
|---------|---------|
| 📂 Investigasi Kasus | Menampilkan informasi lengkap mengenai kasus pembunuhan |
| 🎤 Wawancara Tersangka | Pemain dapat mewawancarai seluruh tersangka |
| 🔍 Analisis Bukti | Menampilkan bukti-bukti yang ditemukan selama penyelidikan |
| 👥 Daftar Tersangka | Menampilkan data tersangka beserta hasil wawancara |
| ⚖️ Penentuan Pelaku | Pemain menentukan siapa pelaku berdasarkan bukti yang ada |
| 🏆 Multiple Outcome | Hasil permainan bergantung pada keputusan pemain |
| 🔄 Validasi Menu | Mencegah pemain melanjutkan investigasi tanpa syarat yang diperlukan |

---

# 🎮 Alur Permainan
```text
START
  ↓
Tampilkan Cerita Kasus
  ↓
Menu Utama
  ↓
Investigasi
  ↓
Wawancara Tersangka
   ↓
Analisis Bukti
   ↓
Daftar Tersangka
   ↓
Tentukan Pelaku
   ↓
Benar?
 ┌───────┴───────┐
 │               │
Ya             Tidak
 │               │
Menang       Kembali Investigasi
 │
END
 ⁠

---

# 📋 Struktur Menu

### MENU UTAMA

1. Investigasi
2. Daftar Tersangka
3. Tentukan Pelaku
4. Keluar
 ⁠

### 🔍 Menu Investigasi

1. Wawancara
2. Analisis Bukti
3. Kembali
 ⁠

### 🎤 Menu Wawancara

1. Emma Alden
2. Liam
3. Lena
4. Kembali
 ⁠

### ⚖️ Menu Tentukan Pelaku

⁠ text
1. Emma Alden
2. Liam
3. Lena
 ⁠

---

# 🧩 Daftar Tersangka

## 👩 Emma Alden
•⁠  ⁠Istri korban
•⁠  ⁠Menikah selama 20 tahun
•⁠  ⁠Mengetahui perselingkuhan David
•⁠  ⁠Berpotensi mendapatkan seluruh aset korban

## 👨 Liam
•⁠  ⁠Direktur Keuangan perusahaan
•⁠  ⁠Sahabat korban
•⁠  ⁠Terlibat pemalsuan laporan keuangan
•⁠  ⁠Terancam kehilangan karier

## 👩 Lena
•⁠  ⁠Asisten pribadi korban
•⁠  ⁠Bekerja selama 7 tahun
•⁠  ⁠Menyimpan rahasia masa lalu yang berkaitan dengan ayahnya

---

# 🧪 Bukti yang Ditemukan

•⁠  ⁠📄 Surat ancaman
•⁠  ⁠📹 Rekaman CCTV koridor
•⁠  ⁠💻 Draft email David
•⁠  ⁠🧤 Sidik jari pada botol minuman
•⁠  ⁠🧊 Hasil forensik es batu
•⁠  ⁠📹 Rekaman CCTV dapur
•⁠  ⁠📂 Dokumen lama milik ayah Lena
•⁠  ⁠🪟 Pecahan kaca di dekat jendela

---

# 💻 Konsep C++ yang Digunakan

| Konsep | Implementasi |
|----------|----------|
| string | Menyimpan nama tersangka, dialog, dan petunjuk |
| if - else | Percabangan keputusan pemain |
| switch case | Navigasi menu |
| looping | Pengulangan menu dan validasi input |
| array | Menyimpan data tersangka dan bukti |
| function | Modularisasi setiap fitur program |
| struct | Menyimpan data tersangka dan petunjuk |
| pointer | Pengelolaan data investigasi |
| file handling | Penyimpanan hasil permainan (opsional) |

---

# ⚙️ Cara Menjalankan Program

### Compile Program

⁠ bash
g++ main.cpp -o cluehunt
 ⁠

### Jalankan Program

⁠ bash
./cluehunt
 ⁠

---

<p align="center">
<b>🔍 ClueHunt : A Mystery Solver Game</b><br>
</p>
