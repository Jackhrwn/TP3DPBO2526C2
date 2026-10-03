import java.util.ArrayList;                                                           // Import ArrayList untuk komposisi mata kuliah
import java.util.List;                                                                // Import List untuk mengembalikan kumpulan data

// ================= PROGRAM STUDI (Composition) =================
public class ProgramStudi {                                                           // Class program studi
    private String idProgramStudi;                                                    // Menyimpan ID program studi
    private String nama;                                                              // Menyimpan nama program studi
    private String jenjang;                                                           // Menyimpan jenjang program studi
    private final ArrayList<MataKuliah> mataKuliah = new ArrayList<>();               // Objek mata kuliah milik program studi

    public ProgramStudi(String idProgramStudi, String nama, String jenjang) {         // Constructor
        this.idProgramStudi = idProgramStudi;                                         // Inisialisasi ID program studi
        this.nama = nama;                                                             // Inisialisasi nama program studi
        this.jenjang = jenjang;                                                       // Inisialisasi jenjang program studi
    }

    public ProgramStudi(ProgramStudi sumber) {                                        // Constructor salinan untuk composition
        this(sumber.idProgramStudi, sumber.nama, sumber.jenjang);                     // Salin data program studi
        for (MataKuliah mk : sumber.mataKuliah) {                                     // Loop mata kuliah sumber
            mataKuliah.add(new MataKuliah(mk));                                       // Salin objek mata kuliah
        }
    }

    // --- Getter dan Setter ---
    public String getIdProgramStudi() { return idProgramStudi; }                      // Ambil ID program studi
    public String getNama() { return nama; }                                          // Ambil nama program studi
    public String getJenjang() { return jenjang; }                                    // Ambil jenjang program studi
    public List<MataKuliah> getMataKuliah() {                                         // Ambil salinan mata kuliah
        ArrayList<MataKuliah> salinan = new ArrayList<>();                            // Siapkan daftar salinan
        for (MataKuliah mk : mataKuliah) {                                            // Loop semua mata kuliah
            salinan.add(new MataKuliah(mk));                                          // Salin objek mata kuliah
        }
        return List.copyOf(salinan);                                                  // Kembalikan daftar yang tidak dapat diubah
    }

    public void setIdProgramStudi(String idProgramStudi) { this.idProgramStudi = idProgramStudi; } // Ubah ID program studi
    public void setNama(String nama) { this.nama = nama; }                            // Ubah nama program studi
    public void setJenjang(String jenjang) { this.jenjang = jenjang; }                // Ubah jenjang program studi

    public void tambahMataKuliah(MataKuliah mk) {                                     // Tambah mata kuliah ke program studi
        mataKuliah.add(new MataKuliah(mk));                                           // Simpan salinan mata kuliah
    }

}
