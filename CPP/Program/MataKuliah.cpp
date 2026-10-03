#include <bits/stdc++.h>                                                        // Library standar lengkap C++
using namespace std;                                                            // Menggunakan namespace std

// =================== MATA KULIAH (Bagian dari Fakultas) ====================
class MataKuliah {                                                              // Class mata kuliah (bukan turunan Manusia)
private:                                                                        // Hanya bisa diakses oleh class ini
    string kodeMataKuliah;                                                      // Menyimpan kode mata kuliah
    string namaMataKuliah;                                                      // Menyimpan nama mata kuliah
    int sks;                                                                    // Menyimpan jumlah SKS

public:                                                                         // Bisa diakses dari luar class
    MataKuliah(string kode, string nama, int sks)                               // Constructor
        : kodeMataKuliah(kode), namaMataKuliah(nama), sks(sks) {}               // Inisialisasi data

    // --- Getter dan Setter ---
    string getKodeMataKuliah() { return kodeMataKuliah; }                       // Ambil kode
    string getNamaMataKuliah() { return namaMataKuliah; }                       // Ambil nama
    int getSks() { return sks; }                                                // Ambil SKS

    void setKodeMataKuliah(string kode) { kodeMataKuliah = kode; }              // Ubah kode
    void setNamaMataKuliah(string nama) { namaMataKuliah = nama; }              // Ubah nama
    void setSks(int jumlah) { sks = jumlah; }                                   // Ubah SKS

    void display() {                                                            // Tampilkan data mata kuliah
        cout << left << setw(9) << "Kode" << ": " << setw(9) << kodeMataKuliah  // Tampilkan kode mata kuliah
             << "| " << setw(8) << "Nama" << ": " << setw(26) << namaMataKuliah // Tambahkan nama mata kuliah
             << "| " << setw(4) << "SKS" << ": " << sks;                        // Tampilkan SKS
    }
};
