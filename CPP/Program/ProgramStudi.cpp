#include <bits/stdc++.h>                                                    // Library standar lengkap C++
using namespace std;                                                        // Menggunakan namespace std

// ================= PROGRAM STUDI (Composition) =================
class ProgramStudi {                                                        // Class program studi
private:                                                                    // Hanya bisa diakses oleh class ini
    string idProgramStudi;                                                  // Menyimpan ID program studi
    string nama;                                                            // Menyimpan nama program studi
    string jenjang;                                                         // Menyimpan jenjang program studi
    vector<MataKuliah> mataKuliah;                                          // Objek mata kuliah milik program studi

public:                                                                     // Bisa diakses dari luar class
    ProgramStudi(string idProgramStudi, string nama, string jenjang)        // Constructor
        : idProgramStudi(idProgramStudi), nama(nama), jenjang(jenjang) {}   // Langsung assign ke atribute

    // --- Getter dan Setter ---
    string getIdProgramStudi() { return idProgramStudi; }                   // Ambil ID program studi
    string getNama() { return nama; }                                       // Ambil nama program studi
    string getJenjang() { return jenjang; }                                 // Ambil jenjang program studi
    vector<MataKuliah> getMataKuliah() { return mataKuliah; }               // Ambil salinan daftar mata kuliah

    void setIdProgramStudi(string nilai) { idProgramStudi = nilai; }        // Ubah ID program studi
    void setNama(string nilai) { nama = nilai; }                            // Ubah nama program studi
    void setJenjang(string nilai) { jenjang = nilai; }                      // Ubah jenjang program studi

    void tambahMataKuliah(MataKuliah mk) {                                  // Tambah mata kuliah ke program studi
        mataKuliah.push_back(mk);                                           // Simpan salinan mata kuliah
    }

};
