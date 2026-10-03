#include <bits/stdc++.h>                                                         // Library standar lengkap C++
using namespace std;                                                             // Menggunakan namespace std

// ======================= MAHASISWA (Turunan dari Manusia) =======================
class Mahasiswa : public Manusia {                                               // Mahasiswa mewarisi sifat Manusia
private:                                                                         // Hanya bisa diakses oleh class ini
    string programStudi;                                                         // Menyimpan program studi mahasiswa
    double ipk;                                                                  // Menyimpan IPK mahasiswa
    vector<string> mataKuliahDiambil;                                            // Menyimpan daftar mata kuliah yang diambil

public:                                                                          // Bisa diakses dari luar class
    Mahasiswa(string nama, string id, int umur, string programStudi, double ipk) // Constructor
        : Manusia(nama, id, umur), programStudi(programStudi), ipk(ipk) {}       // Inisialisasi data

    // --- Getter dan Setter ---
    string getProgramStudi() { return programStudi; }                            // Ambil program studi
    double getIpk() { return ipk; }                                              // Ambil IPK
    vector<string> getMataKuliahDiambil() { return mataKuliahDiambil; }          // Ambil daftar mata kuliah

    void setProgramStudi(string nilai) { programStudi = nilai; }                 // Ubah program studi
    void setIpk(double i) { ipk = i; }                                           // Ubah IPK
    void setMataKuliahDiambil(vector<string> mk) { mataKuliahDiambil = mk; }     // Ubah daftar mata kuliah

    void ambilMataKuliah(string kodeMataKuliah) {                                // Mahasiswa mengambil mata kuliah
        mataKuliahDiambil.push_back(kodeMataKuliah);                             // Tambahkan ke daftar
    }

    string render(int nomor = 1) {                                               // Susun data mahasiswa dalam bingkai
        ostringstream formatIPK;                                                 // Siapkan aliran untuk memformat IPK
        formatIPK << fixed << setprecision(2) << ipk;                            // Format IPK dengan dua angka desimal
        vector<string> lines = {                                                 // Siapkan baris data mahasiswa
            "[" + to_string(nomor) + "] Mahasiswa",                              // Tampilkan judul dan nomor mahasiswa
            "    ID Mahasiswa  : " + id,                                         // Tampilkan ID mahasiswa
            "    Nama          : " + nama,                                       // Tampilkan nama mahasiswa
            "    Umur          : " + to_string(umur),                            // Tampilkan umur mahasiswa
            "    Program Studi : " + programStudi,                               // Tampilkan program studi mahasiswa
            "    IPK           : " + formatIPK.str()                             // Tampilkan IPK terformat
        };
        for (size_t i = 0; i < mataKuliahDiambil.size(); ++i) { // Ulangi seluruh mata kuliah yang diambil
            lines.push_back("    [" + to_string(i + 1) + "] Mata Kuliah Diambil : " + mataKuliahDiambil[i]); // Tampilkan mata kuliah yang diambil
        }                                                                        // Selesaikan perulangan mata kuliah
        size_t lebar = 52;                                                       // Gunakan lebar bingkai tetap
        ostringstream output;                                                    // Siapkan aliran untuk merangkai bingkai
        string batas = "+" + string(lebar + 2, '-') + "+";                       // Buat garis batas bingkai
        output << batas << "\n";                                                 // Tambahkan batas atas
        for (string& line : lines) output << "| " << left << setw(static_cast<int>(lebar)) << line << " |\n"; // Tambahkan baris isi
        output << batas;                                                         // Tambahkan batas bawah
        return output.str();                                                     // Kembalikan bingkai sebagai teks
    }

    void display(int nomor = 1) { cout << render(nomor) << "\n"; } // Tampilkan data mahasiswa
};
