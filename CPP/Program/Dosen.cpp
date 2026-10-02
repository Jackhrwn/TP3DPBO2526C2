#include <iostream>                                     // Library untuk input/output
#include <string>                                       // Library untuk tipe data string
#include <vector>                                       // Library untuk vector
#include <iomanip>                                      // Library untuk setw()
using namespace std;                                    // Menggunakan namespace std

// ====================== DOSEN (Turunan dari Manusia) =======================
class Dosen : public Manusia {                          // Dosen mewarisi sifat Manusia
private:                                                // Hanya bisa diakses oleh class ini
    string programStudi;                                // Menyimpan program studi dosen
    double gaji;                                        // Menyimpan gaji dosen
    vector<string> mataKuliahDiajar;                    // Menyimpan daftar mata kuliah yang diajar

public:                                                                             // Bisa diakses dari luar class
    Dosen(string nama, string id, int umur, string programStudi, double gaji)       // Constructor
        : Manusia(nama, id, umur), programStudi(programStudi), gaji(gaji) {}        // Inisialisasi data

    // --- Getter dan Setter ---

    string getProgramStudi() { return programStudi; }                               // Ambil program studi
    double getGaji() { return gaji; }                                               // Ambil gaji
    vector<string> getMataKuliahDiajar() { return mataKuliahDiajar; }               // Ambil daftar mata kuliah

    void setProgramStudi(string d) { programStudi = d; }                            // Ubah program studi
    void setGaji(double g) { gaji = g; }                                            // Ubah gaji
    void setMataKuliahDiajar(vector<string> mk) { mataKuliahDiajar = mk; }          // Ubah daftar mata kuliah

    void ampuMataKuliah(string kodeMataKuliah) {                                    // Dosen mengajar mata kuliah
        mataKuliahDiajar.push_back(kodeMataKuliah);                                 // Tambahkan ke daftar
    }

    void display() {                                                                // Tampilkan data dosen
        cout << "[DOSEN] ";                                                         // Label dosen
        cout << left << setw(11) << nama << " | ";                                  // Nama (lebar 11 + 2 spasi)
        cout << "ID: " << left << setw(3) << id << " | ";                           // ID (lebar 3 + 2 spasi)
        cout << "Umur: " << left << setw(1) << umur << " | ";                       // Umur (lebar 1 + 2 spasi)
        cout << "Program Studi: " << left << setw(13) << programStudi << " | ";     // program studi (lebar 13 + 2 spasi)
        cout << "Gaji: Rp" << left << setw(6) << gaji;                              // Gaji (lebar 6)
        if (!mataKuliahDiajar.empty()) {                                            // Jika ada mata kuliah
            cout << " | Mengajar: ";                                                // Label mengajar
            for (size_t i = 0; i < mataKuliahDiajar.size(); i++) {                  // Loop semua mata kuliah
                cout << mataKuliahDiajar[i];                                        // Tampilkan kode mata kuliah
                if (i < mataKuliahDiajar.size() - 1) cout << ", ";                  // Pemisah antar mata kuliah
            }
        }
    }
};
