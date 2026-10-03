import java.util.ArrayList;                                                             // Import ArrayList untuk mengumpulkan baris tampilan
import java.util.Arrays;                                                                // Import Arrays untuk menyusun daftar objek
import java.util.List;                                                                  // Import List sebagai parameter kumpulan kartu

public class Main {                                                                     // Class utama program
    private static void tampilkanGabungan(List<String> kartu) {                         // Tampilkan beberapa kartu dengan satu bingkai luar
        ArrayList<ArrayList<String>> isiKartu = new ArrayList<>();                      // Simpan isi tiap kartu
        int lebar = 52;                                                                 // Gunakan lebar tetap untuk semua bingkai
        for (String kartuData : kartu) {                                                // Proses setiap kartu
            ArrayList<String> barisKartu = new ArrayList<>();                           // Siapkan baris untuk satu kartu
            for (String baris : kartuData.split("\\R")) {                               // Periksa setiap baris kartu
                if (!baris.startsWith("| ")) continue;                                  // Abaikan batas kartu lama
                int akhir = baris.lastIndexOf(" |");                                    // Cari penutup kolom isi
                if (akhir < 2) continue;                                                // Abaikan baris yang bukan isi
                String isi = baris.substring(2, akhir).replaceFirst(" +$", "");         // Buang padding lama
                barisKartu.add(isi);                                                    // Simpan baris isi
            }
            isiKartu.add(barisKartu);                                                   // Simpan satu kartu
        }

        String batas = "+" + "-".repeat(lebar + 2) + "+";                               // Buat garis bingkai
        System.out.println(batas);                                                      // Cetak batas atas
        for (int i = 0; i < isiKartu.size(); i++) {                                     // Tampilkan isi semua kartu
            for (String baris : isiKartu.get(i)) System.out.printf("| %-"+lebar+"s |%n", baris); // Cetak isi kartu
            if (i + 1 < isiKartu.size()) System.out.println(batas);                     // Pisahkan kartu dengan satu garis
        }
        System.out.println(batas);                                                      // Cetak batas bawah
    }

