#include "pasien.h"

int main() {
    ListPenyakit LD;
    ListPasien LP;

    createListPenyakit(LD);
    createListPasien(LP);

    insertFirstPenyakit(LD, newPenyakit(101, "Flu", "Ringan"));
    insertLastPenyakit(LD, newPenyakit(102, "Demam", "Ringan"));
    insertFirstPenyakit(LD, newPenyakit(103, "Diabetes", "Sedang"));
    insertFirstPenyakit(LD, newPenyakit(104, "Hipertensi", "Sedang"));
    insertLastPenyakit(LD, newPenyakit(105, "DBD", "Berat"));
    insertLastPenyakit(LD, newPenyakit(106, "Malaria", "Berat"));

    insertLastPasien(LP, newPasien(1, "Andi", 20));
    insertFirstPasien(LP, newPasien(2, "Budi", 25));
    insertLastPasien(LP, newPasien(3, "Citra", 30));
    insertFirstPasien(LP, newPasien(4, "Dewi", 40));
    insertLastPasien(LP, newPasien(5, "Eka", 35));

    connectPasienPenyakit(findPenyakit(LD, 101), findPasien(LP, 1));
    connectPasienPenyakit(findPenyakit(LD, 103), findPasien(LP, 2));
    connectPasienPenyakit(findPenyakit(LD, 103), findPasien(LP, 3));
    connectPasienPenyakit(findPenyakit(LD, 104), findPasien(LP, 4));
    connectPasienPenyakit(findPenyakit(LD, 105), findPasien(LP, 5));
    connectPasienPenyakit(findPenyakit(LD, 101), findPasien(LP, 2));
    connectPasienPenyakit(findPenyakit(LD, 104), findPasien(LP, 2));
    connectPasienPenyakit(findPenyakit(LD, 103), findPasien(LP, 1));
    connectPasienPenyakit(findPenyakit(LD, 105), findPasien(LP, 4));
    connectPasienPenyakit(findPenyakit(LD, 103), findPasien(LP, 5));
    connectPasienPenyakit(findPenyakit(LD, 101), findPasien(LP, 3));
    connectPasienPenyakit(findPenyakit(LD, 101), findPasien(LP, 4));
    connectPasienPenyakit(findPenyakit(LD, 101), findPasien(LP, 5));
    connectPasienPenyakit(findPenyakit(LD, 106), findPasien(LP, 3));
    connectPasienPenyakit(findPenyakit(LD, 104), findPasien(LP, 5));
    connectPasienPenyakit(findPenyakit(LD, 104), findPasien(LP, 3));
    connectPasienPenyakit(findPenyakit(LD, 102), findPasien(LP, 5));
    connectPasienPenyakit(findPenyakit(LD, 102), findPasien(LP, 1));
    connectPasienPenyakit(findPenyakit(LD, 102), findPasien(LP, 2));
    connectPasienPenyakit(findPenyakit(LD, 102), findPasien(LP, 3));

    cout << "\n=== SEMUA PENYAKIT ===\n";
    showAllPenyakit(LD);

    cout << "\n=== SEMUA PASIEN ===\n";
    showAllPasien(LP);

    cout << "\n=== DATA PENYAKIT DENGAN PASIEN-PASIENNYA ===\n";
    showAllPenyakitWithPasien(LD);

    cout << "\n=== DATA PASIEN DENGAN DAFTAR PENYAKITNYA ===\n";
    showAllPasienWithPenyakit(LP, LD);

    cout << "\n=== PASIEN DENGAN PENYAKIT ID 103 (Diabetes) ===\n";
    showPasienDenganPenyakit(LD, 103);

    cout << "\n=== PENYAKIT DARI PASIEN ID 2 (Budi) ===\n";
    showPenyakitDariPasien(LD, 2);

    cout << "\n=== TOP 5 PENYAKIT ===\n";
    showTop5Penyakit(LD);

    cout << "\n=== JUMLAH PASIEN PER PENYAKIT ===\n";
    showJumlahPasienPerPenyakit(LD);

    cout << "\n=== JUMLAH PASIEN DARI PENYAKIT ID 101 (Flu) ===\n";
    showJumlahPasienDariPenyakitTertentu(LD, 101);

    cout << "\n=== DELETE PASIEN ID 3 (Citra) ===\n";
    deletePasien(LP, LD, 3);

    cout << "\n=== HAPUS PENYAKIT ID 102 (Demam) ===\n";
    deletePenyakit(LD, 102);

    cout << "\n=== HAPUS RELASI PASIEN ID 2 DENGAN ID 103  ===\n";
    adrPenyakit py = findPenyakit(LD, 103);
    deleteRelasiNode(py, 2);

    cout << "\n=== HAPUS SEMUA RELASI PASIEN ID 5 (Eka) ===\n";
    deleteSemuaRelasiPasien(LD, 5);

    cout << "\n=== CEK DATA SETELAH DIHAPUS ===\n";
    cout << "\n=== SEMUA PENYAKIT ===\n";
    showAllPenyakit(LD);
    cout << "\n=== SEMUA PASIEN ===\n";
    showAllPasien(LP);
    cout << "\n=== DATA PENYAKIT DENGAN PASIEN-PASIENNYA ===\n";
    showAllPenyakitWithPasien(LD);
    cout << "\n=== DATA PASIEN DENGAN DAFTAR PENYAKITNYA ===\n";
    showAllPasienWithPenyakit(LP, LD);
    cout << "\n=== TOP 5 PENYAKIT ===\n";
    showTop5Penyakit(LD);
    cout << "\n=== JUMLAH PASIEN PER PENYAKIT ===\n";
    showJumlahPasienPerPenyakit(LD);
    cout << "\n=== JUMLAH PASIEN DARI PENYAKIT ID 101 (Flu) ===\n";
    showJumlahPasienDariPenyakitTertentu(LD, 101);

    cout << "\nPROGRAM PEAMNGGILAN OTOMATIS SELESAI\n";

    while (true) {
        cout << "\nMULAI PROGRAM MANUAL? [1(ya), 0(tidak)]: ";

        int menu; cin >> menu;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');              
            cout << "Input harus berupa angka!\n";
            continue;
        }

        switch (menu) {
        case 1: {
            int pilihan;

            do {
                cout << "\n===== MENU DATA PASIEN & PENYAKIT =====\n";
                cout << "1. Tambah Penyakit\n";
                cout << "2. Tambah Pasien\n";
                cout << "3. Hubungkan Pasien dengan Penyakit\n";
                cout << "4. Hapus Relasi Pasien dengan Penyakit\n";
                cout << "5. Hapus Semua Relasi Pasien dengan Penyakit\n";
                cout << "6. Hapus Penyakit\n";
                cout << "7. Hapus Pasien\n";
                cout << "8. Tampilkan Semua Penyakit\n";
                cout << "9. Tampilkan Semua Pasien\n";
                cout << "10. Tampilkan Penyakit dari Pasien Tertentu\n";
                cout << "11. Tampilkan Pasien dengan Penyakit Tertentu\n";
                cout << "12. Tampilkan Penyakit beserta Pasien\n";
                cout << "13. Tampilkan Pasien beserta Daftar Penyakit\n";
                cout << "14. Tampilkan Top 5 Penyakit Terbanyak\n";
                cout << "15. Tampilkan Jumlah Pasien per Penyakit\n";
                cout << "16. Tampilkan Jumlah Pasien dari Penyakit Tertentu\n";
                cout << "0. Keluar\n";
                cout << "Pilih menu: ";
                cin >> pilihan;

                switch (pilihan) {
                case 1: {
                    int id;
                    string nama, kategori;
                    cout << endl;

                    do {
                        cout << "ID Penyakit   : "; cin >> id;
                        if (findPenyakit(LD, id) != NULL) {
                            cout << "ID Penyakit sudah digunakan, masukkan ID lain!\n";
                        }
                    } while (findPenyakit(LD, id) != NULL);

                    cout << "Nama Penyakit                         : "; cin >> nama;
                    cout << "Kategori (Ringan, Sedang, Berat)      : "; cin >> kategori;

                    adrPenyakit P = newPenyakit(id, nama, kategori);

                    int pos;

                    do {
                        cout << "Masukkan ke posisi depan atau belakang list? (1=depan, 2=belakang): ";
                        cin >> pos;

                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(1000, '\n');              
                            cout << "Input harus berupa angka!\n";
                            continue;
                        }

                        if (pos == 2) {
                            insertLastPenyakit(LD, P);
                            cout << "Penyakit berhasil ditambahkan\n";
                        } else if (pos == 1) {
                            insertFirstPenyakit(LD, P);
                            cout << "Penyakit berhasil ditambahkan\n";
                        } else {
                            cout << "Posisi tidak valid, penyakit tidak ditambahkan\n";
                        }
                    } while (pos != 1 && pos != 2);
                    break;
                }
                case 2: {
                    int id, umur;
                    string nama;
                    cout << endl;
                    do {
                        cout << "ID Pasien : "; cin >> id;
                        if (findPasien(LP, id) != NULL) {
                            cout << "ID Pasien sudah digunakan, masukkan ID lain!\n";
                        }
                    } while (findPasien(LP, id) != NULL);

                    cout << "Nama      : "; cin >> nama;
                    cout << "Umur      : "; cin >> umur;

                    adrPasien P = newPasien(id, nama, umur);
                    
                    int pos;
                    
                    do {
                        cout << "Masukkan ke posisi depan atau belakang list? (1=depan, 2=belakang): ";
                        cin >> pos;

                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(1000, '\n');              
                            cout << "Input harus berupa angka!\n";
                            continue;
                        }

                        if (pos == 2) {
                            insertLastPasien(LP, P);
                            cout << "Pasien berhasil ditambahkan\n";
                        } else if (pos == 1) {
                            insertFirstPasien(LP, P);
                            cout << "Pasien berhasil ditambahkan\n";
                        } else {
                            cout << "Posisi tidak valid, pasien tidak ditambahkan\n";
                        }
                    } while (pos != 1 && pos != 2);
                    break;
                }
                case 3: {
                    int idPasien, idPenyakit;
                    cout << "ID Pasien   : "; cin >> idPasien;
                    cout << "ID Penyakit : "; cin >> idPenyakit;

                    adrPasien ps = findPasien(LP, idPasien);
                    adrPenyakit py = findPenyakit(LD, idPenyakit);

                    if (ps != NULL && py != NULL) {
                        if (connectPasienPenyakit(py, ps)) {
                            cout << "Relasi berhasil dibuat\n";
                        } else {
                            cout << "Relasi sudah ada\n";
                        }
                    } else if (ps == NULL) {
                        cout << "ID Pasien tidak ditemukan\n";
                    } else if (py == NULL) {
                        cout << "ID Penyakit tidak ditemukan\n";
                    } else {
                        cout << "ID Pasien dan ID Penyakit tidak ditemukan\n";
                    }
                    break;
                }
                case 4: {
                    int idPasien, idPenyakit;
                    cout << "ID Pasien   : ";
                    cin >> idPasien;

                    if (cin.fail()) {
                            cin.clear();
                            cin.ignore(1000, '\n');              
                            cout << "Input harus berupa angka!\n";
                            continue;
                        }

                    cout << "ID Penyakit : ";
                    cin >> idPenyakit;

                    if (cin.fail()) {
                            cin.clear();
                            cin.ignore(1000, '\n');              
                            cout << "Input harus berupa angka!\n";
                            continue;
                        }

                    adrPenyakit py = findPenyakit(LD, idPenyakit);
                    adrPasien ps = findPasien(LP, idPasien);

                    if (py == NULL) {
                        cout << "Penyakit tidak ditemukan\n";
                    } else if (ps == NULL) {
                        cout << "Pasien tidak ditemukan\n";
                    } else {
                        bool sukses = deleteRelasiNode(py, idPasien);
                        if (sukses) {
                            cout << "Relasi pasien dengan penyakit berhasil dihapus\n";
                        } else {
                            cout << "Relasi pasien dengan penyakit tidak ditemukan\n";
                        }
                    }
                    break;
                }
                case 5: {
                    int idPasien;
                    cout << "ID Pasien yang akan dihapus: ";
                    cin >> idPasien;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');              
                        cout << "Input harus berupa angka!\n";
                        continue;
                    }

                    if (findPasien(LP, idPasien) == NULL) {
                        cout << "Pasien tidak ditemukan\n";
                        break;
                    }
                    
                    deleteSemuaRelasiPasien(LD, idPasien);
                    break;
                }
                case 6: {
                    int idPenyakit;
                    cout << endl;
                    cout << "ID Penyakit yang akan dihapus: ";
                    cin >> idPenyakit;
                    deletePenyakit(LD, idPenyakit);
                    break;
                }
                case 7: {
                    int idPasien;
                    cout << endl;
                    cout << "ID Pasien yang akan dihapus: ";
                    cin >> idPasien;
                    deletePasien(LP, LD, idPasien);
                    break;
                }
                case 8: {
                    cout << endl;
                    showAllPenyakit(LD);
                    break;
                }
                case 9: {
                    cout << endl;
                    showAllPasien(LP);
                    break;
                }
                case 10: {
                    int idPasien;
                    cout << endl;
                    cout << "ID Pasien: ";
                    cin >> idPasien;
                    showPenyakitDariPasien(LD, idPasien);
                    break;
                }
                case 11: {
                    int idPenyakit;
                    cout << endl;
                    cout << "ID Penyakit: ";
                    cin >> idPenyakit;
                    showPasienDenganPenyakit(LD, idPenyakit);
                    break;
                }
                case 12: {
                    cout << endl;
                    showAllPenyakitWithPasien(LD);
                    break;
                }
                case 13: {
                    cout << endl;
                    showAllPasienWithPenyakit(LP, LD);
                    break;
                }
                case 14: {
                    cout << endl;
                    showTop5Penyakit(LD);
                    break;
                }
                case 15: {
                    cout << endl;
                    showJumlahPasienPerPenyakit(LD);
                    break;
                }
                case 16: {
                    int idPenyakit;
                    cout << endl;
                    cout << "ID Penyakit: ";
                    cin >> idPenyakit;
                    showJumlahPasienDariPenyakitTertentu(LD, idPenyakit);
                    break;
                }
                case 0:
                    cout << "\nPROGRAM SELESAI.\n";
                    return 0;
                default:
                    cout << "Pilihan tidak valid\n";
                }

            } while (pilihan != 0);
            break;
        }
        case 0:
            cout << "\nPROGRAM SELESAI.\n";
            return 0;
            
        default:
            cout << "\nPilihan tidak valid.\n";
        }
    }
}
