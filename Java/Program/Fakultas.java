import java.util.ArrayList; // Import ArrayList untuk menampung daftar mata kuliah

// ================= FAKULTAS (Composition) =================
public class Fakultas {                                                         // Class Fakultas (bukan turunan Manusia)
    private String nama;                                                        // Menyimpan nama Fakultas
    private Dosen dekan;                                                        // Dosen yang menjadi dekan (Composition)
    private ArrayList<MataKuliah> mataKuliah = new ArrayList<>();               // Daftar mata kuliah di Fakultas ini

    public Fakultas(String nama, Dosen dekan) {                                 // Constructor
        this.nama = nama;                                                       // Inisialisasi nama Fakultas
        this.dekan = dekan;                                                     // Inisialisasi dekan Fakultas
    }   

    // --- Getter dan Setter ---

    public String getNama() { return nama; }                                    // Ambil nama Fakultas
    public Dosen getDekan() { return dekan; }                                   // Ambil dekan
    public ArrayList<MataKuliah> getMataKuliah() { return mataKuliah; }         // Ambil daftar mata kuliah

    public void setNama(String n) { nama = n; }                                 // Ubah nama Fakultas
    public void setDekan(Dosen k) { dekan = k; }                                // Ubah dekan
    public void setMataKuliah(ArrayList<MataKuliah> mk) { mataKuliah = mk; }    // Ubah daftar mata kuliah

    public void tambahMataKuliah(MataKuliah mk) {                               // Tambah mata kuliah ke Fakultas
        mataKuliah.add(mk);                                                     // Tambahkan ke vector
    }

    public void display() {                                                     // Tampilkan data Fakultas
        ArrayList<String> lines = new ArrayList<>();                            // Simpan semua baris output

        lines.add("Fakultas: " + nama);                                         // Baris nama Fakultas

        String barisDekan = "Dekan: " + dekan.getNama() + " (ID: " + dekan.getId() + ")"; // Baris dekan
        lines.add(barisDekan);                                                  // Simpan baris dekan

        lines.add("Mata Kuliah (" + mataKuliah.size() + "):");                  // Baris jumlah mata kuliah

        for (int i = 0; i < mataKuliah.size(); i++) {                           // Loop semua mata kuliah
            lines.add("  " + (i + 1) + ". " + formatMataKuliah(mataKuliah.get(i))); // Simpan baris mata kuliah
        }

        // Tampilkan dengan separator
        System.out.println("\n" + "=".repeat(69));                              // Separator atas (69 karakter)
        for (String baris : lines) {                                            // Loop semua baris
            System.out.println(baris);                                          // Tampilkan baris
        }
        System.out.println("=".repeat(69));                                     // Separator bawah (69 karakter)
    }

    private String formatMataKuliah(MataKuliah mk) {                            // Format data mata kuliah jadi satu baris teks
        return String.format("%-5s  %-16s | SKS: %-1d | Dosen: %s (%s)",        // Susun string dengan format rapi
                mk.getKodeMataKuliah(), mk.getNamaMataKuliah(), mk.getSks(),    // Argumen: kode, nama, dan SKS
                mk.getDosen().getNama(), mk.getDosen().getNamaFakultas());      // Argumen: nama dan FAKULTAS dosen
    }
}
