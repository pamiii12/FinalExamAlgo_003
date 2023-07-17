#include <iostream>
#include <string>
using namespace std;

struct Node {
	int noMhs;
	string name;
	string Jurusan;
	int TahunMasuk;
	Node* next;
};

const int MAX_MAHASISWA = 100;
int NIM[MAX_MAHASISWA];
string nama[MAX_MAHASISWA];
int tahunMasuk[MAX_MAHASISWA];
int jumlahMahasiswa = 0;

Node* START = NULL;
 
void tambahMahasiswa() {
	int nim;
	string nama;
	string jurusan;
	int thnMasuk;
	Node* nodeBaru = new Node();
	cout << "NIM         : ";
	cin >> nim;
	cout << "Nama        : ";
	cin >> nama;
	cout << "Jurusan     : ";
	cin >> jurusan;
	cout << "Tahun Masuk : ";
	cin >> thnMasuk;
	nodeBaru->noMhs = nim;
	nodeBaru->name = nama;

	if (START == NULL || nim <= START->noMhs) {
		if (START != NULL && nim == START->noMhs)
		{
			cout << "NIM sudah ada" << endl;
			return;
		}

		nodeBaru->next = START;
		START = nodeBaru;
		return;
	}

	Node* previous = START;
	Node* current = START;

	while ((current != NULL) && (nim >= current->noMhs))
	{
		if (nim == current->noMhs)
		{
			cout << "NIM sudah ada" << endl;
			return;
		}
		previous = current;
		current = current->next;
	}

	nodeBaru->next = current;
	previous->next = nodeBaru;
}

void tampilkanSemuaMahasiswa() {
	Node* currentNode = START;
	while (currentNode != NULL) {
		cout << "NIM : " << currentNode->noMhs 
			<< "', Nama : " << currentNode->name 
			<< "', Jurusan : " << currentNode->Jurusan
			<< "', Tahun Masuk : " << currentNode->TahunMasuk << endl;
		currentNode = currentNode->next;
	}
}

void algorithmacariMahasiswaByNIM() {
	int nim;
	cout << "Masukkan NIM : ";
	cin >> nim;
	Node* currentNode = START;
	while (currentNode != NULL) {
		if (currentNode->noMhs == nim) {
			cout << "NIM : " << currentNode->noMhs 
				<< ", Nama : " << currentNode->name 
				<< "', Jurusan : " << currentNode->Jurusan
				<< "', Tahun Masuk : " << currentNode->TahunMasuk << endl;
			return;
		}
		currentNode = currentNode->next;
	}
	cout << "Data tidak ditemukan" << endl;
}


void algorithmaSortByTahunMasuk() {
	int tahunMasuk;
	cout << "tampilkan Tahun Masuk nya : ";
	cin >> tahunMasuk;
	Node* currentNode = START;
	while (currentNode != NULL) {
		if (currentNode->TahunMasuk == tahunMasuk) {
			cout << "NIM : " << currentNode->noMhs
				<< ", Nama : " << currentNode->name
				<< "', Jurusan : " << currentNode->Jurusan 
				<< "', Tahun Masuk : " << currentNode->TahunMasuk << endl;
			return;
		}
		currentNode = currentNode->next;
	}
	cout << "Data tidak ditemukan" << endl;
}

int main() {
	int pilihan;
	do {
		cout << "========== MENU MANAJEMEN DATA MAHASISWA ==========" << endl;
		cout << "1. Tambah Mahasiswa" << endl;
		cout << "2. Tampilkan Semua Mahasiswa" << endl;
		cout << "3. Cari Mahasiswa berdasarkan NIM" << endl;
		cout << "4. Tampilkan Mahasiswa berdasarkan Tahun Masuk" << endl;
		cout << "5. Keluar" << endl;
		cout << "Pilihan: ";
		cin >> pilihan;
		cin.ignore();
		switch (pilihan) {
		case 1:
			tambahMahasiswa();
			break;
		case 2:
			tampilkanSemuaMahasiswa();
			break;
		case 3:
			algorithmacariMahasiswaByNIM();
			break;
		case 4:
			algorithmaSortByTahunMasuk();
			break;
		case 5:
			cout << "Terima kasih! Program selesai." << endl;
			break;
		default:
			cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
		}
		cout << endl;
	} while (pilihan != 5);
	return 0;
}


/* 2. singlelinkedlist
   3. Elements di stack dimasukkan dan dihapus berbasis LIFO(Last In First Ou)
      sedangkan QUEUE Menggunakan FIFO (First In First Out)
   4. jika ingin memakai Elements yg berbasis LIFO (Last In First Out)
   5. a. Sebanyak 9 Struktur
      b. Menggunakan metode inOrder*/
