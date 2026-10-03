from Manusia import Manusia                                  # Import class Manusia dari Manusia.py

# ====================== DOSEN (Turunan dari Manusia) =======================
class Dosen(Manusia):                                        # Dosen mewarisi atribut dasar Manusia
    def __init__(self, nama, id, umur, program_studi, gaji): # Constructor
        super().__init__(nama, id, umur)                     # Inisialisasi data manusia
        self.program_studi = program_studi                   # Menyimpan program studi dosen
        self.gaji = gaji                                     # Menyimpan gaji dosen
        self.mata_kuliah_diajar = []                         # Menyimpan kode mata kuliah yang diampu

    # --- Getter dan Setter ---
    def get_program_studi(self):                             # Ambil program studi
        return self.program_studi                            # Kembalikan program studi

    def get_gaji(self):                                      # Ambil gaji
        return self.gaji                                     # Kembalikan gaji

    def set_program_studi(self, nilai):                      # Ubah program studi
        self.program_studi = nilai                           # Simpan program studi baru

    def set_gaji(self, nilai):                               # Ubah gaji
        self.gaji = nilai                                    # Simpan gaji baru

    def get_mata_kuliah_diajar(self):                        # Ambil daftar mata kuliah yang diampu
        return self.mata_kuliah_diajar.copy()                # Kembalikan salinan daftar

    def set_mata_kuliah_diajar(self, mk):                    # Ubah daftar mata kuliah yang diampu
        self.mata_kuliah_diajar = mk.copy()                  # Simpan salinan daftar baru

    def ampu_mata_kuliah(self, kode):                        # Catat mata kuliah yang diampu
        self.mata_kuliah_diajar.append(kode)                 # Tambahkan kode ke daftar

    def display(self, nomor=1):                              # Susun data dosen dalam bingkai
        lines = [
            f"[{nomor}] Dosen",                              # Tambahkan judul dan nomor dosen
            f"    ID Dosen       : {self.id}",               # Tampilkan ID dosen
            f"    Nama           : {self.nama}",             # Tampilkan nama dosen
            f"    Umur           : {self.umur}",             # Tampilkan umur dosen
            f"    Program Studi  : {self.program_studi}",    # Tampilkan program studi dosen
            f"    Gaji           : Rp{self.gaji:.0f}",       # Tampilkan gaji tanpa desimal
        ]
        for indeks, kode in enumerate(self.mata_kuliah_diajar, start=1):  # Tampilkan setiap mata kuliah yang diampu
            lines.append(f"    [{indeks}] Mata Kuliah Diajar : {kode}")  # Tambahkan mata kuliah yang diampu
        lebar = 52                                             # Gunakan lebar bingkai tetap
        batas = "+" + "-" * (lebar + 2) + "+"                 # Buat batas bingkai
        return "\n" + "\n".join([batas, *(f"| {line:<{lebar}} |" for line in lines), batas])  # Kembalikan bingkai
