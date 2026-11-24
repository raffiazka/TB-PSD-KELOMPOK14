#include "sipus.h"
#include <iostream>

using namespace std;

int main() {
    int kapBuku = 2;
    int jmlBuku = 0;
    Buku* listBuku = new Buku[kapBuku];

    int kapAnggota = 2;
    int jmlAnggota = 0;
    Anggota* listAnggota = new Anggota[kapAnggota];

    int pilih = -1;

    while (pilih != 0) {
        cout << "\n=== MENU SIPUS (PERPUSTAKAAN MINI) ===" << endl;
        cout << "1. Tambah Buku (F1)" << endl;
        cout << "2. Lihat Daftar Buku (F1)" << endl;
        cout << "3. Ubah Data Buku (F1)" << endl;
        cout << "4. Hapus Data Buku (F1)" << endl;
        cout << "5. Tambah Anggota (F2)" << endl;
        cout << "6. Lihat Daftar Anggota (F2)" << endl;
        cout << "7. Ubah Data Anggota (F2)" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                tambahBuku(listBuku, jmlBuku, kapBuku);
                break;
            case 2:
                lihatBuku(listBuku, jmlBuku);
                break;
            case 3:
                ubahBuku(listBuku, jmlBuku);
                break;
            case 4:
                hapusBuku(listBuku, jmlBuku);
                break;
            case 5:
                tambahAnggota(listAnggota, jmlAnggota, kapAnggota);
                break;
            case 6:
                lihatAnggota(listAnggota, jmlAnggota);
                break;
            case 7:
                ubahAnggota(listAnggota, jmlAnggota);
                break;
            case 0:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Menu tidak ada!" << endl;
                break;
        }
    }

    delete[] listBuku;
    delete[] listAnggota;

    return 0;
}