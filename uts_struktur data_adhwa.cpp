#include <iostream>
#include <iomanip>

using namespace std;

struct DetailKaryawan {
    string nama;
    string jabatan;
    double gaji;
    int hariKerja;
    int tanggalLahir[3]; // Array untuk menyimpan tanggal lahir [hari, bulan, tahun]
};

struct Node {
    DetailKaryawan data;
    Node* next;
};

class Karyawan {
private:
    Node* head;
public:
    Karyawan() {
        head = nullptr;
    }

    void tambahKaryawan() {
        Node* newNode = new Node;
        cout << "Nama: ";
        cin.ignore();
        getline(cin , newNode->data.nama);
        cout << "Jabatan: ";
        getline(cin , newNode->data.jabatan);
        cout << "Gaji: ";
        cin >> newNode->data.gaji;
        cout << "Jumlah Hari Masuk Kerja: ";
        cin >> newNode->data.hariKerja;
        cout << "Tanggal Lahir (format: DD MM YYYY): ";
        cin >> newNode->data.tanggalLahir[0] >> newNode->data.tanggalLahir[1] >> newNode->data.tanggalLahir[2];
        newNode->next = head;
        head = newNode;
        cout << "Karyawan berhasil ditambahkan.\n" << endl;
    }

    void cariKaryawan(const string& targetNama) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data.nama == targetNama) {
                cout << "Detail Karyawan:" << endl;
                cout << "\n====================================================\n";
                cout << "Nama: " << current->data.nama << endl;
                cout << "Jabatan: " << current->data.jabatan << endl;
                cout << "Gaji: " << fixed << setprecision(2) << current->data.gaji << endl;
                cout << "Jumlah Hari Masuk Kerja: " << current->data.hariKerja << endl;
                cout << "Tanggal Lahir: " << current->data.tanggalLahir[0] << "/"
                     << current->data.tanggalLahir[1] << "/" << current->data.tanggalLahir[2] << endl;
                cout << "\n====================================================\n";
                return;
            }
            current = current->next;
        }
        cout << "Karyawan tidak ditemukan." << endl;
    }

    void ubahInformasi(const string& targetNama) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data.nama == targetNama) {
              cout << "\n\n====================================================\n";
              cout << "\n=           Edit Data          =\n";
              cout << "\n----------------------------------------------------\n";
              cin.ignore();
              cout << "Nama Baru: ";
              getline(cin, current->data.nama);
              cout << "Jabatan Baru: ";
              getline(cin, current->data.jabatan);
              cout << "Gaji Baru: ";
              cin >> current->data.gaji;
              cout << "Jumlah Hari Masuk Kerja Baru: ";
              cin >> current->data.hariKerja;
              cout << "Tanggal Lahir Baru (format: DD MM YYYY): ";
              cin >> current->data.tanggalLahir[0] >> current->data.tanggalLahir[1] >> current->data.tanggalLahir[2];
              cout << "\n=================================================== \n";
              cout << "Informasi karyawan berhasil diubah." << endl;
              return;
            }
    current = current->next;
  }
  cout << "Karyawan tidak ditemukan." << endl;
}


    void hitungGaji() {
        Node* current = head;
        cout << "\n--------------------------------------------\n";
        while (current != nullptr) {
            double pajak = 0.05; // Pajak penghasilan 5%
            double gajiSetelahPajak = current->data.gaji * (1 - pajak);

            cout << "Gaji " << fixed << setprecision(2) << current->data.nama << " setelah dipotong pajak: " << gajiSetelahPajak << endl;
            current = current->next;
        }
        cout << "\n--------------------------------------------\n";
    }

    void tampilkanLaporan() {
        Node* current = head;
        cout << "Laporan Karyawan:" << endl;
        while (current != nullptr) {
            cout << "\n-------------------------\n";
            cout << "Nama: " << current->data.nama << endl;
            cout << "Jabatan: " << current->data.jabatan << endl;
            cout << "Gaji: " << fixed << setprecision(2) << current->data.gaji << endl;
            cout << "Jumlah Hari Masuk Kerja: " << current->data.hariKerja << endl;
            cout << "Tanggal Lahir: " << current->data.tanggalLahir[0] << "/"
                 << current->data.tanggalLahir[1] << "/" << current->data.tanggalLahir[2] << endl;
            cout << "---------------------------" << endl;
            current = current->next;
        }
    }

    int hitungKaryawanSamaTanggal(int tanggal, int bulan, int tahun) {
        Node* current = head;
        int jumlahKaryawan = 0;
        while (current != nullptr) {
            if (current->data.tanggalLahir[0] == tanggal && current->data.tanggalLahir[1]
                == bulan && current->data.tanggalLahir[2] == tahun) {
                jumlahKaryawan++;
            }
            current = current->next;
        }
        return jumlahKaryawan;
    }
};

int main() {
    Karyawan daftarKaryawan;
    int pilihan;

    do {
        cout << "\n=====================================================\n";
        cout << "\n=               Manajemen Data Karyawan             =\n";
        cout << "\n=====================================================\n";
        cout << "=1. Tambah Karyawan Baru                            =\n";
        cout << "=2. Cari Karyawan                                   =\n";
        cout << "=3. Ubah Informasi Karyawan                         =\n";
        cout << "=4. Hitung Gaji                                     =\n";
        cout << "=5. Tampilkan Laporan Karyawan                      =\n";
        cout << "=6. Hitung Jumlah Karyawan dengan Tanggal Lahir Sama=\n";
        cout << "=7. Keluar                                          =\n";
        cout << "\n====================================================\n";
        cout << "Pilihan (1 s/d 7) : ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            daftarKaryawan.tambahKaryawan();
            break;
        case 2: {
            string namaCari;
            cout << "\nMasukkan nama karyawan yang ingin dicari: ";
            cin.ignore();
            getline(cin , namaCari);
            daftarKaryawan.cariKaryawan(namaCari);
            break;
        }
        case 3: {
            string namaUbah;
            cout << "\nMasukkan nama karyawan yang ingin diubah informasinya: ";
            cin.ignore();
            getline(cin , namaUbah);
            daftarKaryawan.ubahInformasi(namaUbah);
            break;
        }
        case 4:
            daftarKaryawan.hitungGaji();
            break;
        case 5:
            daftarKaryawan.tampilkanLaporan();
            break;
        case 6: {
            int tanggal, bulan, tahun;
            cout << "\nMasukkan tanggal lahir (format: DD MM YYYY): ";
            cin >> tanggal >> bulan >> tahun;
            int jumlahKaryawan = daftarKaryawan.hitungKaryawanSamaTanggal(tanggal, bulan, tahun);
            cout << "\nJumlah karyawan dengan tanggal lahir tersebut: " << jumlahKaryawan << endl;
            break;
        }
        case 7:
            cout << "Program selesai.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
        }
    } while (pilihan != 7);

    return 0;
}
