from Manusia import Manusia                                 # Import class Manusia dari Manusia.py

# ======================= MAHASISWA (Turunan dari Manusia) =======================
class Mahasiswa(Manusia):                                   # Mahasiswa mewarisi sifat Manusia
    def __init__(self, nama, id, umur, program_studi, ipk): # Constructor
        super().__init__(nama, id, umur)                    # Inisialisasi data
        self.program_studi = program_studi                  # Menyimpan program studi
        self.ipk = ipk                                      # Menyimpan IPK
        self.mata_kuliah_diambil = []                       # Menyimpan daftar mata kuliah yang diambil

    # --- Getter dan Setter ---
    def get_program_studi(self):                            # Ambil program studi
        return self.program_studi                           # Kembalikan program studi

    def get_ipk(self):                                      # Ambil IPK
        return self.ipk                                     # Kembalikan IPK

    def get_mata_kuliah_diambil(self):                      # Ambil daftar mata kuliah
        return self.mata_kuliah_diambil.copy()              # Kembalikan salinan daftar

    def set_program_studi(self, nilai):                     # Ubah program studi
        self.program_studi = nilai                          # Simpan program studi baru

    def set_ipk(self, i):                                   # Ubah IPK
        self.ipk = i                                        # Simpan IPK baru

    def set_mata_kuliah_diambil(self, mk):                  # Ubah daftar mata kuliah
        self.mata_kuliah_diambil = list(mk)                 # Simpan salinan daftar baru

    def ambil_mata_kuliah(self, kode_mata_kuliah):          # Mahasiswa mengambil mata kuliah
        self.mata_kuliah_diambil.append(kode_mata_kuliah)   # Tambahkan ke daftar

    def display(self, nomor=1):                             # Susun data mahasiswa dalam bingkai
        lines = [                                           # Siapkan baris data mahasiswa
            f"[{nomor}] Mahasiswa",                         # Tambahkan judul dan nomor mahasiswa
            f"    ID Mahasiswa  : {self.id}",               # Tampilkan ID mahasiswa
            f"    Nama          : {self.nama}",             # Tampilkan nama mahasiswa
            f"    Umur          : {self.umur}",             # Tampilkan umur mahasiswa
            f"    Program Studi : {self.program_studi}",    # Tampilkan program studi mahasiswa
            f"    IPK           : {self.ipk:.2f}",          # Tampilkan IPK dengan dua desimal
        ]
        for indeks, kode in enumerate(self.mata_kuliah_diambil, start=1):   # Tampilkan setiap mata kuliah yang diambil
            lines.append(f"    [{indeks}] Mata Kuliah Diambil : {kode}")    # Tambahkan mata kuliah yang diambil
        lebar = 52                                          # Gunakan lebar bingkai tetap
        batas = "+" + "-" * (lebar + 2) + "+"               # Buat batas bingkai
        return "\n" + "\n".join([batas, *(f"| {line:<{lebar}} |" for line in lines), batas])  # Kembalikan bingkai