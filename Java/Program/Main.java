public class Main {                                                                 // Class utama program
    public static void main(String[] args) {                                        // Fungsi utama program
        System.out.println("==================================================");   // Separator atas
        System.out.println("           SISTEM MANAJEMEN UNIVERSITAS");              // Judul program
        System.out.println("==================================================\n"); // Separator bawah judul

        // --- Buat Dosen ---
        Dosen dosen1 = new Dosen("Bu Rosa", "P001", 45, "FPMIPA", 850000);          // Dosen pertama
        Dosen dosen2 = new Dosen("Pak Yudi", "P002", 50, "FPOK", 900000);           // Dosen kedua
        Dosen dosen3 = new Dosen("Pak Budi", "P003", 55, "FIP", 950000);            // Dosen ketiga

        // --- Buat Mahasiswa ---
        Mahasiswa mhs1 = new Mahasiswa("Bentar", "S001", 20, "Matematika", 3.8);    // Mahasiswa pertama
        Mahasiswa mhs2 = new Mahasiswa("Rian", "S002", 19, "PKO", 3.9);             // Mahasiswa kedua

        // --- Mahasiswa ambil mata kuliah ---
        mhs1.ambilMataKuliah("MIPA101");                                            // mhs1 ambil MIPA101
        mhs1.ambilMataKuliah("MIPA201");                                            // mhs1 ambil MIPA201
        mhs2.ambilMataKuliah("PJK101");                                             // mhs2 ambil PJK101

        // --- Dosen ampu mata kuliah ---
        dosen1.ampuMataKuliah("MIPA101");                                           // dosen1 ampu MIPA101
        dosen1.ampuMataKuliah("MIPA201");                                           // dosen1 ampu MIPA201
        dosen2.ampuMataKuliah("PJK101");                                            // dosen2 ampu PJK101

        // --- Buat Mata Kuliah (Composition: MataKuliah has-a Dosen) ---
        MataKuliah mk1 = new MataKuliah("MIPA101", "Statistika Dasar", 3, dosen1);  // MK pertama
        MataKuliah mk2 = new MataKuliah("MIPA201", "Biologi Sel", 4, dosen1);       // MK kedua
        MataKuliah mk3 = new MataKuliah("PJK101", "Pendidikan Jasmani", 3, dosen2); // MK ketiga

        // --- Buat Fakultas (Composition: FAKULTAS has-a Dosen as dekan) ---
        Fakultas fakIlkom = new Fakultas("FPMIPA", dosen1);                         // Fakultas FPMIPA
        fakIlkom.tambahMataKuliah(mk1);                                             // Tambah mk1 ke fakIlkom
        fakIlkom.tambahMataKuliah(mk2);                                             // Tambah mk2 ke fakIlkom

        Fakultas fakFisika = new Fakultas("FPOK", dosen2);                          // Fakultas FPOK
        fakFisika.tambahMataKuliah(mk3);                                            // Tambah mk3 ke fakFisika

        // ========================= TAMPILKAN SEBELUM MENAMBAH ==========================
        System.out.println(">>> DATA SEBELUM DITAMBAHKAN <<<\n");                   // Label sebelum menambah

        System.out.println("--- DOSEN ---");                                        // Label dosen
        dosen1.display(); System.out.println();                                     // Tampilkan dosen1
        dosen2.display(); System.out.println();                                     // Tampilkan dosen2
        dosen3.display(); System.out.println("\n");                                 // Tampilkan dosen3

        System.out.println("--- MAHASISWA ---");                                    // Label mahasiswa
        mhs1.display(); System.out.println();                                       // Tampilkan mhs1
        mhs2.display(); System.out.println("\n");                                   // Tampilkan mhs2

        System.out.println("--- FAKULTAS ---");                                     // Label Fakultas
        fakIlkom.display();                                                         // Tampilkan fakIlkom
        fakFisika.display();                                                        // Tampilkan fakFisika

        // =============================== TAMBAH DATA BARU ===============================
        System.out.print("\n>>> MENAMBAHKAN DATA BARU <<<\n\n");                    // Label menambah data

        // --- Tambah dosen baru ---
        Dosen dosen4 = new Dosen("Bu Dini", "P004", 60, "FIP", 500000);             // Dosen keempat
        dosen4.ampuMataKuliah("PGSD101");                                           // dosen4 ampu PGSD101
        System.out.println("Ditambahkan dosen baru: Bu Dini");                      // Pesan

        // --- Tambah mahasiswa baru ---
        Mahasiswa mhs3 = new Mahasiswa("Repan", "S003", 22, "PGSD", 3.7);           // Mahasiswa ketiga
        mhs3.ambilMataKuliah("PGSD101");                                            // mhs3 ambil PGSD101
        System.out.println("Ditambahkan mahasiswa baru: Repan");                    // Pesan

        // --- Tambah mata kuliah baru ---
        MataKuliah mk4 = new MataKuliah("PGSD101", "Landasan Pendidikan", 4, dosen4);       // MK keempat
        System.out.println("Ditambahkan mata kuliah baru: PGSD101 - Landasan Pendidikan");  // Pesan

        // --- Tambah fakultas baru ---
        Fakultas fakFIP = new Fakultas("FIP", dosen4);                              // Fakultas FIP
        fakFIP.tambahMataKuliah(mk4);                                               // Tambah mk4 ke fakFIP
        System.out.println("Ditambahkan fakultas baru: FIP");                       // Pesan

        // --- Tambah mata kuliah yang diajar Pak Budi ---
        MataKuliah mk6 = new MataKuliah("BIM201", " Bimbingan Konseling", 3, dosen3); // MK keenam
        fakFIP.tambahMataKuliah(mk6);                                               // Tambah mk6 ke fakFIP
        dosen3.ampuMataKuliah("BIM201");                                            // dosen3 ampu BIM201
        System.out.println("Ditambahkan mata kuliah baru yang diajar Pak Budi: BIM201 - Bimbingan Konseling"); // Pesan

        // --- Tambah mata kuliah ke fakultas yang ada ---
        MataKuliah mk5 = new MataKuliah("MIPA301", "Kimia Analitik", 3, dosen1);    // MK kelima
        fakIlkom.tambahMataKuliah(mk5);                                             // Tambah mk5 ke fakIlkom
        dosen1.ampuMataKuliah("MIPA301");                                           // dosen1 ampu MIPA301
        System.out.println("Ditambahkan mata kuliah baru ke fakultas FPMIPA: MIPA301 - Kimia Analitik"); // Pesan

        // ========================== TAMPILKAN SESUDAH MENAMBAH ==========================
        System.out.print("\n>>> DATA SESUDAH DITAMBAHKAN <<<\n\n");                 // Label sesudah menambah

        System.out.println("--- DOSEN ---");                                        // Label dosen
        dosen1.display(); System.out.println();                                     // Tampilkan dosen1
        dosen2.display(); System.out.println();                                     // Tampilkan dosen2
        dosen3.display(); System.out.println();                                     // Tampilkan dosen3
        dosen4.display(); System.out.println("\n");                                 // Tampilkan dosen4

        System.out.println("--- MAHASISWA ---");                                    // Label mahasiswa
        mhs1.display(); System.out.println();                                       // Tampilkan mhs1
        mhs2.display(); System.out.println();                                       // Tampilkan mhs2
        mhs3.display(); System.out.println("\n");                                   // Tampilkan mhs3

        System.out.println("--- FAKULTAS ---");                                     // Label Fakultas
        fakIlkom.display();                                                         // Tampilkan fakIlkom
        fakFisika.display();                                                        // Tampilkan fakFisika
        fakFIP.display();                                                           // Tampilkan fakFIP

        System.out.print("\n" + "=".repeat(51) + "\n");                             // Separator bawah (51 karakter)
        System.out.println("                  PROGRAM SELESAI");                    // Pesan selesai
        System.out.println("=".repeat(51));                                         // Separator akhir (51 karakter)
    }
}
