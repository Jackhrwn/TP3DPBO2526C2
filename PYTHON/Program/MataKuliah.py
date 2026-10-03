# =================== MATA KULIAH (Composition: has-a Dosen) ====================
class MataKuliah:                                   # Class mata kuliah (bukan turunan Orang)
    def __init__(self, kode, nama, sks, dosen):     # Constructor
        self.kode_mata_kuliah = kode                # Menyimpan kode mata kuliah
        self.nama_mata_kuliah = nama                # Menyimpan nama mata kuliah
        self.sks = sks                              # Menyimpan jumlah SKS
        self.dosen = dosen                          # Dosen yang mengajar (Composition)

    # --- Getter dan Setter ---

    def get_kode_mata_kuliah(self):                 # Ambil kode mata kuliah
        return self.kode_mata_kuliah

    def get_nama_mata_kuliah(self):                 # Ambil nama mata kuliah
        return self.nama_mata_kuliah

    def get_sks(self):                              # Ambil SKS
        return self.sks

    def get_dosen(self):                            # Ambil dosen
        return self.dosen

    def set_kode_mata_kuliah(self, k):              # Ubah kode mata kuliah
        self.kode_mata_kuliah = k

    def set_nama_mata_kuliah(self, n):              # Ubah nama mata kuliah
        self.nama_mata_kuliah = n

    def set_sks(self, s):                           # Ubah SKS
        self.sks = s

    def set_dosen(self, d):                         # Ubah dosen
        self.dosen = d

    def display(self):                              # Tampilkan data mata kuliah
        result = f"{self.kode_mata_kuliah:<5}  {self.nama_mata_kuliah:<16} | "  # Kode + nama 
        result += f"SKS: {self.sks:<1} | "          # SKS 
        result += "Dosen: "  # Label dosen
        result += f"{self.dosen.get_nama()} ({self.dosen.get_nama_fakultas()})"  # Nama dan Fakultas dosen
        return result
