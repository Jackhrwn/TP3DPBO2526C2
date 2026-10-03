import java.util.ArrayList;                                                             // Import ArrayList untuk menyimpan daftar mata kuliah
import java.util.List;                                                                  // Import List untuk baris tampilan
import java.util.Locale;                                                                // Import Locale untuk format angka konsisten

// ======================= MAHASISWA (Turunan dari Manusia) =======================
public class Mahasiswa extends Manusia {                                                // Mahasiswa mewarisi sifat Manusia
    private String programStudi;                                                        // Menyimpan program studi mahasiswa
    private double ipk;                                                                 // Menyimpan IPK mahasiswa
    private ArrayList<String> mataKuliahDiambil = new ArrayList<>();                    // Menyimpan daftar mata kuliah yang diambil

    public Mahasiswa(String nama, String id, int umur, String programStudi, double ipk) { // Constructor
        super(nama, id, umur);                                                          // Panggil constructor kelas induk (Manusia)
        this.programStudi = programStudi;                                               // Inisialisasi program studi
        this.ipk = ipk;                                                                 // Inisialisasi IPK
    }

    // --- Getter dan Setter ---
    public String getProgramStudi() { return programStudi; }                            // Ambil program studi
    public double getIpk() { return ipk; }                                              // Ambil IPK
    public ArrayList<String> getMataKuliahDiambil() { return new ArrayList<>(mataKuliahDiambil); } // Ambil salinan daftar

    public void setProgramStudi(String nilai) { programStudi = nilai; }                 // Ubah program studi
    public void setIpk(double i) { ipk = i; }                                           // Ubah IPK
    public void setMataKuliahDiambil(ArrayList<String> mk) { mataKuliahDiambil = new ArrayList<>(mk); } // Salin daftar baru

    public void ambilMataKuliah(String kodeMataKuliah) {                                // Mahasiswa mengambil mata kuliah
        mataKuliahDiambil.add(kodeMataKuliah);                                          // Tambahkan kode ke daftar
    }

    @Override                                                                           // Timpa metode display() dari kelas induk Manusia
    public void display() { System.out.println(render(1)); }                            // Tampilkan dengan nomor default
    public void display(int nomor) { System.out.println(render(nomor)); }               // Tampilkan dengan nomor yang diberikan

    public String render(int nomor) {                                                   // Susun data mahasiswa dalam bingkai
        ArrayList<String> lines = new ArrayList<>(List.of(                              // Siapkan baris data mahasiswa
            "[" + nomor + "] Mahasiswa",                                                // Tampilkan judul dan no mahasiswa
            "    ID Mahasiswa  : " + id,                                                // Tampilkan ID mahasiswa
            "    Nama          : " + nama,                                              // Tampilkan nama mahasiswa
            "    Umur          : " + umur,                                              // Tampilkan umur mahasiswa
            "    Program Studi : " + programStudi,                                      // Tampilkan program studi mahasiswa
            String.format(Locale.ROOT, "    IPK           : %.2f", ipk)                 // Tampilkan IPK dengan titik desimal
        ));
        for (int i = 0; i < mataKuliahDiambil.size(); i++) {                            // Tampilkan mata kuliah yang diambil
            lines.add("    [" + (i + 1) + "] Mata Kuliah Diambil : " + mataKuliahDiambil.get(i)); // Tambahkan mata kuliah
        }
        int lebar = 52;                                                                 // Gunakan lebar bingkai tetap
        String batas = "+" + "-".repeat(lebar + 2) + "+";                               // Buat batas bingkai
        StringBuilder output = new StringBuilder(batas).append(System.lineSeparator()); // Siapkan keluaran bingkai
        for (String line : lines) output.append(String.format("| %-"+lebar+"s |%n", line)); // Tambahkan baris berbingkai
        return output.append(batas).toString();                                         // Kembalikan seluruh bingkai
    }
}
