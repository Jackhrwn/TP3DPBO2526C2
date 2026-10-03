#include <bits/stdc++.h>                                    // Library standar lengkap C++
using namespace std;                                        // Menggunakan namespace std

// ================= FAKULTAS (Composition) =================
class Fakultas {                                            // Class Fakultas (bukan turunan Manusia)
private:                                                    // Hanya bisa diakses oleh class ini
    string idFakultas;                                      // Menyimpan ID Fakultas
    string nama;                                            // Menyimpan nama Fakultas
    vector<ProgramStudi> programStudi;                      // Objek program studi milik Fakultas

public:                                                     // Bisa diakses dari luar class
    Fakultas(string idFakultas, string nama)                // Constructor
        : idFakultas(idFakultas), nama(nama) {}             // Inisialisasi ID dan nama Fakultas

    // --- Getter dan Setter ---
    string getIdFakultas() { return idFakultas; }           // Ambil ID Fakultas
    string getNama() { return nama; }                       // Ambil nama Fakultas
    vector<ProgramStudi> getProgramStudi() { return programStudi; } // Ambil salinan daftar prodi

    void setIdFakultas(string nilai) { idFakultas = nilai; }// Ubah ID Fakultas
    void setNama(string nilai) { nama = nilai; }            // Ubah nama Fakultas

    void tambahProgramStudi(ProgramStudi prodi) {           // Tambah atau perbarui program studi
        for (ProgramStudi& yangAda : programStudi) {        // Cari program studi berdasarkan ID
            if (yangAda.getIdProgramStudi() == prodi.getIdProgramStudi()) { // Periksa kecocokan ID program studi
                yangAda = prodi;                            // Perbarui program studi
                return;                                     // Hentikan setelah prodi diperbarui
            }
        }
        programStudi.push_back(prodi);                      // Simpan program studi baru
    }

    string render(int nomorFakultas = 1) {                  // Susun Fakultas dengan Program Studi dan Mata Kuliah di dalamnya
        vector<string> lines = {                            // Siapkan baris data Fakultas
            "[" + to_string(nomorFakultas) + "] Fakultas",  // Tampilkan judul dan nomor Fakultas
            "    ID Fakultas   : " + idFakultas,            // Tampilkan ID Fakultas
            "    Nama Fakultas : " + nama,                  // Tampilkan nama Fakultas
            "    Jumlah Prodi  : " + to_string(programStudi.size()) // Tampilkan jumlah program studi
        };
        for (size_t i = 0; i < programStudi.size(); ++i) {  // Ulangi semua program studi
            ProgramStudi& prodi = programStudi[i];          // Ambil program studi saat ini
            lines.push_back("");                            // Pisahkan data antaprogram studi
            lines.push_back("    [" + to_string(i + 1) + "] Program Studi");        // Tampilkan judul dan nomor prodi
            lines.push_back("        ID Prodi   : " + prodi.getIdProgramStudi());   // Tampilkan ID prodi
            lines.push_back("        Nama Prodi : " + prodi.getNama());             // Tampilkan nama prodi
            lines.push_back("        Jenjang    : " + prodi.getJenjang());          // Tampilkan jenjang prodi
            vector<MataKuliah> daftarMK = prodi.getMataKuliah();                    // Ambil salinan daftar mata kuliah
            for (size_t j = 0; j < daftarMK.size(); ++j) {                          // Ulangi seluruh mata kuliah prodi
                lines.push_back("        [" + to_string(j + 1) + "] Mata Kuliah");  // Tampilkan judul dan nomor mata kuliah
                lines.push_back("            ID Matkul   : " + daftarMK[j].getKodeMataKuliah()); // Tampilkan kode mata kuliah
                lines.push_back("            Nama Matkul : " + daftarMK[j].getNamaMataKuliah()); // Tampilkan nama mata kuliah
                lines.push_back("            SKS         : " + to_string(daftarMK[j].getSks())); // Tampilkan jumlah SKS
            }
        }

        size_t lebar = 52;                                  // Gunakan lebar bingkai tetap
        ostringstream output;                               // Siapkan aliran untuk merangkai bingkai
        string batas = "+" + string(lebar + 2, '-') + "+"; // Buat garis batas bingkai
        output << batas << "\n";                            // Tambahkan batas atas
        for (string& line : lines) {                        // Cetak setiap baris dalam bingkai
            output << "| " << left << setw(static_cast<int>(lebar)) << line << " |\n"; // Tambahkan baris isi
        }
        output << batas;                                    // Tambahkan batas bawah
        return output.str();                                // Kembalikan bingkai sebagai teks
    }

    void display(int nomorFakultas = 1) { cout << render(nomorFakultas) << "\n"; } // Tampilkan data Fakultas
};
