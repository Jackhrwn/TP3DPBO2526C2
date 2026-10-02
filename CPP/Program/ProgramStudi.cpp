#include <iostream>                                     // Library untuk input/output
#include <string>                                       // Library untuk tipe data string
#include <vector>                                       // Library untuk vector
#include <sstream>                                      // Library untuk stringstream
#include <algorithm>                                    // Library untuk max()
using namespace std;                                    // Menggunakan namespace std

// ================= PROGRAM STUDI (Composition) =================
class ProgramStudi {                                    // Class ProgramStudi (bukan turunan Manusia)
private:                                                // Hanya bisa diakses oleh class ini
    string nama;                                        // Menyimpan nama program studi
    Dosen* ketua;                                       // Dosen yang menjadi ketua (Composition)
    vector<MataKuliah> mataKuliah;                      // Daftar mata kuliah di program studi ini

public:                                                 // Bisa diakses dari luar class
    ProgramStudi(string nama, Dosen* ketua)             // Constructor 
        : nama(nama), ketua(ketua) {}                   // Inisialisasi data

    // --- Getter dan Setter ---

    string getNama() { return nama; }                               // Ambil nama program studi
    Dosen* getKetua() { return ketua; }                             // Ambil ketua
    vector<MataKuliah> getMataKuliah() { return mataKuliah; }       // Ambil daftar mata kuliah

    void setNama(string n) { nama = n; }                            // Ubah nama program studi
    void setKetua(Dosen* k) { ketua = k; }                          // Ubah ketua
    void setMataKuliah(vector<MataKuliah> mk) { mataKuliah = mk; }  // Ubah daftar mata kuliah

    void tambahMataKuliah(MataKuliah mk) {                          // Tambah mata kuliah ke program studi
        mataKuliah.push_back(mk);                                   // Tambahkan ke vector
    }

    void display() {                                                // Tampilkan data program studi
        vector<string> lines;                                       // Simpan semua baris output

        lines.push_back("Program Studi: " + nama);                  // Baris nama program studi

        string barisKetua = "Ketua: " + ketua->getNama() + " (ID: " + ketua->getId() + ")";  // Baris ketua
        lines.push_back(barisKetua);                                // Simpan baris ketua

        lines.push_back("Mata Kuliah (" + to_string(mataKuliah.size()) + "):");  // Baris jumlah mata kuliah

        for (size_t i = 0; i < mataKuliah.size(); i++) {  // Loop semua mata kuliah
            stringstream ss;                              // Stringstream untuk tangkap output
            ss << "  " << (i + 1) << ". ";                // Nomor mata kuliah
            streambuf* oldBuf = cout.rdbuf(ss.rdbuf());   // Redirect cout ke stringstream
            mataKuliah[i].display();                      // Tampilkan detail mata kuliah
            cout.rdbuf(oldBuf);                           // Kembalikan cout
            lines.push_back(ss.str());                    // Simpan baris mata kuliah
        }

        // Tampilkan dengan separator 
        cout << "\n" << string(69, '=') << "\n";          // Separator atas (69 karakter)
        for (const auto& baris : lines) {                 // Loop semua baris
            cout << baris << "\n";                        // Tampilkan baris
        }
        cout << string(69, '=') << "\n";                  // Separator bawah (69 karakter)
    }
};
