// =================== MATA KULIAH (Bagian dari Fakultas) ====================
public class MataKuliah {                                                             // Class mata kuliah
    private String kodeMataKuliah;                                                    // Menyimpan kode mata kuliah
    private String namaMataKuliah;                                                    // Menyimpan nama mata kuliah
    private int sks;                                                                  // Menyimpan jumlah SKS

    public MataKuliah(String kode, String nama, int sks) {                            // Constructor
        this.kodeMataKuliah = kode;                                                   // Inisialisasi kode
        this.namaMataKuliah = nama;                                                   // Inisialisasi nama
        this.sks = sks;                                                               // Inisialisasi SKS
    }

    public MataKuliah(MataKuliah sumber) {                                            // Constructor salinan untuk composition
        this(sumber.kodeMataKuliah, sumber.namaMataKuliah, sumber.sks);               // Salin data mata kuliah
    }

    // --- Getter dan Setter ---
    public String getKodeMataKuliah() { return kodeMataKuliah; }                      // Ambil kode
    public String getNamaMataKuliah() { return namaMataKuliah; }                      // Ambil nama
    public int getSks() { return sks; }                                               // Ambil SKS

    public void setKodeMataKuliah(String kode) { kodeMataKuliah = kode; }             // Ubah kode
    public void setNamaMataKuliah(String nama) { namaMataKuliah = nama; }             // Ubah nama
    public void setSks(int jumlah) { sks = jumlah; }                                  // Ubah SKS

    public void display() {                                                           // Tampilkan data mata kuliah
        System.out.printf("%-9s: %-9s | %-8s: %-26s | %-4s: %d", "Kode", kodeMataKuliah, "Nama", namaMataKuliah, "SKS", sks); // Tampilkan data sejajar
    }
}
