# =================== MATA KULIAH (Bagian dari Fakultas) ====================
class MataKuliah:                                    # Class mata kuliah (bukan turunan Manusia)
    def __init__(self, kode, nama, sks):             # Constructor
        self.kode_mata_kuliah = kode                 # Menyimpan kode mata kuliah
        self.nama_mata_kuliah = nama                 # Menyimpan nama mata kuliah
        self.sks = sks                               # Menyimpan jumlah SKS

    # --- Getter dan Setter ---
    def get_kode_mata_kuliah(self):                  # Ambil kode mata kuliah
        return self.kode_mata_kuliah                 # Kembalikan kode mata kuliah

    def get_nama_mata_kuliah(self):                  # Ambil nama mata kuliah
        return self.nama_mata_kuliah                 # Kembalikan nama mata kuliah

    def get_sks(self):                               # Ambil SKS
        return self.sks                              # Kembalikan jumlah SKS

    def set_kode_mata_kuliah(self, kode):            # Ubah kode mata kuliah
        self.kode_mata_kuliah = kode                 # Simpan kode baru

    def set_nama_mata_kuliah(self, nama):            # Ubah nama mata kuliah
        self.nama_mata_kuliah = nama                 # Simpan nama baru

    def set_sks(self, jumlah):                       # Ubah SKS
        self.sks = jumlah                            # Simpan jumlah SKS baru

    def display(self):                               # Tampilkan data mata kuliah
        return (
            f"{'Kode':<9}: {self.kode_mata_kuliah:<9} | "   # Tampilkan kode
            f"{'Nama':<8}: {self.nama_mata_kuliah:<26} | "  # Tampilkan nama
            f"{'SKS':<4}: {self.sks}"                       # Tampilkan SKS
        )
