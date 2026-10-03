# ================= FAKULTAS (Composition) =================
class Fakultas:                                              # Class Fakultas
    def __init__(self, id_fakultas, nama):                   # Constructor
        self.id_fakultas = id_fakultas                       # Menyimpan ID Fakultas
        self.nama = nama                                     # Menyimpan nama Fakultas
        self.program_studi = []                              # Objek prodi milik Fakultas

    # --- Getter dan Setter ---
    def get_id_fakultas(self):                               # Ambil ID Fakultas
        return self.id_fakultas                              # Kembalikan ID Fakultas

    def get_nama(self):                                      # Ambil nama Fakultas
        return self.nama                                     # Kembalikan nama Fakultas

    def get_program_studi(self):                             # Ambil salinan daftar prodi
        return [prodi.salin() for prodi in self.program_studi]  # Kembalikan salinan semua prodi

    def set_id_fakultas(self, id_fakultas):                  # Ubah ID Fakultas
        self.id_fakultas = id_fakultas                       # Simpan ID baru

    def set_nama(self, nama):                                # Ubah nama Fakultas
        self.nama = nama                                     # Simpan nama baru

    def tambah_program_studi(self, prodi):                   # Tambah atau perbarui prodi
        for i, prodi_tersimpan in enumerate(self.program_studi):    # Cari prodi dengan ID yang sama
            if prodi_tersimpan.get_id_program_studi() == prodi.get_id_program_studi():
                self.program_studi[i] = prodi.salin()        # Perbarui prodi dengan ID sama
                return                                       # Hentikan setelah prodi diperbarui
        self.program_studi.append(prodi.salin())             # Simpan salinan prodi baru

    def display(self, nomor_fakultas=1):                     # Susun Fakultas beserta isinya dalam satu bingkai
        lines = [                                            # Siapkan baris data Fakultas
            f"[{nomor_fakultas}] Fakultas",                  # Tambahkan judul dan nomor Fakultas
            f"    ID Fakultas   : {self.id_fakultas}",       # Tambahkan ID Fakultas
            f"    Nama Fakultas : {self.nama}",              # Tambahkan nama Fakultas
            f"    Jumlah Prodi  : {len(self.program_studi)}",# Tambahkan jumlah program studi
        ]
        for indeks_prodi, prodi in enumerate(self.program_studi, start=1):      # Tampilkan setiap program studi
            lines.extend([
                "",                                                             # Pisahkan data antaprogram studi
                f"    [{indeks_prodi}] Program Studi",                          # Tampilkan judul dan nomor prodi
                f"        ID Prodi   : {prodi.get_id_program_studi()}",         # Tampilkan ID prodi
                f"        Nama Prodi : {prodi.get_nama()}",                     # Tampilkan nama prodi
                f"        Jenjang    : {prodi.get_jenjang()}",                  # Tampilkan jenjang prodi
            ])
            for indeks_mk, mk in enumerate(prodi.get_mata_kuliah(), start=1):   # Tampilkan seluruh mata kuliah prodi
                lines.extend([
                    f"        [{indeks_mk}] Mata Kuliah",                       # Tampilkan judul dan nomor mata kuliah
                    f"            ID Matkul   : {mk.get_kode_mata_kuliah()}",   # Tampilkan kode mata kuliah
                    f"            Nama Matkul : {mk.get_nama_mata_kuliah()}",   # Tampilkan nama mata kuliah
                    f"            SKS         : {mk.get_sks()}",                # Tampilkan jumlah SKS
                ])
        lebar = 52                                                              # Gunakan lebar bingkai tetap
        batas = "+" + "-" * (lebar + 2) + "+"                                   # Buat batas bingkai
        return "\n" + "\n".join([batas, *(f"| {line:<{lebar}} |" for line in lines), batas])  # Kembalikan bingkai
