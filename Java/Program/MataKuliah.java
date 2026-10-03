// =================== MATA KULIAH (Composition: has-a Dosen) ====================
public class MataKuliah {                                               // Class mata kuliah (bukan turunan Orang)
    private String kodeMataKuliah;                                      // Menyimpan kode mata kuliah
    private String namaMataKuliah;                                      // Menyimpan nama mata kuliah
    private int sks;                                                    // Menyimpan jumlah SKS
    private Dosen dosen;                                                // Dosen yang mengajar (Composition)

    public MataKuliah(String kode, String nama, int sks, Dosen dosen) { // Constructor
        this.kodeMataKuliah = kode;                                     // Inisialisasi data
        this.namaMataKuliah = nama;                                     // Inisialisasi nama mata kuliah
        this.sks = sks;                                                 // Inisialisasi jumlah SKS
        this.dosen = dosen;                                             // Inisialisasi dosen pengajar
    }

    // --- Getter dan Setter ---

    public String getKodeMataKuliah() { return kodeMataKuliah; }        // Ambil kode mata kuliah
    public String getNamaMataKuliah() { return namaMataKuliah; }        // Ambil nama mata kuliah
    public int getSks() { return sks; }                                 // Ambil SKS
    public Dosen getDosen() { return dosen; }                           // Ambil dosen

    public void setKodeMataKuliah(String k) { kodeMataKuliah = k; }     // Ubah kode mata kuliah
    public void setNamaMataKuliah(String n) { namaMataKuliah = n; }     // Ubah nama mata kuliah
    public void setSks(int s) { sks = s; }                              // Ubah SKS
    public void setDosen(Dosen d) { dosen = d; }                        // Ubah dosen

    public void display() {                                             // Tampilkan data mata kuliah
        System.out.printf("%-5s  %-16s | ", kodeMataKuliah, namaMataKuliah); // Kode + nama 
        System.out.printf("SKS: %-1d | ", sks);                         // SKS 
        System.out.print("Dosen: ");                                    // Label dosen
        System.out.print(dosen.getNama() + " (" + dosen.getNamaFakultas() + ")"); // Nama dan FAKULTAS dosen
    }
}
