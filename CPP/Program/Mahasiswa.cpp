#include <iostream>                                                            // Library untuk input/output
#include <string>                                                              // Library untuk tipe data string
#include <vector>                                                              // Library untuk vector
#include <iomanip>                                                             // Library untuk setw()
using namespace std;                                                           // Menggunakan namespace std

// ======================= MAHASISWA (Turunan dari Manusia) =======================
class Mahasiswa : public Manusia {                                             // Mahasiswa mewarisi sifat Manusia
private:                                                                       // Hanya bisa diakses oleh class ini
    string jurusan;                                                            // Menyimpan jurusan mahasiswa
    double ipk;                                                                // Menyimpan IPK mahasiswa
    vector<string> mataKuliahDiambil;                                          // Menyimpan daftar mata kuliah yang diambil

public:                                                                        // Bisa diakses dari luar class
    Mahasiswa(string nama, string id, int umur, string jurusan, double ipk)    // Constructor
        : Manusia(nama, id, umur), jurusan(jurusan), ipk(ipk) {}               // Inisialisasi data

    // --- Getter dan Setter ---

    string getJurusan() { return jurusan; }                                    // Ambil jurusan
    double getIpk() { return ipk; }                                            // Ambil IPK
    vector<string> getMataKuliahDiambil() { return mataKuliahDiambil; }        // Ambil daftar mata kuliah

    void setJurusan(string j) { jurusan = j; }                                 // Ubah jurusan
    void setIpk(double i) { ipk = i; }                                         // Ubah IPK
    void setMataKuliahDiambil(vector<string> mk) { mataKuliahDiambil = mk; }   // Ubah daftar mata kuliah

    void ambilMataKuliah(string kodeMataKuliah) {                              // Mahasiswa mengambil mata kuliah
        mataKuliahDiambil.push_back(kodeMataKuliah);                           // Tambahkan ke daftar
    }

    void display() {                                                           // Tampilkan data mahasiswa
        cout << "[MAHASISWA] ";                                                // Label mahasiswa
        cout << left << setw(6) << nama << " | ";                              // Nama (lebar 6 + 2 spasi)
        cout << "ID: " << left << setw(3) << id << " | ";                      // ID (lebar 3 + 2 spasi)
        cout << "Umur: " << left << setw(1) << umur << " | ";                  // Umur (lebar 1 + 2 spasi)
        cout << "Jurusan: " << left << setw(10) << jurusan << " | ";           // Jurusan (lebar 10 + 2 spasi)
        cout << "IPK: " << left << setw(2) << ipk;                             // IPK (lebar 2)
        if (!mataKuliahDiambil.empty()) {                                      // Jika ada mata kuliah
            cout << " | Mata Kuliah: ";                                        // Label mata kuliah
            for (size_t i = 0; i < mataKuliahDiambil.size(); i++) {            // Loop semua mata kuliah
                cout << mataKuliahDiambil[i];                                  // Tampilkan kode mata kuliah
                if (i < mataKuliahDiambil.size() - 1) cout << ", ";            // Pemisah antar mata kuliah
            }
        }
    }
};
