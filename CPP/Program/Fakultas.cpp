#include <iostream>                                                 // Library untuk input/output
#include <string>                                                   // Library untuk tipe data string
#include <vector>                                                   // Library untuk vector
#include <sstream>                                                  // Library untuk stringstream
#include <algorithm>                                                // Library untuk max()
using namespace std;                                                // Menggunakan namespace std

// ================= FAKULTAS (Composition) =================
class Fakultas {                                                    // Class Fakultas (bukan turunan Manusia)
private:                                                            // Hanya bisa diakses oleh class ini
    string nama;                                                    // Menyimpan nama Fakultas
    Dosen* dekan;                                                   // Dosen yang menjadi dekan (Composition)
    vector<MataKuliah> mataKuliah;                                  // Daftar mata kuliah di Fakultas ini

public:                                                             // Bisa diakses dari luar class
    Fakultas(string nama, Dosen* dekan)                             // Constructor 
        : nama(nama), dekan(dekan) {}                               // Inisialisasi data

    // --- Getter dan Setter ---

    string getNama() { return nama; }                               // Ambil nama Fakultas
    Dosen* getDekan() { return dekan; }                             // Ambil dekan
    vector<MataKuliah> getMataKuliah() { return mataKuliah; }       // Ambil daftar mata kuliah

    void setNama(string n) { nama = n; }                            // Ubah nama Fakultas
    void setDekan(Dosen* k) { dekan = k; }                          // Ubah dekan
    void setMataKuliah(vector<MataKuliah> mk) { mataKuliah = mk; }  // Ubah daftar mata kuliah

    void tambahMataKuliah(MataKuliah mk) {                          // Tambah mata kuliah ke Fakultas
        mataKuliah.push_back(mk);                                   // Tambahkan ke vector
    }

    void display() {                                                // Tampilkan data Fakultas
        vector<string> lines;                                       // Simpan semua baris output

        lines.push_back("FAKULTAS: " + nama);                       // Baris nama Fakultas

        string barisDekan = "Dekan: " + dekan->getNama() + " (ID: " + dekan->getId() + ")";  // Baris dekan
        lines.push_back(barisDekan);                                // Simpan baris dekan

        lines.push_back("Mata Kuliah (" + to_string(mataKuliah.size()) + "):");  // Baris jumlah mata kuliah

        for (size_t i = 0; i < mataKuliah.size(); i++) {            // Loop semua mata kuliah
            stringstream ss;                                        // Stringstream untuk tangkap output
            ss << "  " << (i + 1) << ". ";                          // Nomor mata kuliah
            streambuf* oldBuf = cout.rdbuf(ss.rdbuf());             // Redirect cout ke stringstream
            mataKuliah[i].display();                                // Tampilkan detail mata kuliah
            cout.rdbuf(oldBuf);                                     // Kembalikan cout
            lines.push_back(ss.str());                              // Simpan baris mata kuliah
        }

        // Tampilkan dengan separator 
        cout << "\n" << string(69, '=') << "\n";                    // Separator atas (69 karakter)
        for (const auto& baris : lines) {                           // Loop semua baris
            cout << baris << "\n";                                  // Tampilkan baris
        }
        cout << string(69, '=') << "\n";                            // Separator bawah (69 karakter)
    }
};
