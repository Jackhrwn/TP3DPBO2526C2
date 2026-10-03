import java.util.ArrayList; // Import ArrayList untuk menyimpan daftar mata kuliah

// ====================== DOSEN (Turunan dari Manusia) =======================
public class Dosen extends Manusia {                                                    // Dosen mewarisi sifat Manusia
    private String namaFakultas;                                                        // Menyimpan FAKULTAS dosen
    private double gaji;                                                                // Menyimpan gaji dosen
    private ArrayList<String> mataKuliahDiajar = new ArrayList<>();                     // Menyimpan daftar mata kuliah yang diajar

    public Dosen(String nama, String id, int umur, String namaFakultas, double gaji) {  // Constructor
        super(nama, id, umur);                                                          // Panggil constructor kelas induk (Manusia)
        this.namaFakultas = namaFakultas;                                               // Inisialisasi FAKULTAS
        this.gaji = gaji;                                                               // Inisialisasi gaji
    }

    // --- Getter dan Setter ---

    public String getNamaFakultas() { return namaFakultas; }                            // Ambil FAKULTAS
    public double getGaji() { return gaji; }                                            // Ambil gaji
    public ArrayList<String> getMataKuliahDiajar() { return mataKuliahDiajar; }         // Ambil daftar mata kuliah

    public void setNamaFakultas(String d) { namaFakultas = d; }                         // Ubah FAKULTAS
    public void setGaji(double g) { gaji = g; }                                         // Ubah gaji
    public void setMataKuliahDiajar(ArrayList<String> mk) { mataKuliahDiajar = mk; }    // Ubah daftar mata kuliah

    public void ampuMataKuliah(String kodeMataKuliah) {                                 // Dosen mengajar mata kuliah
        mataKuliahDiajar.add(kodeMataKuliah);                                           // Tambahkan ke daftar
    }

    @Override                                                                           // Timpa metode display() dari kelas induk Manusia
    public void display() {                                                             // Tampilkan data dosen
        System.out.print("[DOSEN] ");                                                   // Label dosen
        System.out.printf("%-8s | ", nama);                                             // Nama (lebar 8 + 2 spasi)
        System.out.printf("ID: %-3s | ", id);                                           // ID (lebar 3 + 2 spasi)
        System.out.printf("Umur: %-1d | ", umur);                                       // Umur (lebar 1 + 2 spasi)
        System.out.printf("Fakultas: %-6s | ", namaFakultas);                           // Fakultas (lebar 6 + 2 spasi)
        System.out.printf("Gaji: Rp%-6.0f", gaji);                                      // Gaji (lebar 6)
        if (!mataKuliahDiajar.isEmpty()) {                                              // Jika ada mata kuliah
            System.out.print(" | Mengajar: ");                                          // Label mengajar
            for (int i = 0; i < mataKuliahDiajar.size(); i++) {                         // Loop semua mata kuliah
                System.out.print(mataKuliahDiajar.get(i));                              // Tampilkan kode mata kuliah
                if (i < mataKuliahDiajar.size() - 1) System.out.print(", ");            // Pemisah antar mata kuliah
            }
        }
    }
}
