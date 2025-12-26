#include "pasien.h"

void createListPenyakit(ListPenyakit &LD) {
    LD.first = NULL;
}

void createListPasien(ListPasien &LD) {
    LD.first = NULL;
}

adrPenyakit newPenyakit(int id, string nama, string kategori) {
    adrPenyakit P = new Penyakit;
    P->idPenyakit = id;
    P->nama = nama;
    P->kategori = kategori;
    P->firstRelasi = NULL;
    P->next = NULL;
    return P;
}

adrPasien newPasien(int id, string nama, int umur) {
    adrPasien P = new Pasien;
    P->idPasien = id;
    P->nama = nama;
    P->umur = umur;
    P->next = NULL;
    return P;
}

adrRelasi newRelasi(adrPasien P) {
    adrRelasi R = new Relasi;
    R->pasien = P;
    R->next = NULL;
    return R;
}

void insertFirstPenyakit(ListPenyakit &LD, adrPenyakit P) {
    P->next = LD.first;
    LD.first = P;
}

void insertLastPenyakit(ListPenyakit &LD, adrPenyakit P) {
    if (LD.first == NULL) {
        LD.first = P;
    } else {
        adrPenyakit Q = LD.first;
        while (Q->next != NULL)
            Q = Q->next;
        Q->next = P;
    }
}

void insertFirstPasien(ListPasien &LP, adrPasien P) {
    P->next = LP.first;
    LP.first = P;
}

void insertLastPasien(ListPasien &LP, adrPasien P) {
    if (LP.first == NULL) {
        LP.first = P;
    } else {
        adrPasien Q = LP.first;
        while (Q->next != NULL)
            Q = Q->next;
        Q->next = P;
    }
}

bool connectPasienPenyakit(adrPenyakit py, adrPasien ps) {
    adrRelasi R = py->firstRelasi;
    while (R != NULL) {
        if (R->pasien == ps) {
            return false;
        }
        R = R->next;
    }

    adrRelasi newR = newRelasi(ps);
    newR->next = py->firstRelasi;
    py->firstRelasi = newR;
    return true;
}

bool deleteRelasiNode(adrPenyakit py, int idPasien) {
    adrRelasi R = py->firstRelasi;
    adrRelasi prev = NULL;
    while (R != NULL) {
        if (R->pasien->idPasien == idPasien) {
            if (prev == NULL)
                py->firstRelasi = R->next;
            else
                prev->next = R->next;
            delete R;
            return true;
        }
        prev = R;
        R = R->next;
    }
    return false;
}

void deleteSemuaRelasiPasien(ListPenyakit &LD, int idPasien) {
    adrPenyakit P = LD.first;
    while (P != NULL) {
        deleteRelasiNode(P, idPasien);
        P = P->next;
    }
}

void deletePenyakit(ListPenyakit &LD, int idPenyakit) {
    adrPenyakit P = LD.first;
    adrPenyakit prev = NULL;
    
    while (P != NULL && P->idPenyakit != idPenyakit) {
        prev = P;
        P = P->next;
    }
    
    if (P == NULL) {
        cout << "Penyakit tidak ditemukan\n";
        return;
    }
    
    adrRelasi R = P->firstRelasi;
    while (R != NULL) {
        adrRelasi temp = R;
        R = R->next;
        delete temp;
    }
    
    if (prev == NULL) {
        LD.first = P->next;
    } else {
        prev->next = P->next;
    }
    
    delete P;
    cout << "Penyakit berhasil dihapus\n";
}

void deletePasien(ListPasien &LP, ListPenyakit &LD, int idPasien) {
    adrPasien P = LP.first;
    adrPasien prev = NULL;
    
    adrPenyakit D = LD.first;
    while (D != NULL) {
        deleteRelasiNode(D, idPasien);
        D = D->next;
    }
    
    while (P != NULL && P->idPasien != idPasien) {
        prev = P;
        P = P->next;
    }
    
    if (P == NULL) {
        cout << "Pasien tidak ditemukan\n";
        return;
    }
    
    if (prev == NULL) {
        LP.first = P->next;
    } else {
        prev->next = P->next;
    }
    
    delete P;
    cout << "Pasien berhasil dihapus\n";
}

void showAllPenyakit(ListPenyakit LD) {
    if (LD.first == NULL) {
        cout << "Data penyakit kosong" << endl;
        return;
    }
    
    adrPenyakit P = LD.first;
    while (P != NULL) {
        cout << "ID Penyakit : " << P->idPenyakit << endl;
        cout << "Nama        : " << P->nama << endl;
        cout << "Kategori    : " << P->kategori << endl;
        cout << "------------------------" << endl;
        P = P->next;
    }
}

void showAllPasien(ListPasien LD) {
    if (LD.first == NULL) {
        cout << "Data pasien kosong" << endl;
        return;
    }
    
    adrPasien P = LD.first;
    while (P != NULL) {
        cout << "ID Pasien : " << P->idPasien << endl;
        cout << "Nama      : " << P->nama << endl;
        cout << "Umur      : " << P->umur << endl;
        cout << "------------------------" << endl;
        P = P->next;
    }
}

