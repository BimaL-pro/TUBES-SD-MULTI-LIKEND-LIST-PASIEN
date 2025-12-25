#include "pasien.h"

int main() {
    ListPenyakit LD;
    ListPasien LP;

    createListPenyakit(LD);
    createListPasien(LP);


    //TAMBAH PENYAKIT
    insertLastPenyakit(LD, newPenyakit(101, "Flu", "Ringan"));
    insertLastPenyakit(LD, newPenyakit(102, "Demam", "Ringan"));
    insertLastPenyakit(LD, newPenyakit(103, "Diabetes", "Sedang"));
    insertLastPenyakit(LD, newPenyakit(104, "Hipertensi", "Sedang"));
    insertLastPenyakit(LD, newPenyakit(105, "DBD", "Berat"));
    insertLastPenyakit(LD, newPenyakit(106, "Malaria", "Berat"));

    // (2) TAMBAH PASIEN
    insertLastPasien(LP, newPasien(1, "Andi", 20));
    insertLastPasien(LP, newPasien(2, "Budi", 25));
    insertLastPasien(LP, newPasien(3, "Citra", 30));
    insertLastPasien(LP, newPasien(4, "Dewi", 40));
    insertLastPasien(LP, newPasien(5, "Eka", 35));

    // (3) HUBUNGKAN PASIEN DENGAN PENYAKIT
    connectPasienPenyakit(findPenyakit(LD, 101), findPasien(LP, 1));
    connectPasienPenyakit(findPenyakit(LD, 103), findPasien(LP, 2));
    connectPasienPenyakit(findPenyakit(LD, 103), findPasien(LP, 3));
    connectPasienPenyakit(findPenyakit(LD, 105), findPasien(LP, 4));
    connectPasienPenyakit(findPenyakit(LD, 105), findPasien(LP, 5));
    connectPasienPenyakit(findPenyakit(LD, 101), findPasien(LP, 2));
    connectPasienPenyakit(findPenyakit(LD, 103), findPasien(LP, 2));
    connectPasienPenyakit(findPenyakit(LD, 103), findPasien(LP, 1));
    connectPasienPenyakit(findPenyakit(LD, 105), findPasien(LP, 4));
    connectPasienPenyakit(findPenyakit(LD, 105), findPasien(LP, 5));
    connectPasienPenyakit(findPenyakit(LD, 101), findPasien(LP, 3));
    connectPasienPenyakit(findPenyakit(LD, 101), findPasien(LP, 4));
    connectPasienPenyakit(findPenyakit(LD, 101), findPasien(LP, 5));
    connectPasienPenyakit(findPenyakit(LD, 106), findPasien(LP, 3));
    connectPasienPenyakit(findPenyakit(LD, 105), findPasien(LP, 5));
    connectPasienPenyakit(findPenyakit(LD, 104), findPasien(LP, 5));
    connectPasienPenyakit(findPenyakit(LD, 104), findPasien(LP, 3));
    connectPasienPenyakit(findPenyakit(LD, 104), findPasien(LP, 5));
    connectPasienPenyakit(findPenyakit(LD, 102), findPasien(LP, 1));
    connectPasienPenyakit(findPenyakit(LD, 102), findPasien(LP, 2));
    connectPasienPenyakit(findPenyakit(LD, 102), findPasien(LP, 3));

    // (6) TAMPILKAN SEMUA PENYAKIT
    cout << "\n=== (6) SEMUA PENYAKIT ===\n";
    showAllPenyakit(LD);

    // (7) TAMPILKAN SEMUA PASIEN
    cout << "\n=== (7) SEMUA PASIEN ===\n";
    showAllPasien(LP);

    // (11) TAMPILKAN PENYAKIT BESERTA PASIEN
    cout << "\n=== (11) PENYAKIT + PASIEN ===\n";
    showPenyakitWithPasien(LD);

    // (10) TAMPILKAN PASIEN BESERTA DAFTAR PENYAKIT
    cout << "\n=== (10) PASIEN + DAFTAR PENYAKIT ===\n";
    showPasienDenganDaftarPenyakit(LP, LD);

    // (9) TAMPILKAN PASIEN DENGAN PENYAKIT TERTENTU
    cout << "\n=== (9) PASIEN DENGAN PENYAKIT ID 103 (Diabetes) ===\n";
    showPasienDenganPenyakit(LD, 103);

    // (8) TAMPILKAN PENYAKIT DARI PASIEN TERTENTU
    cout << "\n=== (8) PENYAKIT DARI PASIEN ID 2 (Budi) ===\n";
    showPenyakitDariPasien(LD, 2);

    // (12) TAMPILKAN TOP 5 PENYAKIT TERBANYAK
    cout << "\n=== (12) TOP 5 PENYAKIT ===\n";
    showTop5Penyakit(LD);

    // (5) HAPUS PASIEN
    cout << "\n=== (5) DELETE PASIEN ID 3 (Citra) ===\n";
    deletePasien(LP, LD, 3);

    // (4) HAPUS PENYAKIT
    cout << "\n=== (4) DELETE PENYAKIT ID 102 (Demam) ===\n";
    deletePenyakit(LD, 102);

    // CEK ULANG SETELAH DELETE
    cout << "\n=== CEK DATA SETELAH DELETE ===\n";
    showPenyakitWithPasien(LD);

    cout << "\nPROGRAM SELESAI (SEMUA 12 MENU TERPANGGIL)\n";

    int pilihan;

    do {
        cout << "\n===== MENU DATA PASIEN & PENYAKIT =====\n";
        cout << "1. Tambah Penyakit\n";
        cout << "2. Tambah Pasien\n";
        cout << "3. Hubungkan Pasien dengan Penyakit\n";
        cout << "4. Hapus Penyakit\n";
        cout << "5. Hapus Pasien\n";
        cout << "6. Tampilkan Semua Penyakit\n";
        cout << "7. Tampilkan Semua Pasien\n";
        cout << "8. Tampilkan Pasien dengan Penyakit Tertentu\n";
        cout << "9. Tampilkan Penyakit dari Pasien Tertentu\n";
        cout << "10. Tampilkan Pasien beserta Daftar Penyakit\n";
        cout << "11. Tampilkan Penyakit beserta Pasien\n";
        cout << "12. Tampilkan Top 5 Penyakit Terbanyak\n";
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

            cout << "Nama Penyakit : "; cin >> nama;
            cout << "Kategori      : "; cin >> kategori;

            adrPenyakit P = newPenyakit(id, nama, kategori);
            cout << "Masukkan ke posisi depan atau belakang list? (1=depan, 2=belakang): ";
            int pos; cin >> pos;
            if (pos == 2) {
                insertLastPenyakit(LD, P);
                cout << "Penyakit berhasil ditambahkan\n";
            } else {
                insertFirstPenyakit(LD, P);
                cout << "Penyakit berhasil ditambahkan\n";
            }
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
            cout << "Masukkan ke posisi depan atau belakang list? (1=depan, 2=belakang): ";
            int pos; cin >> pos;
            if (pos == 2) {
                insertLastPasien(LP, P);
                cout << "Pasien berhasil ditambahkan\n";
            } else {
                insertFirstPasien(LP, P);
                cout << "Pasien berhasil ditambahkan\n";
            }
            break;
        }

        case 3: {
            int idPasien, idPenyakit;
            cout << "ID Pasien   : "; cin >> idPasien;
            cout << "ID Penyakit : "; cin >> idPenyakit;

            adrPasien ps = findPasien(LP, idPasien);
            adrPenyakit py = findPenyakit(LD, idPenyakit);

            if (ps != NULL && py != NULL) {
                connectPasienPenyakit(py, ps);
                cout << "Relasi berhasil dibuat\n";
            } else {
                cout << "Pasien atau Penyakit tidak ditemukan\n";
            }
            break;
        }

        case 4: {
            int idPenyakit;
            cout << endl;
            cout << "ID Penyakit yang akan dihapus: ";
            cin >> idPenyakit;
            deletePenyakit(LD, idPenyakit);
            break;
        }

        case 5: {
            int idPasien;
            cout << endl;
            cout << "ID Pasien yang akan dihapus: ";
            cin >> idPasien;
            deletePasien(LP, LD, idPasien);
            break;
        }

        case 6: {
            cout << endl;
            showAllPenyakit(LD);
            break;
        }

        case 7: {
            cout << endl;
            showAllPasien(LP);
            break;
        }

        case 8: {
            int idPasien;
            cout << endl;
            cout << "ID Pasien: ";
            cin >> idPasien;
            showPenyakitDariPasien(LD, idPasien);
            break;
        }

        case 9: {
            int idPenyakit;
            cout << endl;
            cout << "ID Penyakit: ";
            cin >> idPenyakit;
            showPasienDenganPenyakit(LD, idPenyakit);
            break;
        }

        case 10: {
            cout << endl;
            showPenyakitWithPasien(LD);
            break;
        }

        case 11: {
            cout << endl;
            showPasienDenganDaftarPenyakit(LP, LD);
            break;
        }
        case 12: {
            cout << endl;
            showTop5Penyakit(LD);
            break;
        }
        case 0:
            cout << "Terima kasih!\n";
            break;

        default:
            cout << "Pilihan tidak valid\n";
        }

    } while (pilihan != 0);

    return 0;
}
