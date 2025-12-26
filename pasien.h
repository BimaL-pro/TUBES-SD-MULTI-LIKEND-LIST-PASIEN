#ifndef PASIEN_H
#define PASIEN_H

#include <iostream>
#include <string>
using namespace std;

// POINTER TYPE
typedef struct Penyakit *adrPenyakit;
typedef struct Pasien *adrPasien;
typedef struct Relasi *adrRelasi;

struct Pasien {
    int idPasien;
    string nama;
    int umur;
    adrPasien next;
};

struct Relasi {
    adrPasien pasien;
    adrRelasi next;
};

struct Penyakit {
    int idPenyakit;
    string nama;
    string kategori;
    adrRelasi firstRelasi;
    adrPenyakit next;
};

struct ListPenyakit {
    adrPenyakit first;
};

struct ListPasien {
    adrPasien first;
};

struct StatistikPenyakit {
    string nama;
    int jumlah;
};

////////////////////// FUNCTION SOAL //////////////////////
// Inisialisasi List
void createListPenyakit(ListPenyakit &LD);
void createListPasien(ListPasien &LP);

// Alokasi
adrPenyakit newPenyakit(int id, string nama, string kategori);
adrPasien newPasien(int id, string nama, int umur);
adrRelasi newRelasi(adrPasien P);

// Tambah dari depan / belakang
void insertFirstPenyakit(ListPenyakit &LD, adrPenyakit P);
void insertLastPenyakit(ListPenyakit &LD, adrPenyakit P);
void insertFirstPasien(ListPasien &LP, adrPasien P);
void insertLastPasien(ListPasien &LP, adrPasien P);

// Relasi
bool connectPasienPenyakit(adrPenyakit py, adrPasien ps);

// Delete
bool deleteRelasiNode(adrPenyakit py, int idPasien);
void deleteSemuaRelasiPasien(ListPenyakit &LD, int idPasien);
void deletePasien(ListPasien &LP, ListPenyakit &LD, int idPasien);
void deletePenyakit(ListPenyakit &LD, int idPenyakit);

// Tampilkan semua isi list
void showAllPenyakit(ListPenyakit LD);
void showAllPasien(ListPasien LP);

// Mencari id penyakit / id pasien
adrPenyakit findPenyakit(ListPenyakit LD, int id);
adrPasien findPasien(ListPasien LP, int id);

// Tampilkan berdasarkan id penyakit / id pasien
void showPasienDenganPenyakit(ListPenyakit LD, int idPenyakit);
void showPenyakitDariPasien(ListPenyakit LD, int idPasien);

// Tampilkan semua relasi berdarkan penyakit / pasien
void showAllPenyakitWithPasien(ListPenyakit LD);
void showAllPasienWithPenyakit(ListPasien LP, ListPenyakit LD);

// Utility
int countPasien(adrPenyakit py);
void showTop5Penyakit(ListPenyakit LD);

////////////////////// FUNCTION TUGAS BESAR //////////////////////
void showJumlahPasienDariPenyakitTertentu(ListPenyakit LD, int idPenyakit);
void showJumlahPasienPerPenyakit(ListPenyakit LD);

#endif