adrPenyakit findPenyakit(ListPenyakit LD, int id) {
    adrPenyakit P = LD.first;
    while (P != NULL && P->idPenyakit != id)
    P = P->next;
    return P;
}

adrPasien findPasien(ListPasien LD, int id) {
    adrPasien P = LD.first;
    while (P != NULL && P->idPasien != id)
        P = P->next;
    return P;
}

void showPasienDenganPenyakit(ListPenyakit LD, int idPenyakit) {
    adrPenyakit P = findPenyakit(LD, idPenyakit);
    
    if (P == NULL) {
        cout << "Penyakit tidak ditemukan" << endl;
        return;
    }
    cout << "Daftar Pasien dengan Penyakit "
    << P->nama << " :" << endl;

    adrRelasi R = P->firstRelasi;
    if (R == NULL) {
        cout << "Belum ada pasien" << endl;
        return;
    }

    while (R != NULL) {
        cout << "- " << R->pasien->nama
            << " (Umur " << R->pasien->umur << ")" << endl;
            R = R->next;
    }
}

void showPenyakitDariPasien(ListPenyakit LD, int idPasien) {
    bool ketemu = false;
    adrPenyakit P = LD.first;
    
    cout << "Penyakit yang dimiliki pasien ID "
    << idPasien << " :" << endl;

    while (P != NULL) {
        adrRelasi R = P->firstRelasi;
        while (R != NULL) {
            if (R->pasien->idPasien == idPasien) {
                cout << "- " << P->nama << endl;
                ketemu = true;
                break;
            }
            R = R->next;
        }
        P = P->next;
    }
    
    if (!ketemu) {
        cout << "Pasien tidak memiliki penyakit atau tidak ditemukan" << endl;
    }
}

void showAllPenyakitWithPasien(ListPenyakit LD) {
    adrPenyakit P = LD.first;
    while (P != NULL) {
        cout << "Penyakit: " << P->nama << endl;
        adrRelasi R = P->firstRelasi;
        while (R != NULL) {
            cout << "  - " << R->pasien->nama << endl;
            R = R->next;
        }
        P = P->next;
    }
}

void showAllPasienWithPenyakit(ListPasien LP, ListPenyakit LD) {
    adrPasien P = LP.first;

    while (P != NULL) {
        cout << "Pasien " << P->nama << " : ";

        bool ada = false;
        adrPenyakit Py = LD.first;

        while (Py != NULL) {
            adrRelasi R = Py->firstRelasi;

            while (R != NULL) {
                if (R->pasien == P) {
                    if (ada) cout << ", ";
                    cout << Py->nama;
                    ada = true;
                    break;
                }
                R = R->next;
            }
            Py = Py->next;
        }

        if (!ada) {
            cout << "(tidak ada penyakit)";
        }

        cout << endl;
        P = P->next;
    }
}

int countPasien(adrPenyakit py) {
    int count = 0;
    adrRelasi R = py->firstRelasi;
    while (R != NULL) {
        count++;
        R = R->next;
    }
    return count;
}

void showTop5Penyakit(ListPenyakit LD) {
    if (LD.first == NULL) {
        cout << "Data penyakit kosong\n";
        return;
    }

    StatistikPenyakit data[100];
    int n = 0;

    adrPenyakit P = LD.first;
    while (P != NULL) {
        data[n].nama = P->nama;
        data[n].jumlah = countPasien(P);
        n++;
        P = P->next;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j].jumlah < data[j + 1].jumlah) {
                StatistikPenyakit temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    cout << "Top 5 Penyakit Terbanyak:\n";
    int limit = (n < 5) ? n : 5;
    for (int i = 0; i < limit; i++) {
        cout << i + 1 << ". "
            << data[i].nama
            << " : " << data[i].jumlah
            << " pasien\n";
    }
}

void showJumlahPasienDariPenyakitTertentu(ListPenyakit LD, int idPenyakit) {
    adrPenyakit P = findPenyakit(LD, idPenyakit);

    if (P == NULL) {
        cout << "Penyakit dengan ID " << idPenyakit << " tidak ditemukan\n";
        return;
    }

    int jumlah = countPasien(P);

    cout << "Jumlah pasien dengan penyakit "
        << P->nama
        << " (ID " << idPenyakit << ") : "
        << jumlah << " pasien\n";
}

void showJumlahPasienPerPenyakit(ListPenyakit LD) {
    if (LD.first == NULL) {
        cout << "Data penyakit kosong\n";
        return;
    }

    cout << "Jumlah Pasien per Penyakit:\n";

    adrPenyakit P = LD.first;
    while (P != NULL) {
        cout << "ID " << P->idPenyakit
            << " | " << P->nama
            << " : " << countPasien(P)
            << " pasien\n";
        P = P->next;
    }
}
