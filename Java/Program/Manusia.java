public class Manusia {                                          // Class dasar untuk semua orang di universitas
    protected String nama;                                      // Menyimpan nama manusia
    protected String id;                                        // Menyimpan ID manusia
    protected int umur;                                         // Menyimpan umur manusia

    public Manusia(String nama, String id, int umur) {          // Constructor untuk inisialisasi data
        this.nama = nama;                                       // Inisialisasi nama
        this.id = id;                                           // Inisialisasi id
        this.umur = umur;                                       // Inisialisasi umur 
    }

    // --- Getter dan Setter ---
    public String getNama() { return nama; }                    // Ambil nama
    public String getId() { return id; }                        // Ambil ID
    public int getUmur() { return umur; }                       // Ambil umur

    public void setNama(String n) { nama = n; }                 // Ubah nama
    public void setId(String i) { id = i; }                     // Ubah ID
    public void setUmur(int u) { umur = u; }                    // Ubah umur

    public void display() {                                     // Tampilkan data manusia
        System.out.print("Nama: " + nama + " | ID: " + id + " | Umur: " + umur); // Tampilkan nama, ID, dan umur
    }
}
