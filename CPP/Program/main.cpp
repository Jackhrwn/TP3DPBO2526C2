#include "Manusia.cpp"                                              // Include class Manusia
#include "Dosen.cpp"                                                // Include class Dosen
#include "Mahasiswa.cpp"                                            // Include class Mahasiswa
#include "MataKuliah.cpp"                                           // Include class MataKuliah
#include "ProgramStudi.cpp"                                         // Include class ProgramStudi
#include "Fakultas.cpp"                                             // Include class Fakultas

void tampilkanGabungan(vector<string> kartu) {                      // Tampilkan beberapa bingkai dengan satu garis pemisah
    vector<vector<string>> isiKartu;                                // Simpan baris data dari setiap kartu
    size_t lebar = 52;                                              // Gunakan lebar tetap untuk semua bingkai
    for (string& kartuData : kartu) {                               // Proses setiap bingkai data
        vector<string> barisKartu;                                  // Siapkan baris untuk satu bingkai
        istringstream input(kartuData);                             // Siapkan aliran untuk membaca bingkai
        string baris;                                               // Simpan baris yang sedang dibaca
        while (getline(input, baris)) {                             // Baca isi bingkai baris demi baris
            if (baris.size() < 4 || baris.front() != '|') continue; // Lewati baris selain isi bingkai
            size_t awal = baris.find("| ");                         // Temukan awal teks di dalam bingkai
            size_t akhir = baris.rfind(" |");                       // Temukan akhir teks di dalam bingkai
            if (awal == string::npos || akhir == string::npos || akhir < awal + 2) continue; // Lewati format baris tidak valid
            string isi = baris.substr(awal + 2, akhir - awal - 2);  // Ambil teks tanpa karakter bingkai
            size_t akhirIsi = isi.find_last_not_of(' ');            // Cari karakter terakhir selain spasi
            if (akhirIsi != string::npos) isi.erase(akhirIsi + 1);  // Hilangkan spasi tambahan di akhir isi
            barisKartu.push_back(isi);                              // Simpan baris isi kartu
        }
        isiKartu.push_back(barisKartu);                             // Simpan seluruh baris kartu
    }

    string batas = "+" + string(lebar + 2, '-') + "+";              // Buat garis batas sesuai lebar isi
    cout << batas << "\n";                                          // Tampilkan batas atas bingkai gabungan
    for (size_t i = 0; i < isiKartu.size(); ++i) {                  // Tampilkan setiap kartu secara berurutan
        for (string& baris : isiKartu[i]) {                         // Tampilkan semua baris pada kartu
            cout << "| " << left << setw(static_cast<int>(lebar)) << baris << " |\n"; // Cetak isi yang rata kiri
        }
        if (i + 1 < isiKartu.size()) cout << batas << "\n";         // Pisahkan kartu dengan satu garis
    }
    cout << batas << "\n";                                          // Tampilkan batas bawah bingkai gabungan
}