    public static void main(String[] args) {                                            // Fungsi utama program
        System.out.println("==================================================");       // Separator atas
        System.out.println("           SISTEM MANAJEMEN UNIVERSITAS");                  // Judul program
        System.out.println("==================================================\n");     // Separator bawah judul

        // --- Buat Fakultas ---
        Fakultas fakMIPA = new Fakultas("F001", "FPMIPA");                              // Fakultas FPMIPA
        Fakultas fakPOK = new Fakultas("F002", "FPOK");                                 // Fakultas FPOK

        // --- Buat Program Studi ---
        ProgramStudi prodiIlkom = new ProgramStudi("PS001", "Ilmu Komputer", "S1");     // Program Studi Ilmu Komputer
        ProgramStudi prodiMatematika = new ProgramStudi("PS002", "Matematika", "S1");   // Program Studi Matematika
        ProgramStudi prodiPKO = new ProgramStudi("PS003", "PKO", "S1");                 // Program Studi PKO

        // --- Buat Mata Kuliah ---
        MataKuliah mk1 = new MataKuliah("ILK101", "Dasar Pemrograman", 3);              // MK pertama
        MataKuliah mk2 = new MataKuliah("MTK101", "Statistika Dasar", 3);               // MK kedua
        MataKuliah mk3 = new MataKuliah("MTK201", "Kalkulus I", 4);                     // MK ketiga
        MataKuliah mk4 = new MataKuliah("PJK101", "Pendidikan Jasmani", 3);             // MK keempat
        prodiIlkom.tambahMataKuliah(mk1);                                               // Tambah mk1 ke prodiIlkom
        prodiMatematika.tambahMataKuliah(mk2);                                          // Tambah mk2 ke prodiMatematika
        prodiMatematika.tambahMataKuliah(mk3);                                          // Tambah mk3 ke prodiMatematika
        prodiPKO.tambahMataKuliah(mk4);                                                 // Tambah mk4 ke prodiPKO

        // --- Buat Dosen ---
        Dosen dosen1 = new Dosen("Bu Rosa", "D001", 45, "Ilmu Komputer", 850000);       // Dosen pertama
        Dosen dosen2 = new Dosen("Pak Yudi", "D002", 50, "PKO", 900000);                // Dosen kedua
        Dosen dosen3 = new Dosen("Pak Budi", "D003", 55, "Matematika", 950000);         // Dosen ketiga
        dosen1.ampuMataKuliah("ILK101");                                                // dosen1 mengampu ILK101
        dosen2.ampuMataKuliah("PJK101");                                                // dosen2 mengampu PJK101
        dosen3.ampuMataKuliah("MTK101");                                                // dosen3 mengampu MTK101
        dosen3.ampuMataKuliah("MTK201");                                                // dosen3 mengampu MTK201

        // --- Susun program studi ke Fakultas ---
        fakMIPA.tambahProgramStudi(prodiIlkom);                                         // Tambah prodiIlkom ke FPMIPA
        fakMIPA.tambahProgramStudi(prodiMatematika);                                    // Tambah prodiMatematika ke FPMIPA
        fakPOK.tambahProgramStudi(prodiPKO);                                            // Tambah prodiPKO ke FPOK

        // --- Buat Mahasiswa ---
        Mahasiswa mhs1 = new Mahasiswa("Bentar", "M001", 20, "Ilmu Komputer", 3.8);     // Mahasiswa pertama
        Mahasiswa mhs2 = new Mahasiswa("Rian", "M002", 19, "PKO", 3.9);                 // Mahasiswa kedua
        mhs1.ambilMataKuliah("ILK101");                                                 // mhs1 mengambil ILK101
        mhs2.ambilMataKuliah("PJK101");                                                 // mhs2 mengambil PJK101

        // ========================= TAMPILKAN SEBELUM MENAMBAH ==========================
        System.out.println(">>> DATA SEBELUM DITAMBAHKAN <<<\n");                       // Label sebelum menambah

        System.out.println("--- FAKULTAS, PROGRAM STUDI, DAN MATA KULIAH ---");         // Label hierarki akademik
        tampilkanGabungan(Arrays.asList(fakMIPA.render(1), fakPOK.render(2)));          // Tampilkan hierarki dalam satu bingkai

        System.out.println("\n--- DOSEN ---");                                          // Label dosen
        tampilkanGabungan(Arrays.asList(dosen1.render(1), dosen2.render(2), dosen3.render(3))); // Tampilkan dosen dalam satu bingkai

        System.out.println("\n--- MAHASISWA ---");                                      // Label mahasiswa
        tampilkanGabungan(Arrays.asList(mhs1.render(1), mhs2.render(2)));               // Tampilkan mahasiswa dalam satu bingkai

        // =============================== TAMBAH DATA BARU ===============================
        System.out.println("\n>>> MENAMBAHKAN DATA BARU <<<\n");                        // Label menambah data
        // --- Buat Fakultas baru ---
        Fakultas fakFIP = new Fakultas("F003", "FIP");                                  // Fakultas FIP
        System.out.printf("%-22s: F003 - FIP%n", "Fakultas baru");                      // Tampilkan data Fakultas baru

        // --- Buat Program Studi baru ---
        ProgramStudi prodiPGSD = new ProgramStudi("PS004", "Pendidikan Guru SD", "S1"); // Program Studi PGSD
        System.out.printf("%-22s: PS004 - Pendidikan Guru SD (S1)%n", "Program studi baru"); // Tampilkan data prodi baru

        // --- Buat Mata Kuliah baru ---
        MataKuliah mk5 = new MataKuliah("PGSD101", "Landasan Pendidikan", 4);           // MK kelima
        MataKuliah mk6 = new MataKuliah("PGSD201", "Bimbingan Konseling", 3);           // MK keenam
        MataKuliah mk7 = new MataKuliah("MTK301", "Kalkulus II", 3);                    // MK ketujuh
        prodiPGSD.tambahMataKuliah(mk5);                                                // Tambah mk5 ke prodiPGSD
        System.out.printf("%-22s: PGSD101 - Landasan Pendidikan (4 SKS)%n", "Mata kuliah baru"); // Tampilkan mata kuliah baru
        prodiPGSD.tambahMataKuliah(mk6);                                                // Tambah mk6 ke prodiPGSD
        System.out.printf("%-22s: PGSD201 - Bimbingan Konseling (3 SKS)%n", "");        // Tampilkan mata kuliah tambahan
        prodiMatematika.tambahMataKuliah(mk7);                                          // Tambah mk7 ke prodiMatematika
        System.out.printf("%-22s: MTK301 - Kalkulus II (3 SKS)%n", "");                 // Tampilkan mata kuliah tambahan

        // --- Buat Dosen baru ---
        Dosen dosen4 = new Dosen("Bu Dini", "D004", 60, "Pendidikan Guru SD", 500000);  // Dosen keempat
        System.out.printf("%-22s: D004 - Bu Dini%n", "Dosen baru");                     // Tampilkan data Dosen baru
        dosen4.ampuMataKuliah("PGSD101");                                               // dosen4 mengampu PGSD101
        dosen4.ampuMataKuliah("PGSD201");                                               // dosen4 mengampu PGSD201
        dosen3.ampuMataKuliah("MTK301");                                                // dosen3 mengampu MTK301

        // --- Susun program studi baru ke Fakultas ---
        fakFIP.tambahProgramStudi(prodiPGSD);                                           // Tambah prodiPGSD ke FIP
        fakMIPA.tambahProgramStudi(prodiMatematika);                                    // Perbarui data prodiMatematika

        // --- Buat Mahasiswa baru ---
        Mahasiswa mhs3 = new Mahasiswa("Repan", "M003", 22, "Pendidikan Guru SD", 3.7); // Mahasiswa ketiga
        System.out.printf("%-22s: M003 - Repan%n%n", "Mahasiswa baru");                 // Tampilkan data Mahasiswa baru
        mhs3.ambilMataKuliah("PGSD101");                                                // mhs3 mengambil PGSD101
        mhs3.ambilMataKuliah("PGSD201");                                                // mhs3 mengambil PGSD201

        // ========================== TAMPILKAN SESUDAH MENAMBAH ==========================
        System.out.println("\n>>> DATA SESUDAH DITAMBAHKAN <<<\n");                     // Label sesudah menambah
        System.out.println("--- FAKULTAS, PROGRAM STUDI, DAN MATA KULIAH ---");         // Label hierarki akademik
        tampilkanGabungan(Arrays.asList(fakMIPA.render(1), fakPOK.render(2), fakFIP.render(3))); // Tampilkan hierarki dalam satu bingkai

        System.out.println("\n--- DOSEN ---");                                          // Label dosen
        tampilkanGabungan(Arrays.asList(dosen1.render(1), dosen2.render(2), dosen3.render(3), dosen4.render(4))); // Tampilkan dosen dalam satu bingkai

        System.out.println("\n--- MAHASISWA ---");                                      // Label mahasiswa
        tampilkanGabungan(Arrays.asList(mhs1.render(1), mhs2.render(2), mhs3.render(3))); // Tampilkan mahasiswa dalam satu bingkai

        System.out.println("\n===================================================");    // Separator akhir
        System.out.println("                  PROGRAM SELESAI");                        // Pesan selesai
        System.out.println("===================================================");      // Separator bawah
    }
}
