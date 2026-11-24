#ifndef SIPUS_H
#define SIPUS_H

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Tanggal {
    int tgl;
    int bln;
    int thn;
};

struct Buku {
    string kode;
    string judul;
    string kategori;
    int stok;
    int dipinjam;
};

struct Anggota {
    string id;
    string nama;
    int jmlPinjam;
};

struct Peminjaman {
    string idPinjam;
    string idAnggota;
    string kodeBuku;
    Tanggal tglPinjam;
    bool sudahKembali;
};

void tambahBuku(Buku*& arr, int& jml, int& kap) {
    if (jml == kap) {
        int kapBaru = kap * 2;
        Buku* arrBaru = new Buku[kapBaru];

        for (int i = 0; i < jml; i++) {
            arrBaru[i] = arr[i];
        }

        delete[] arr;
        arr = arrBaru;
        kap = kapBaru;
        cout << "Info: Kapasitas array buku ditambah jadi " << kap << endl;
    }

    Buku dataBaru;
    cout << "Masukkan kode buku (BK-xxx): ";
    cin >> dataBaru.kode;

    if (dataBaru.kode.length() < 4 || dataBaru.kode[0] != 'B' || dataBaru.kode[1] != 'K' || dataBaru.kode[2] != '-') {
        cout << "Kode salah! Harus diawali BK- (contoh: BK-001)" << endl;
        return;
    }

    cin.ignore();
    cout << "Masukkan judul buku: ";
    getline(cin, dataBaru.judul);

    cout << "Masukkan kategori buku: ";
    getline(cin, dataBaru.kategori);

    cout << "Masukkan jumlah stok: ";
    cin >> dataBaru.stok;

    dataBaru.dipinjam = 0;

    arr[jml] = dataBaru;
    jml++;
    cout << "Data buku berhasil disimpan!" << endl;
}

void ubahBuku(Buku* arr, int jml) {
    cout << "\n--- Ubah Data Buku ---" << endl;
    if (jml == 0) {
        cout << "Data buku masih kosong." << endl;
        return;
    }

    string cariKode;
    cout << "Masukkan kode buku yang ingin diubah (BK-xxx): ";
    cin >> cariKode;

    for (int i = 0; i < jml; i++) {
        if (arr[i].kode == cariKode) {
            cout << "Data lama: " << arr[i].judul << " (" << arr[i].kategori << ") | Stok: " << arr[i].stok << endl;

            cin.ignore();
            cout << "Masukkan judul baru: ";
            getline(cin, arr[i].judul);

            cout << "Masukkan kategori baru: ";
            getline(cin, arr[i].kategori);

            cout << "Masukkan stok baru: ";
            cin >> arr[i].stok;

            cout << "Data buku berhasil diubah!" << endl;
            return;
        }
    }

    cout << "Buku dengan kode " << cariKode << " tidak ditemukan!" << endl;
}

void hapusBuku(Buku* arr, int& jml) {
    cout << "\n--- Hapus Data Buku ---" << endl;
    if (jml == 0) {
        cout << "Data buku masih kosong." << endl;
        return;
    }

    string cariKode;
    cout << "Masukkan kode buku yang ingin dihapus (BK-xxx): ";
    cin >> cariKode;

    for (int i = 0; i < jml; i++) {
        if (arr[i].kode == cariKode) {
            if (arr[i].dipinjam > 0) {
                cout << "Gagal! Buku sedang dipinjam dan tidak boleh dihapus." << endl;
                return;
            }

            for (int j = i; j < jml - 1; j++) {
                arr[j] = arr[j + 1];
            }
            jml--;
            cout << "Buku " << cariKode << " berhasil dihapus!" << endl;
            return;
        }
    }

    cout << "Buku dengan kode " << cariKode << " tidak ditemukan!" << endl;
}

void cetakBarisBuku(const Buku& b) {
    cout << "| " << left << setw(8) << b.kode
         << "| " << left << setw(25) << b.judul
         << "| " << left << setw(15) << b.kategori
         << "| " << left << setw(6) << b.stok << "|" << endl;
}

void lihatBuku(const Buku* arr, int jml) {
    cout << "\n--- Daftar Buku Perpustakaan ---" << endl;
    if (jml == 0) {
        cout << "Data buku masih kosong." << endl;
        return;
    }

    cout << "+---------+--------------------------+----------------+-------+" << endl;
    cout << "| Kode    | Judul Buku               | Kategori       | Stok  |" << endl;
    cout << "+---------+--------------------------+----------------+-------+" << endl;
    for (int i = 0; i < jml; i++) {
        cetakBarisBuku(arr[i]);
    }
    cout << "+---------+--------------------------+----------------+-------+" << endl;
}

void tambahAnggota(Anggota*& arr, int& jml, int& kap) {
    if (jml == kap) {
        int kapBaru = kap * 2;
        Anggota* arrBaru = new Anggota[kapBaru];

        for (int i = 0; i < jml; i++) {
            arrBaru[i] = arr[i];
        }

        delete[] arr;
        arr = arrBaru;
        kap = kapBaru;
        cout << "Info: Kapasitas array anggota ditambah jadi " << kap << endl;
    }

    Anggota dataBaru;
    cout << "Masukkan ID anggota (AG-xxx): ";
    cin >> dataBaru.id;

    if (dataBaru.id.length() < 4 || dataBaru.id[0] != 'A' || dataBaru.id[1] != 'G' || dataBaru.id[2] != '-') {
        cout << "ID salah! Harus diawali AG- (contoh: AG-001)" << endl;
        return;
    }

    cin.ignore();
    cout << "Masukkan nama anggota: ";
    getline(cin, dataBaru.nama);

    dataBaru.jmlPinjam = 0;

    arr[jml] = dataBaru;
    jml++;
    cout << "Data anggota berhasil disimpan!" << endl;
}

void ubahAnggota(Anggota* arr, int jml) {
    cout << "\n--- Ubah Data Anggota ---" << endl;
    if (jml == 0) {
        cout << "Data anggota masih kosong." << endl;
        return;
    }

    string cariId;
    cout << "Masukkan ID anggota yang ingin diubah (AG-xxx): ";
    cin >> cariId;

    for (int i = 0; i < jml; i++) {
        if (arr[i].id == cariId) {
            cout << "Nama lama: " << arr[i].nama << endl;

            cin.ignore();
            cout << "Masukkan nama baru: ";
            getline(cin, arr[i].nama);

            cout << "Data anggota berhasil diubah!" << endl;
            return;
        }
    }

    cout << "Anggota dengan ID " << cariId << " tidak ditemukan!" << endl;
}

void cetakBarisAnggota(const Anggota& a) {
    cout << "| " << left << setw(8) << a.id
         << "| " << left << setw(25) << a.nama
         << "| " << left << setw(13) << a.jmlPinjam << "|" << endl;
}

void lihatAnggota(const Anggota* arr, int jml) {
    cout << "\n--- Daftar Anggota Perpustakaan ---" << endl;
    if (jml == 0) {
        cout << "Data anggota masih kosong." << endl;
        return;
    }

    cout << "+---------+--------------------------+--------------+" << endl;
    cout << "| ID      | Nama Anggota             | Jml Pinjam   |" << endl;
    cout << "+---------+--------------------------+--------------+" << endl;
    for (int i = 0; i < jml; i++) {
        cetakBarisAnggota(arr[i]);
    }
    cout << "+---------+--------------------------+--------------+" << endl;
}

#endif