// =================================== MAIN ===================================
int main() {                                                        // Fungsi utama program
    cout << string(50, '=') << "\n";                                // Separator atas
    cout << "           SISTEM MANAJEMEN UNIVERSITAS\n";            // Judul program
    cout << string(50, '=') << "\n\n";                              // Separator bawah judul

    // --- Buat Fakultas ---
    Fakultas fakMIPA("F001", "FPMIPA");                             // Fakultas FPMIPA
    Fakultas fakPOK("F002", "FPOK");                                // Fakultas FPOK

    // --- Buat Program Studi ---
    ProgramStudi prodiIlkom("PS001", "Ilmu Komputer", "S1");        // Program Studi Ilmu Komputer
    ProgramStudi prodiMatematika("PS002", "Matematika", "S1");      // Program Studi Matematika
    ProgramStudi prodiPKO("PS003", "PKO", "S1");                    // Program Studi PKO

    // --- Buat Mata Kuliah ---
    MataKuliah mk1("ILK101", "Dasar Pemrograman", 3);               // MK pertama
    MataKuliah mk2("MTK101", "Statistika Dasar", 3);                // MK kedua
    MataKuliah mk3("MTK201", "Kalkulus I", 4);                      // MK ketiga
    MataKuliah mk4("PJK101", "Pendidikan Jasmani", 3);              // MK keempat
    prodiIlkom.tambahMataKuliah(mk1);                               // Tambah mk1 ke prodiIlkom
    prodiMatematika.tambahMataKuliah(mk2);                          // Tambah mk2 ke prodiMatematika
    prodiMatematika.tambahMataKuliah(mk3);                          // Tambah mk3 ke prodiMatematika
    prodiPKO.tambahMataKuliah(mk4);                                 // Tambah mk4 ke prodiPKO

    // --- Buat Dosen ---
    Dosen dosen1("Bu Rosa", "D001", 45, "Ilmu Komputer", 850000);   // Dosen pertama
    Dosen dosen2("Pak Yudi", "D002", 50, "PKO", 900000);            // Dosen kedua
    Dosen dosen3("Pak Budi", "D003", 55, "Matematika", 950000);     // Dosen ketiga
    dosen1.ampuMataKuliah("ILK101");                                // dosen1 mengampu ILK101
    dosen2.ampuMataKuliah("PJK101");                                // dosen2 mengampu PJK101
    dosen3.ampuMataKuliah("MTK101");                                // dosen3 mengampu MIPA101
    dosen3.ampuMataKuliah("MTK201");                                // dosen3 mengampu MIPA201

    // --- Susun program studi ke Fakultas ---
    fakMIPA.tambahProgramStudi(prodiIlkom);                         // Tambah prodiIlkom ke FPMIPA
    fakMIPA.tambahProgramStudi(prodiMatematika);                    // Tambah prodiMatematika ke FPMIPA
    fakPOK.tambahProgramStudi(prodiPKO);                            // Tambah prodiPKO ke FPOK

    // --- Buat Mahasiswa ---
    Mahasiswa mhs1("Bentar", "M001", 20, "Ilmu Komputer", 3.8);     // Mahasiswa pertama
    Mahasiswa mhs2("Rian", "M002", 19, "PKO", 3.9);                 // Mahasiswa kedua
    mhs1.ambilMataKuliah("ILK101");                                 // mhs1 mengambil ILK101
    mhs2.ambilMataKuliah("PJK101");                                 // mhs2 mengambil PJK101

    // ========================= TAMPILKAN SEBELUM MENAMBAH ==========================
    cout << ">>> DATA SEBELUM DITAMBAHKAN <<<\n\n";                 // Label sebelum menambah

    cout << "--- FAKULTAS, PROGRAM STUDI, DAN MATA KULIAH ---\n";   // Label hierarki akademik
    tampilkanGabungan({fakMIPA.render(1), fakPOK.render(2)});       // Tampilkan hierarki dalam satu bingkai

    cout << "\n--- DOSEN ---\n";                                    // Label dosen
    tampilkanGabungan({dosen1.render(1), dosen2.render(2), dosen3.render(3)}); // Tampilkan dosen dalam satu bingkai

    cout << "\n--- MAHASISWA ---\n";                                // Label mahasiswa
    tampilkanGabungan({mhs1.render(1), mhs2.render(2)});            // Tampilkan mahasiswa dalam satu bingkai

    // =============================== TAMBAH DATA BARU ===============================
    cout << "\n>>> MENAMBAHKAN DATA BARU <<<\n\n";                  // Label menambah data

    // --- Buat Fakultas baru ---
    Fakultas fakFIP("F003", "FIP");                                 // Fakultas FIP
    cout << left << setw(22) << "Fakultas baru" << ": F003 - FIP\n";// Tampilkan ringkasan Fakultas baru

    // --- Buat Program Studi baru ---
    ProgramStudi prodiPGSD("PS004", "Pendidikan Guru SD", "S1");    // Program Studi Pendidikan Guru SD
    cout << left << setw(22) << "Program studi baru" << ": PS004 - Pendidikan Guru SD (S1)\n"; // Tampilkan ringkasan prodi baru

    // --- Buat Mata Kuliah baru ---
    MataKuliah mk5("PGSD101", "Landasan Pendidikan", 4);            // MK kelima
    MataKuliah mk6("PGSD201", "Bimbingan Konseling", 3);            // MK keenam
    MataKuliah mk7("MTK301", "Kalkulus II", 3);                     // MK ketujuh
    prodiPGSD.tambahMataKuliah(mk5);                                // Tambah mk5 ke prodiPGSD
    cout << left << setw(22) << "Mata kuliah baru" << ": PGSD101 - Landasan Pendidikan (4 SKS)\n"; // Tampilkan mata kuliah baru
    prodiPGSD.tambahMataKuliah(mk6);                                // Tambah mk6 ke prodiPGSD
    cout << left << setw(22) << "" << ": PGSD201 - Bimbingan Konseling (3 SKS)\n"; // Tampilkan mata kuliah tambahan
    prodiMatematika.tambahMataKuliah(mk7);                          // Tambah mk7 ke prodiMatematika
    cout << left << setw(22) << "" << ": MTK301 - Kalkulus II (3 SKS)\n"; // Tampilkan mata kuliah tambahan

    // --- Buat Dosen baru ---
    Dosen dosen4("Bu Dini", "D004", 60, "Pendidikan Guru SD", 500000);  // Dosen keempat
    cout << left << setw(22) << "Dosen baru" << ": D004 - Bu Dini\n";   // Tampilkan ringkasan Dosen baru
    dosen4.ampuMataKuliah("PGSD101");                               // dosen4 mengampu PGSD101
    dosen4.ampuMataKuliah("PGSD201");                               // dosen4 mengampu PGSD201
    dosen3.ampuMataKuliah("MTK301");                                // dosen3 mengampu MTK301

    // --- Susun program studi baru ke Fakultas ---
    fakFIP.tambahProgramStudi(prodiPGSD);                           // Tambah prodiPGSD ke FIP
    fakMIPA.tambahProgramStudi(prodiMatematika);                    // Perbarui mata kuliah prodiMatematika

    // --- Buat Mahasiswa baru ---
    Mahasiswa mhs3("Repan", "M003", 22, "Pendidikan Guru SD", 3.7); // Mahasiswa ketiga
    cout << left << setw(22) << "Mahasiswa baru" << ": M003 - Repan\n\n"; // Tampilkan ringkasan Mahasiswa baru
    mhs3.ambilMataKuliah("PGSD101");                                // mhs3 mengambil PGSD101
    mhs3.ambilMataKuliah("PGSD201");                                // mhs3 mengambil PGSD201

    // ========================== TAMPILKAN SESUDAH MENAMBAH ==========================
    cout << "\n>>> DATA SESUDAH DITAMBAHKAN <<<\n\n";               // Label sesudah menambah

    cout << "--- FAKULTAS, PROGRAM STUDI, DAN MATA KULIAH ---\n";   // Label hierarki akademik
    tampilkanGabungan({fakMIPA.render(1), fakPOK.render(2), fakFIP.render(3)}); // Tampilkan hierarki dalam satu bingkai

    cout << "\n--- DOSEN ---\n";                                    // Label dosen
    tampilkanGabungan({dosen1.render(1), dosen2.render(2), dosen3.render(3), dosen4.render(4)}); // Tampilkan dosen dalam satu bingkai

    cout << "\n--- MAHASISWA ---\n";                                // Label mahasiswa
    tampilkanGabungan({mhs1.render(1), mhs2.render(2), mhs3.render(3)}); // Tampilkan mahasiswa dalam satu bingkai

    cout << "\n" << string(51, '=') << "\n";                        // Separator bawah
    cout << "                  PROGRAM SELESAI\n";                  // Pesan selesai
    cout << string(51, '=') << "\n";                                // Separator akhir

    return 0;                                                       // Program selesai dengan status sukses
}
