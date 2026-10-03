import java.util.ArrayList;                                                             // Import ArrayList untuk mata kuliah yang diampu
import java.util.List;                                                                  // Import List untuk baris tampilan

// ====================== DOSEN (Turunan dari Manusia) =======================
public class Dosen extends Manusia {                                                    // Dosen mewarisi sifat Manusia
    private String programStudi;                                                        // Menyimpan program studi dosen
    private double gaji;                                                                // Menyimpan gaji dosen
    private final ArrayList<String> mataKuliahDiajar = new ArrayList<>();               // Menyimpan kode mata kuliah yang diampu

    public Dosen(String nama, String id, int umur, String programStudi, double gaji) {  // Constructor
        super(nama, id, umur);                                                          // Panggil constructor Manusia
        this.programStudi = programStudi;                                               // Inisialisasi program studi
        this.gaji = gaji;                                                               // Inisialisasi gaji
    }

    // --- Getter dan Setter ---
    public String getProgramStudi() { return programStudi; }                            // Ambil program studi
    public double getGaji() { return gaji; }                                            // Ambil gaji
    public ArrayList<String> getMataKuliahDiajar() { return new ArrayList<>(mataKuliahDiajar); } // Ambil salinan daftar

    public void setProgramStudi(String nilai) { programStudi = nilai; }                 // Ubah program studi
    public void setGaji(double nilai) { gaji = nilai; }                                 // Ubah gaji
    public void setMataKuliahDiajar(ArrayList<String> mk) {                             // Ubah daftar mata kuliah
        mataKuliahDiajar.clear();                                                       // Kosongkan daftar sebelumnya
        mataKuliahDiajar.addAll(mk);                                                    // Salin isi daftar baru
    }

    public void ampuMataKuliah(String kode) {                                           // Catat mata kuliah yang diampu
        mataKuliahDiajar.add(kode);                                                     // Tambahkan kode ke daftar
    }

    @Override                                                                           // Timpa metode display() dari Manusia
    public void display() { System.out.println(render(1)); }                            // Tampilkan dengan nomor default
    public void display(int nomor) { System.out.println(render(nomor)); }               // Tampilkan dengan nomor yang diberikan

    public String render(int nomor) {                                                   // Susun data dosen dalam bingkai
        ArrayList<String> lines = new ArrayList<>(List.of(                              // Siapkan baris data dosen
            "[" + nomor + "] Dosen",                                                    // Tampilkan judul dan nomor dosen
            "    ID Dosen       : " + id,                                               // Tampilkan ID dosen
            "    Nama           : " + nama,                                             // Tampilkan nama dosen
            "    Umur           : " + umur,                                             // Tampilkan umur dosen
            "    Program Studi  : " + programStudi,                                     // Tampilkan program studi dosen
            String.format("    Gaji           : Rp%.0f", gaji)                          // Tampilkan gaji dosen
        ));
        for (int i = 0; i < mataKuliahDiajar.size(); i++) {                             // Tampilkan mata kuliah yang diampu
            lines.add("    [" + (i + 1) + "] Mata Kuliah Diajar : " + mataKuliahDiajar.get(i)); // Tambahkan mata kuliah dosen
        }
        int lebar = 52;                                                                 // Gunakan lebar bingkai tetap
        String batas = "+" + "-".repeat(lebar + 2) + "+";                               // Buat batas bingkai
        StringBuilder output = new StringBuilder(batas).append(System.lineSeparator()); // Siapkan keluaran bingkai
        for (String line : lines) output.append(String.format("| %-"+lebar+"s |%n", line)); // Tambahkan baris berbingkai
        return output.append(batas).toString();                                         // Kembalikan seluruh bingkai
    }
}
