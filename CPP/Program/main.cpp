#include "Manusia.cpp"                                // Include class Manusia
#include "Dosen.cpp"                                  // Include class Dosen
#include "MataKuliah.cpp"                             // Include class MataKuliah
#include "Mahasiswa.cpp"                              // Include class Mahasiswa
#include "Departemen.cpp"                             // Include class Departemen

// =================================== MAIN ===================================
int main() {                                                    // Fungsi utama program
    cout << string(50, '=') << "\n";                            // Separator atas (50 karakter)
    cout << "           SISTEM MANAJEMEN UNIVERSITAS\n";        // Judul program
    cout << string(50, '=') << "\n\n";                          // Separator bawah judul

    // --- Buat Dosen ---
    Dosen dosen1("Bu Rosa", "P001", 45, "Ilmu Komputer", 85000);// Dosen pertama
    Dosen dosen2("Pak Herbert", "P002", 50, "Fisika", 90000);   // Dosen kedua
    Dosen dosen3("Pak Budi", "P003", 55, "Matematika", 95000);  // Dosen ketiga

    // --- Buat Mahasiswa ---
    Mahasiswa mhs1("Bentar", "S001", 20, "Ilmu Komputer", 3.8); // Mahasiswa pertama
    Mahasiswa mhs2("Rian", "S002", 19, "Fisika", 3.9);          // Mahasiswa kedua

    // --- Mahasiswa ambil mata kuliah ---
    mhs1.ambilMataKuliah("CS101");                              // mhs1 ambil CS101
    mhs1.ambilMataKuliah("CS201");                              // mhs1 ambil CS201
    mhs2.ambilMataKuliah("PHY101");                             // mhs2 ambil PHY101

    // --- Dosen ampu mata kuliah ---
    dosen1.ampuMataKuliah("CS101");                             // dosen1 ampu CS101
    dosen1.ampuMataKuliah("CS201");                             // dosen1 ampu CS201
    dosen2.ampuMataKuliah("PHY101");                            // dosen2 ampu PHY101

    // --- Buat Mata Kuliah (Composition: MataKuliah has-a Dosen) ---
    MataKuliah mk1("CS101", "Daspro", 3, &dosen1);              // MK pertama
    MataKuliah mk2("CS201", "Srukdat", 4, &dosen1);             // MK kedua
    MataKuliah mk3("PHY101", "Fisika Dasar", 3, &dosen2);       // MK ketiga

    // --- Buat Departemen (Composition: Departemen has-a Dosen as ketua) ---
    Departemen depIlkom("Ilmu Komputer", &dosen1);              // Departemen Ilmu Komputer
    depIlkom.tambahMataKuliah(mk1);                             // Tambah mk1 ke depIlkom
    depIlkom.tambahMataKuliah(mk2);                             // Tambah mk2 ke depIlkom

    Departemen depFisika("Fisika", &dosen2);                    // Departemen Fisika
    depFisika.tambahMataKuliah(mk3);                            // Tambah mk3 ke depFisika

    // ========================= TAMPILKAN SEBELUM MENAMBAH ==========================
    cout << ">>> DATA SEBELUM DITAMBAHKAN <<<\n\n";      // Label sebelum menambah

    cout << "--- DOSEN ---\n";                           // Label dosen
    dosen1.display(); cout << "\n";                      // Tampilkan dosen1
    dosen2.display(); cout << "\n";                      // Tampilkan dosen2
    dosen3.display(); cout << "\n\n";                    // Tampilkan dosen3

    cout << "--- MAHASISWA ---\n";                       // Label mahasiswa
    mhs1.display(); cout << "\n";                        // Tampilkan mhs1
    mhs2.display(); cout << "\n\n";                      // Tampilkan mhs2

    cout << "--- DEPARTEMEN ---\n";                      // Label departemen
    depIlkom.display();                                  // Tampilkan depIlkom
    depFisika.display();                                 // Tampilkan depFisika

    // =============================== TAMBAH DATA BARU ===============================
    cout << "\n>>> MENAMBAHKAN DATA BARU <<<\n\n";                  // Label menambah data

    // --- Tambah dosen baru ---
    Dosen dosen4("Pak Rezky", "P004", 60, "Matematika", 100000);    // Dosen keempat
    dosen4.ampuMataKuliah("MATH101");                               // dosen4 ampu MATH101
    cout << "Ditambahkan dosen baru: Pak Rezky\n";                  // Pesan

    // --- Tambah mahasiswa baru ---
    Mahasiswa mhs3("Repan", "S003", 22, "Matematika", 3.7);         // Mahasiswa ketiga
    mhs3.ambilMataKuliah("MATH101");                                // mhs3 ambil MATH101
    cout << "Ditambahkan mahasiswa baru: Repan\n";                  // Pesan

    // --- Tambah mata kuliah baru ---
    MataKuliah mk4("MATH101", "Kalkulus I", 4, &dosen4);             // MK keempat
    cout << "Ditambahkan mata kuliah baru: MATH101 - Kalkulus I\n";  // Pesan

    // --- Tambah departemen baru ---
    Departemen depMatematika("Matematika", &dosen4);                 // Departemen Matematika
    depMatematika.tambahMataKuliah(mk4);                             // Tambah mk4 ke depMatematika
    cout << "Ditambahkan departemen baru: Matematika\n";             // Pesan

    // --- Tambah mata kuliah ke departemen yang ada ---
    MataKuliah mk5("CS301", "DPBO", 3, &dosen1);                     // MK kelima
    depIlkom.tambahMataKuliah(mk5);                                  // Tambah mk5 ke depIlkom
    dosen1.ampuMataKuliah("CS301");                                  // dosen1 ampu CS301
    cout << "Ditambahkan mata kuliah baru ke departemen Ilmu Komputer: CS301 - DPBO\n";  // Pesan

    // ========================== TAMPILKAN SESUDAH MENAMBAH ==========================
    cout << "\n>>> DATA SESUDAH DITAMBAHKAN <<<\n\n";    // Label sesudah menambah

    cout << "--- DOSEN ---\n";                           // Label dosen
    dosen1.display(); cout << "\n";                      // Tampilkan dosen1
    dosen2.display(); cout << "\n";                      // Tampilkan dosen2
    dosen3.display(); cout << "\n";                      // Tampilkan dosen3
    dosen4.display(); cout << "\n\n";                    // Tampilkan dosen4

    cout << "--- MAHASISWA ---\n";                       // Label mahasiswa
    mhs1.display(); cout << "\n";                        // Tampilkan mhs1
    mhs2.display(); cout << "\n";                        // Tampilkan mhs2
    mhs3.display(); cout << "\n\n";                      // Tampilkan mhs3

    cout << "--- DEPARTEMEN ---\n";                      // Label departemen
    depIlkom.display();                                  // Tampilkan depIlkom
    depFisika.display();                                 // Tampilkan depFisika
    depMatematika.display();                             // Tampilkan depMatematika

    cout << "\n" << string(51, '=') << "\n";             // Separator bawah (51 karakter)
    cout << "                  PROGRAM SELESAI\n";       // Pesan selesai
    cout << string(51, '=') << "\n";                     // Separator akhir (51 karakter)

    return 0;                                            // Program selesai
}
