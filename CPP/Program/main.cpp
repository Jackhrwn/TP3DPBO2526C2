#include "Manusia.cpp"                                          // Include class Manusia
#include "Dosen.cpp"                                            // Include class Dosen
#include "Mahasiswa.cpp"                                        // Include class Mahasiswa
#include "MataKuliah.cpp"                                       // Include class MataKuliah
#include "Fakultas.cpp"                                         // Include class Fakultas

// =================================== MAIN ===================================
int main() {                                                    // Fungsi utama program
    cout << string(50, '=') << "\n";                            // Separator atas (50 karakter)
    cout << "           SISTEM MANAJEMEN UNIVERSITAS\n";        // Judul program
    cout << string(50, '=') << "\n\n";                          // Separator bawah judul

    // --- Buat Dosen ---
    Dosen dosen1("Bu Rosa", "P001", 45, "FPMIPA", 850000);       // Dosen pertama
    Dosen dosen2("Pak Yudi", "P002", 50, "FPOK", 900000);        // Dosen kedua
    Dosen dosen3("Pak Budi", "P003", 55, "FIP", 950000);         // Dosen ketiga

    // --- Buat Mahasiswa ---
    Mahasiswa mhs1("Bentar", "S001", 20, "Matematika", 3.8);     // Mahasiswa pertama
    Mahasiswa mhs2("Rian", "S002", 19, "PKO", 3.9);              // Mahasiswa kedua

    // --- Mahasiswa ambil mata kuliah ---
    mhs1.ambilMataKuliah("MIPA101");                             // mhs1 ambil MIPA101
    mhs1.ambilMataKuliah("MIPA201");                             // mhs1 ambil MIPA201
    mhs2.ambilMataKuliah("PJK101");                              // mhs2 ambil PJK101

    // --- Dosen ampu mata kuliah ---
    dosen1.ampuMataKuliah("MIPA101");                            // dosen1 ampu MIPA101
    dosen1.ampuMataKuliah("MIPA201");                            // dosen1 ampu MIPA201
    dosen2.ampuMataKuliah("PJK101");                             // dosen2 ampu PJK101

    // --- Buat Mata Kuliah (Composition: MataKuliah has-a Dosen) ---
    MataKuliah mk1("MIPA101", "Statistika Dasar", 3, &dosen1);   // MK pertama
    MataKuliah mk2("MIPA201", "Biologi Sel", 4, &dosen1);        // MK kedua
    MataKuliah mk3("PJK101", "Pendidikan Jasmani", 3, &dosen2);  // MK ketiga

    // --- Buat Fakultas (Composition: FAKULTAS has-a Dosen as dekan) ---
    Fakultas fakIlkom("FPMIPA", &dosen1);                        // Fakultas FPMIPA
    fakIlkom.tambahMataKuliah(mk1);                              // Tambah mk1 ke fakIlkom
    fakIlkom.tambahMataKuliah(mk2);                              // Tambah mk2 ke fakIlkom

    Fakultas fakFisika("FPOK", &dosen2);                         // Fakultas FPOK
    fakFisika.tambahMataKuliah(mk3);                             // Tambah mk3 ke fakFisika

    // ========================= TAMPILKAN SEBELUM MENAMBAH ==========================
    cout << ">>> DATA SEBELUM DITAMBAHKAN <<<\n\n";              // Label sebelum menambah

    cout << "--- DOSEN ---\n";                                   // Label dosen
    dosen1.display(); cout << "\n";                              // Tampilkan dosen1
    dosen2.display(); cout << "\n";                              // Tampilkan dosen2
    dosen3.display(); cout << "\n\n";                            // Tampilkan dosen3

    cout << "--- MAHASISWA ---\n";                               // Label mahasiswa
    mhs1.display(); cout << "\n";                                // Tampilkan mhs1
    mhs2.display(); cout << "\n\n";                              // Tampilkan mhs2

    cout << "--- FAKULTAS ---\n";                                // Label Fakultas
    fakIlkom.display();                                          // Tampilkan fakIlkom
    fakFisika.display();                                         // Tampilkan fakFisika

    // =============================== TAMBAH DATA BARU ===============================
    cout << "\n>>> MENAMBAHKAN DATA BARU <<<\n\n";               // Label menambah data

    // --- Tambah dosen baru ---
    Dosen dosen4("Bu Dini", "P004", 60, "FIP", 1000000);         // Dosen keempat
    dosen4.ampuMataKuliah("PGSD101");                            // dosen4 ampu PGSD101
    cout << "Ditambahkan dosen baru: Bu Dini\n";                 // Pesan

    // --- Tambah mahasiswa baru ---
    Mahasiswa mhs3("Repan", "S003", 22, "PGSD", 3.7);            // Mahasiswa ketiga
    mhs3.ambilMataKuliah("PGSD101");                             // mhs3 ambil PGSD101
    cout << "Ditambahkan mahasiswa baru: Repan\n";               // Pesan

    // --- Tambah mata kuliah baru ---
    MataKuliah mk4("PGSD101", "Landasan Pendidikan", 4, &dosen4);             // MK keempat
    cout << "Ditambahkan mata kuliah baru: PGSD101 - Landasan Pendidikan\n";  // Pesan

    // --- Tambah Fakultas baru ---
    Fakultas fakFIP("FIP", &dosen4);                             // Fakultas FIP
    fakFIP.tambahMataKuliah(mk4);                                // Tambah mk4 ke fakFIP
    cout << "Ditambahkan FAKULTAS baru: FIP\n";                  // Pesan

    // --- Tambah mata kuliah yang diajar Pak Budi ---
    MataKuliah mk6("BIM201", " Bimbingan Konseling", 3, &dosen3);// MK keenam
    fakFIP.tambahMataKuliah(mk6);                                // Tambah mk6 ke fakFIP
    dosen3.ampuMataKuliah("BIM201");                             // dosen3 ampu BIM201
    cout << "Ditambahkan mata kuliah baru yang diajar Pak Budi: BIM201 - Bimbingan Konseling\n";  // Pesan

    // --- Tambah mata kuliah ke FAKULTAS yang ada ---
    MataKuliah mk5("MIPA301", "Kimia Analitik", 3, &dosen1);     // MK kelima
    fakIlkom.tambahMataKuliah(mk5);                              // Tambah mk5 ke fakIlkom
    dosen1.ampuMataKuliah("MIPA301");                            // dosen1 ampu MIPA301
    cout << "Ditambahkan mata kuliah baru ke FAKULTAS FPMIPA: MIPA301 - Kimia Analitik\n";  // Pesan

    // ========================== TAMPILKAN SESUDAH MENAMBAH ==========================
    cout << "\n>>> DATA SESUDAH DITAMBAHKAN <<<\n\n";            // Label sesudah menambah

    cout << "--- DOSEN ---\n";                                   // Label dosen
    dosen1.display(); cout << "\n";                              // Tampilkan dosen1
    dosen2.display(); cout << "\n";                              // Tampilkan dosen2
    dosen3.display(); cout << "\n";                              // Tampilkan dosen3
    dosen4.display(); cout << "\n\n";                            // Tampilkan dosen4

    cout << "--- MAHASISWA ---\n";                               // Label mahasiswa
    mhs1.display(); cout << "\n";                                // Tampilkan mhs1
    mhs2.display(); cout << "\n";                                // Tampilkan mhs2
    mhs3.display(); cout << "\n\n";                              // Tampilkan mhs3

    cout << "--- FAKULTAS ---\n";                                // Label Fakultas
    fakIlkom.display();                                          // Tampilkan fakIlkom
    fakFisika.display();                                         // Tampilkan fakFisika
    fakFIP.display();                                            // Tampilkan fakFIP

    cout << "\n" << string(51, '=') << "\n";                     // Separator bawah (51 karakter)
    cout << "                  PROGRAM SELESAI\n";               // Pesan selesai
    cout << string(51, '=') << "\n";                             // Separator akhir (51 karakter)

    return 0;                                                    // Program selesai
}
