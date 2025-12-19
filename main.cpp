#include "pasien.h"

int main() {
    ListPenyakit LD;
    ListPasien LP;

    createListPenyakit(LD);
    createListPasien(LP);

    int pilihan;

    do {
        cout << "\n===== MENU DATA PASIEN & PENYAKIT =====\n";
        cout << "1. Tambah Penyakit\n";
        cout << "2. Tambah Pasien\n";
        cout << "3. Hubungkan Pasien dengan Penyakit\n";
        cout << "4. Tampilkan Semua Penyakit\n";
        cout << "5. Tampilkan Semua Pasien\n";
        cout << "6. Tampilkan Penyakit beserta Pasien\n";
        cout << "7. Tampilkan Pasien dengan Penyakit Tertentu\n";
        cout << "8. Tampilkan Penyakit dari Pasien Tertentu\n";
        cout << "9. Tampilkan Top Penyakit Terbanyak\n";
        cout << "10. Hapus Pasien\n";
        cout << "11. Hapus Penyakit\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1: {
            int id;
            string nama, kategori;
            cout << endl;
            cout << "ID Penyakit   : "; cin >> id;
            cout << "Nama Penyakit : "; cin >> nama;
            cout << "Kategori      : "; cin >> kategori;

            adrPenyakit P = newPenyakit(id, nama, kategori);
            insertFirstPenyakit(LD, P);
            cout << "Penyakit berhasil ditambahkan\n";
            break;
        }

        case 2: {
            int id, umur;
            string nama;
            cout << endl;
            cout << "ID Pasien : "; cin >> id;
            cout << "Nama      : "; cin >> nama;
            cout << "Umur      : "; cin >> umur;

            adrPasien P = newPasien(id, nama, umur);
            insertLastPasien(LP, P);
            cout << "Pasien berhasil ditambahkan\n";
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

        case 4:
            cout << endl;
            showAllPenyakit(LD);
            break;

        case 5:
            cout << endl;
            showAllPasien(LP);
            break;

        case 6:
            cout << endl;
            showPenyakitWithPasien(LD);
            break;

        case 7: {
            int idPenyakit;
            cout << endl;
            cout << "ID Penyakit: ";
            cin >> idPenyakit;
            showPasienDenganPenyakit(LD, idPenyakit);
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
            cout << endl;
            showTop5Penyakit(LD);
            break;
        }

        case 10: {
            int idPasien;
            cout << endl;
            cout << "ID Pasien yang akan dihapus: ";
            cin >> idPasien;
            deletePasien(LP, LD, idPasien);
            break;
        }

        case 11: {
            int idPenyakit;
            cout << endl;
            cout << "ID Penyakit yang akan dihapus: ";
            cin >> idPenyakit;
            deletePenyakit(LD, idPenyakit);
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
