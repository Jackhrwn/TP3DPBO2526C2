from Manusia import Manusia                                 # Import class Manusia dari Manusia.py

# ======================= MAHASISWA (Turunan dari Manusia) =======================
class Mahasiswa(Manusia):                                   # Mahasiswa mewarisi sifat Manusia
    def __init__(self, nama, id, umur, jurusan, ipk):       # Constructor
        super().__init__(nama, id, umur)                    # Inisialisasi data
        self.jurusan = jurusan                              # Menyimpan jurusan
        self.ipk = ipk                                      # Menyimpan IPK
        self.mata_kuliah_diambil = []                       # Menyimpan daftar mata kuliah yang diambil

    # --- Getter dan Setter ---

    def get_jurusan(self):                                  # Ambil jurusan
        return self.jurusan

    def get_ipk(self):                                      # Ambil IPK
        return self.ipk

    def get_mata_kuliah_diambil(self):                      # Ambil daftar mata kuliah
        return self.mata_kuliah_diambil

    def set_jurusan(self, j):                               # Ubah jurusan
        self.jurusan = j

    def set_ipk(self, i):                                   # Ubah IPK
        self.ipk = i

    def set_mata_kuliah_diambil(self, mk):                  # Ubah daftar mata kuliah
        self.mata_kuliah_diambil = mk

    def ambil_mata_kuliah(self, kode_mata_kuliah):          # Mahasiswa mengambil mata kuliah
        self.mata_kuliah_diambil.append(kode_mata_kuliah)   # Tambahkan ke daftar

    def display(self):                                      # Tampilkan data mahasiswa
        result = "[MAHASISWA] "                             # Label mahasiswa
        result += f"{self.nama:<6} | "                      # Nama (lebar 6 + 2 spasi)
        result += f"ID: {self.id:<3} | "                    # ID (lebar 3 + 2 spasi)
        result += f"Umur: {self.umur:<1} | "                # Umur (lebar 1 + 2 spasi)
        result += f"Jurusan: {self.jurusan:<10} | "         # Jurusan (lebar 10 + 2 spasi)
        result += f"IPK: {self.ipk:<2}"                     # IPK (lebar 2)
        if self.mata_kuliah_diambil:                        # Jika ada mata kuliah
            result += " | Mata Kuliah: "                    # Label mata kuliah
            for i, kode in enumerate(self.mata_kuliah_diambil):  # Loop semua mata kuliah
                result += kode                              # Tampilkan kode mata kuliah
                if i < len(self.mata_kuliah_diambil) - 1:   # Pemisah antar mata kuliah
                    result += ", "
        return result                                       # Kembalikan result