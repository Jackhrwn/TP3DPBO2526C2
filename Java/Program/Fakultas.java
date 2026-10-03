import java.util.ArrayList;                                                          // Import ArrayList untuk komposisi program studi
import java.util.List;                                                               // Import List untuk mengembalikan kumpulan data

// ================= FAKULTAS (Composition) =================
public class Fakultas {                                                              // Class Fakultas
    private String idFakultas;                                                       // Menyimpan ID Fakultas
    private String nama;                                                             // Menyimpan nama Fakultas
    private final ArrayList<ProgramStudi> programStudi = new ArrayList<>();          // Objek prodi milik Fakultas

    public Fakultas(String idFakultas, String nama) {                                // Constructor
        this.idFakultas = idFakultas;                                                // Inisialisasi ID
        this.nama = nama;                                                            // Inisialisasi nama
    }

    // --- Getter dan Setter ---
    public String getIdFakultas() { return idFakultas; }                             // Ambil ID Fakultas
    public String getNama() { return nama; }                                         // Ambil nama Fakultas
    public List<ProgramStudi> getProgramStudi() {                                    // Ambil salinan daftar prodi
        ArrayList<ProgramStudi> salinan = new ArrayList<>();
        for (ProgramStudi prodi : programStudi) {                                    // Salin setiap program studi
            salinan.add(new ProgramStudi(prodi));                                    // Salin prodi beserta mata kuliah
        }
        return List.copyOf(salinan);                                                 // Kembalikan daftar yang tidak dapat diubah
    }

    public void setIdFakultas(String idFakultas) { this.idFakultas = idFakultas; }   // Ubah ID
    public void setNama(String nama) { this.nama = nama; }                           // Ubah nama

    public void tambahProgramStudi(ProgramStudi prodi) {                             // Tambah atau perbarui prodi
        for (int i = 0; i < programStudi.size(); i++) {                              // Cari prodi dengan ID yang sama
            if (programStudi.get(i).getIdProgramStudi().equals(prodi.getIdProgramStudi())) {
                programStudi.set(i, new ProgramStudi(prodi));                        // Perbarui prodi berdasarkan ID
                return;                                                              // Hentikan setelah prodi diperbarui
            }
        }
        programStudi.add(new ProgramStudi(prodi));                                   // Simpan salinan prodi baru
    }

    public void display() { System.out.println(render(1)); }                         // Tampilkan dengan nomor default
    public void display(int nomorFakultas) { System.out.println(render(nomorFakultas)); } // Tampilkan dengan nomor yang diberikan

    public String render(int nomorFakultas) {                                        // Susun Fakultas beserta isinya dalam satu bingkai
        ArrayList<String> lines = new ArrayList<>();                                 // Siapkan baris tampilan
        lines.add("[" + nomorFakultas + "] Fakultas");                               // Tampilkan judul Fakultas
        lines.add("    ID Fakultas   : " + idFakultas);                              // Tampilkan ID Fakultas
        lines.add("    Nama Fakultas : " + nama);                                    // Tampilkan nama Fakultas
        lines.add("    Jumlah Prodi  : " + programStudi.size());                     // Tampilkan jumlah prodi

        for (int i = 0; i < programStudi.size(); i++) {                              // Tampilkan setiap program studi
            ProgramStudi prodi = programStudi.get(i);                                // Ambil prodi saat ini
            lines.add("");                                                           // Pisahkan data antarprodi
            lines.add("    [" + (i + 1) + "] Program Studi");                        // Tampilkan judul dan nomor prodi
            lines.add("        ID Prodi   : " + prodi.getIdProgramStudi());          // Tampilkan ID prodi
            lines.add("        Nama Prodi : " + prodi.getNama());                    // Tampilkan nama prodi
            lines.add("        Jenjang    : " + prodi.getJenjang());                 // Tampilkan jenjang prodi
            List<MataKuliah> daftarMK = prodi.getMataKuliah();                       // Ambil daftar mata kuliah prodi
            for (int j = 0; j < daftarMK.size(); j++) {                              // Tampilkan semua mata kuliah prodi
                MataKuliah mk = daftarMK.get(j);                                     // Ambil mata kuliah saat ini
                lines.add("        [" + (j + 1) + "] Mata Kuliah");                  // Tampilkan judul dan nomor mata kuliah
                lines.add("            ID Matkul   : " + mk.getKodeMataKuliah());    // Tampilkan kode mata kuliah
                lines.add("            Nama Matkul : " + mk.getNamaMataKuliah());    // Tampilkan nama mata kuliah
                lines.add("            SKS         : " + mk.getSks());               // Tampilkan jumlah SKS
            }
        }

        int lebar = 52;                                                              // Gunakan lebar bingkai tetap
        String batas = "+" + "-".repeat(lebar + 2) + "+";                            // Buat batas bingkai
        StringBuilder output = new StringBuilder(batas).append(System.lineSeparator()); // Siapkan keluaran bingkai
        for (String line : lines) output.append(String.format("| %-"+lebar+"s |%n", line)); // Tambahkan baris berbingkai
        return output.append(batas).toString();                                      // Kembalikan seluruh bingkai
    }
}
