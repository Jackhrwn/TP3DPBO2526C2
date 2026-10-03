# ================= FAKULTAS (Composition) =================
class Fakultas:                         # Class Fakultas (bukan turunan Manusia)
    def __init__(self, nama, dekan):    # Constructor
        self.nama = nama                # Menyimpan nama Fakultas
        self.dekan = dekan              # Dosen yang menjadi dekan (Composition)
        self.mata_kuliah = []           # Daftar mata kuliah di Fakultas ini

    # --- Getter dan Setter ---

    def get_nama(self):                 # Ambil nama Fakultas
        return self.nama

    def get_dekan(self):                # Ambil dekan
        return self.dekan

    def get_mata_kuliah(self):          # Ambil daftar mata kuliah
        return self.mata_kuliah

    def set_nama(self, n):              # Ubah nama Fakultas
        self.nama = n

    def set_dekan(self, k):             # Ubah dekan
        self.dekan = k

    def set_mata_kuliah(self, mk):      # Ubah daftar mata kuliah
        self.mata_kuliah = mk

    def tambah_mata_kuliah(self, mk):   # Tambah mata kuliah ke Fakultas
        self.mata_kuliah.append(mk)     # Tambahkan ke vector

    def display(self):                  # Tampilkan data Fakultas
        lines = []                      # Simpan semua baris output

        lines.append("Fakultas: " + self.nama)  # Baris nama Fakultas

        baris_dekan = f"Dekan: {self.dekan.get_nama()} (ID: {self.dekan.get_id()})"  # Baris dekan
        lines.append(baris_dekan)                                # Simpan baris dekan

        lines.append(f"Mata Kuliah ({len(self.mata_kuliah)}):")  # Baris jumlah mata kuliah

        for i, mk in enumerate(self.mata_kuliah):                # Loop semua mata kuliah
            lines.append(f"  {i + 1}. {mk.display()}")           # Simpan baris mata kuliah

        # Tampilkan dengan separator
        result = "\n" + "=" * 69 + "\n"                          # Separator atas (69 karakter)
        result += "\n".join(lines) + "\n"
        result += "=" * 69                                       # Separator bawah (69 karakter)
        return result