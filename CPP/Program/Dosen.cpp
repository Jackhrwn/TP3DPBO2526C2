#include <bits/stdc++.h>                                                        // Library standar lengkap C++
using namespace std;                                                            // Menggunakan namespace std

// ====================== DOSEN (Turunan dari Manusia) =======================
class Dosen : public Manusia {                                                  // Dosen mewarisi sifat Manusia
private:                                                                        // Hanya bisa diakses oleh class ini
    string programStudi;                                                        // Menyimpan program studi dosen
    double gaji;                                                                // Menyimpan gaji dosen
    vector<string> mataKuliahDiajar;                                            // Menyimpan kode mata kuliah yang diampu

public:                                                                         // Bisa diakses dari luar class
    Dosen(string nama, string id, int umur, string programStudi, double gaji)   // Constructor
        : Manusia(nama, id, umur), programStudi(programStudi), gaji(gaji) {}    // Inisialisasi data

    // --- Getter dan Setter ---
    string getProgramStudi() { return programStudi; }                           // Ambil program studi
    double getGaji() { return gaji; }                                           // Ambil gaji
    vector<string> getMataKuliahDiajar() { return mataKuliahDiajar; }           // Ambil mata kuliah yang diampu

    void setProgramStudi(string nilai) { programStudi = nilai; }                // Ubah program studi
    void setGaji(double nilai) { gaji = nilai; }                                // Ubah gaji
    void setMataKuliahDiajar(vector<string> mk) { mataKuliahDiajar = mk; }      // Ubah daftar mata kuliah

    void ampuMataKuliah(string kode) {                                          // Catat mata kuliah yang diampu
        mataKuliahDiajar.push_back(kode);                                       // Tambahkan kode ke daftar
    }

    string render(int nomor = 1) {                                              // Susun data dosen dalam bingkai
        vector<string> lines = {                                                // Siapkan baris data dosen
            "[" + to_string(nomor) + "] Dosen",                                 // Tampilkan judul dan nomor dosen
            "    ID Dosen       : " + id,                                       // Tampilkan ID dosen
            "    Nama           : " + nama,                                     // Tampilkan nama dosen
            "    Umur           : " + to_string(umur),                          // Tampilkan umur dosen
            "    Program Studi  : " + programStudi,                             // Tampilkan program studi dosen
            "    Gaji           : Rp" + to_string(static_cast<long long>(gaji)) // Tampilkan gaji dosen
        };
        for (size_t i = 0; i < mataKuliahDiajar.size(); ++i) { // Ulangi seluruh mata kuliah yang diampu
            lines.push_back("    [" + to_string(i + 1) + "] Mata Kuliah Diajar : " + mataKuliahDiajar[i]); // Tampilkan mata kuliah yang diampu
        }
        size_t lebar = 52;                                                      // Gunakan lebar bingkai tetap
        ostringstream output;                                                   // Siapkan aliran untuk merangkai bingkai
        string batas = "+" + string(lebar + 2, '-') + "+";                      // Buat garis batas bingkai
        output << batas << "\n";                                                // Tambahkan batas atas
        for (string& line : lines) output << "| " << left << setw(static_cast<int>(lebar)) << line << " |\n"; // Tambahkan baris isi
        output << batas;                                                        // Tambahkan batas bawah
        return output.str();                                                    // Kembalikan bingkai sebagai teks
    }

    void display(int nomor = 1) { cout << render(nomor) << "\n"; }              // Tampilkan data dosen
};
