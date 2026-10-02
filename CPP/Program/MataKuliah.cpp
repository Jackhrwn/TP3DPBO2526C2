#include <iostream>                                     // Library untuk input/output
#include <string>                                       // Library untuk tipe data string
#include <iomanip>                                      // Library untuk setw()
using namespace std;                                    // Menggunakan namespace std

// =================== MATA KULIAH (Composition: has-a Dosen) ====================
class MataKuliah {                                      // Class mata kuliah (bukan turunan Orang)
private:                                                // Hanya bisa diakses oleh class ini
    string kodeMataKuliah;                              // Menyimpan kode mata kuliah
    string namaMataKuliah;                              // Menyimpan nama mata kuliah
    int sks;                                            // Menyimpan jumlah SKS
    Dosen* dosen;                                       // Dosen yang mengajar (Composition)

public:                                                                          // Bisa diakses dari luar class
    MataKuliah(string kode, string nama, int sks, Dosen* dosen)                  // Constructor
        : kodeMataKuliah(kode), namaMataKuliah(nama), sks(sks), dosen(dosen) {}  // Inisialisasi data

    // --- Getter dan Setter ---

    string getKodeMataKuliah() { return kodeMataKuliah; }     // Ambil kode mata kuliah
    string getNamaMataKuliah() { return namaMataKuliah; }     // Ambil nama mata kuliah
    int getSks() { return sks; }                              // Ambil SKS
    Dosen* getDosen() { return dosen; }                       // Ambil dosen

    void setKodeMataKuliah(string k) { kodeMataKuliah = k; }  // Ubah kode mata kuliah
    void setNamaMataKuliah(string n) { namaMataKuliah = n; }  // Ubah nama mata kuliah
    void setSks(int s) { sks = s; }                           // Ubah SKS
    void setDosen(Dosen* d) { dosen = d; }                    // Ubah dosen

    void display() {                                          // Tampilkan data mata kuliah
        cout << left << setw(5) << kodeMataKuliah << "  " << left << setw(12) << namaMataKuliah << " | ";  // Kode + nama 
        cout << "SKS: " << left << setw(1) << sks << " | ";   // SKS 
        cout << "Dosen: ";                                    // Label dosen
        cout << dosen->getNama() << " (" << dosen->getProgramStudi() << ")";  // Nama dan program studi dosen
    }
};
