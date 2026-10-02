#include <iostream>                                     // Library untuk input/output
#include <string>                                       // Library untuk tipe data string
using namespace std;                                    // Menggunakan namespace std

// ============================ MANUSIA (Base Class) ============================
class Manusia {                                         // Class dasar untuk semua orang di universitas
protected:                                              // Hanya bisa diakses oleh class turunan
    string nama;                                        // Menyimpan nama manusia
    string id;                                          // Menyimpan ID manusia
    int umur;                                           // Menyimpan umur manusia

public:                                                 // Bisa diakses dari luar class
    Manusia(string nama, string id, int umur)           // Constructor untuk inisialisasi data
        : nama(nama), id(id), umur(umur) {}             // Langsung assign ke attribute

    // --- Getter dan Setter ---

    string getNama() { return nama; }                   // Ambil nama
    string getId() { return id; }                       // Ambil ID
    int getUmur() { return umur; }                      // Ambil umur

    void setNama(string n) { nama = n; }                // Ubah nama
    void setId(string i) { id = i; }                    // Ubah ID
    void setUmur(int u) { umur = u; }                   // Ubah umur

    void display() {                                    // Tampilkan data manusia
        cout << "Nama: " << nama << " | ID: " << id << " | Umur: " << umur;
    }
};
