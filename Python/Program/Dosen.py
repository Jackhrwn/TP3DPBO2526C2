from Manusia import Manusia                                     # Import class Manusia dari Manusia.py

# ====================== DOSEN (Turunan dari Manusia) =======================
class Dosen(Manusia):                                           # Dosen mewarisi sifat Manusia
    def __init__(self, nama, id, umur, nama_fakultas, gaji):    # Constructor
        super().__init__(nama, id, umur)                        # Inisialisasi data
        self.nama_fakultas = nama_fakultas                      # Menyimpan Fakultas dosen
        self.gaji = gaji                                        # Menyimpan gaji dosen
        self.mata_kuliah_diajar = []                            # Menyimpan daftar mata kuliah yang diajar

    # --- Getter dan Setter ---

    def get_nama_fakultas(self):                                # Ambil Fakultas
        return self.nama_fakultas

    def get_gaji(self):                                         # Ambil gaji
        return self.gaji

    def get_mata_kuliah_diajar(self):                           # Ambil daftar mata kuliah
        return self.mata_kuliah_diajar

    def set_nama_fakultas(self, d):                             # Ubah Fakultas
        self.nama_fakultas = d

    def set_gaji(self, g):                                      # Ubah gaji
        self.gaji = g

    def set_mata_kuliah_diajar(self, mk):                       # Ubah daftar mata kuliah
        self.mata_kuliah_diajar = mk

    def ampu_mata_kuliah(self, kode_mata_kuliah):               # Dosen mengajar mata kuliah
        self.mata_kuliah_diajar.append(kode_mata_kuliah)        # Tambahkan ke daftar

    def display(self):                                          # Tampilkan data dosen
        result = "[DOSEN] "                                     # Label dosen
        result += f"{self.nama:<8} | "                          # Nama (lebar 8 + 2 spasi)
        result += f"ID: {self.id:<3} | "                        # ID (lebar 3 + 2 spasi)
        result += f"Umur: {self.umur:<1} | "                    # Umur (lebar 1 + 2 spasi)
        result += f"Fakultas: {self.nama_fakultas:<6} | "       # Fakultas (lebar 6 + 2 spasi)
        result += f"Gaji: Rp{self.gaji:<6}"                     # Gaji (lebar 6)
        if self.mata_kuliah_diajar:                             # Jika ada mata kuliah
            result += " | Mengajar: "                           # Label mengajar
            for i, kode in enumerate(self.mata_kuliah_diajar):  # Loop semua mata kuliah
                result += kode                                  # Tampilkan kode mata kuliah
                if i < len(self.mata_kuliah_diajar) - 1:        # Pemisah antar mata kuliah
                    result += ", "
        return result                                           # Kembalikan result