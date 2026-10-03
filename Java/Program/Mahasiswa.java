import java.util.ArrayList; // Import ArrayList untuk menyimpan daftar mata kuliah

// ======================= MAHASISWA (Turunan dari Manusia) =======================
public class Mahasiswa extends Manusia {                                               // Mahasiswa mewarisi sifat Manusia
    private String jurusan;                                                            // Menyimpan jurusan mahasiswa
    private double ipk;                                                                // Menyimpan IPK mahasiswa
    private ArrayList<String> mataKuliahDiambil = new ArrayList<>();                   // Menyimpan daftar mata kuliah yang diambil

    public Mahasiswa(String nama, String id, int umur, String jurusan, double ipk) {   // Constructor
        super(nama, id, umur);                                                         // Panggil constructor kelas induk (Manusia)                                                       
        this.jurusan = jurusan;                                                        // Inisialisasi jurusan
        this.ipk = ipk;                                                                // Inisialisasi IPK
    }

    // --- Getter dan Setter ---

    public String getJurusan() { return jurusan; }                                     // Ambil jurusan
    public double getIpk() { return ipk; }                                             // Ambil IPK
    public ArrayList<String> getMataKuliahDiambil() { return mataKuliahDiambil; }      // Ambil daftar mata kuliah

    public void setJurusan(String j) { jurusan = j; }                                  // Ubah jurusan
    public void setIpk(double i) { ipk = i; }                                          // Ubah IPK
    public void setMataKuliahDiambil(ArrayList<String> mk) { mataKuliahDiambil = mk; } // Ubah daftar mata kuliah

    public void ambilMataKuliah(String kodeMataKuliah) {                               // Mahasiswa mengambil mata kuliah
        mataKuliahDiambil.add(kodeMataKuliah);                                         // Tambahkan ke daftar
    }

    @Override                                                                          // Timpa metode display() dari kelas induk Manusia
    public void display() {                                                            // Tampilkan data mahasiswa
        System.out.print("[MAHASISWA] ");                                              // Label mahasiswa
        System.out.printf("%-6s | ", nama);                                            // Nama (lebar 6 + 2 spasi)
        System.out.printf("ID: %-3s | ", id);                                          // ID (lebar 3 + 2 spasi)
        System.out.printf("Umur: %-1d | ", umur);                                      // Umur (lebar 1 + 2 spasi)
        System.out.printf("Jurusan: %-10s | ", jurusan);                               // Jurusan (lebar 10 + 2 spasi)
        System.out.printf("IPK: %-2s", ipk);                                           // IPK (lebar 2)
        if (!mataKuliahDiambil.isEmpty()) {                                            // Jika ada mata kuliah
            System.out.print(" | Mata Kuliah: ");                                      // Label mata kuliah
            for (int i = 0; i < mataKuliahDiambil.size(); i++) {                       // Loop semua mata kuliah
                System.out.print(mataKuliahDiambil.get(i));                            // Tampilkan kode mata kuliah
                if (i < mataKuliahDiambil.size() - 1) System.out.print(", ");          // Pemisah antar mata kuliah
            }
        }
    }
}
