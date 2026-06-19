#include <iostream>
using namespace std;

//PROTOTYPE
void tampilIntro(){
	cout << "Intro\n";
}

void investigasi(){
	cout << "Menu Investigasi\n";
	system("pause"); system("cls");
	return;
}

void daftarTersangka(){
	cout << "Daftar Tersangka\n";
	system("pause"); system("cls");
	return;
}

void tentukanPelaku(){
	cout << "Tentukan pelaku\n";
	system("pause"); system("cls");
	return;
}

void tampilEnding(){
	cout << "ending\n";
}

int inputMenu(){
	int pilihan;
	cout << "\n=== MENU UTAMA ===\n";
	cout << "1. Investigasi\n";
	cout << "2. Daftar Tersangka\n";
	cout << "3. Tentukan Pelaku\n";
	cout << "0. Keluar\n";
	cout << "Pilih menu: ";
	cin >> pilihan;
	
	while (cin.fail()) {
		cin.clear(); cin.ignore(1000, '\n');
		cout << "Input harus berupa angka!\n";
		cout << "Pilih menu: ";
		cin >> pilihan;
	} return pilihan;
}

void menuUtama(){
	tampilIntro();
	system("pause"); system("cls");
	
	int pilihan;
	do {
		pilihan = inputMenu();
		switch(pilihan){
			case 1:
				system("pause"); system("cls");
				investigasi();
				break;
			case 2:
				system("pause"); system("cls");
				daftarTersangka();
				break;
			case 3:
				system("pause"); system("cls");
				tentukanPelaku();
				break;
			case 0:
				cout << "Keluar dari permainan...\n";
				break;
			default:
				cout << "Menu tidak valid!\n";
				cout << "\nTekan ENTER untuk melanjutkan...";
				cin.ignore(); cin.get();
		}
	} while (pilihan != 0);
}

int main(){
	menuUtama();
	return 0;
}