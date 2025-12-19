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

// Inisialisasi List
void createListPenyakit(ListPenyakit &LD);
void createListPasien(ListPasien &LP);

// Insert Parent
void insertFirstPenyakit(ListPenyakit &LD, adrPenyakit P);
void insertLastPasien(ListPasien &LP, adrPasien P);

// Delete
void deletePasien(ListPasien &LP, ListPenyakit &LD, int idPasien);
void deletePenyakit(ListPenyakit &LD, int idPenyakit);

// Alokasi
adrPenyakit newPenyakit(int id, string nama, string kategori);
adrPasien newPasien(int id, string nama, int umur);
adrRelasi newRelasi(adrPasien P);

// Search
adrPenyakit findPenyakit(ListPenyakit LD, int id);
adrPasien findPasien(ListPasien LP, int id);

// Relasi
void connectPasienPenyakit(adrPenyakit py, adrPasien ps);
void deleteRelasiPasien(adrPenyakit py, int idPasien);

// Show
void showAllPenyakit(ListPenyakit LD);
void showAllPasien(ListPasien LP);
void showPenyakitWithPasien(ListPenyakit LD);
void showPasienDenganPenyakit(ListPenyakit LD, int idPenyakit);
void showPenyakitDariPasien(ListPenyakit LD, int idPasien);

// Utility
int countPasien(adrPenyakit py);
void showTop5Penyakit(ListPenyakit LD);

#endif