class Manusia:                              # Class dasar untuk semua orang di universitas
    def __init__(self, nama, id, umur):     # Constructor untuk inisialisasi data
        self.nama = nama                    # Inisialisasi nama
        self.id = id                        # Inisialisasi id
        self.umur = umur                    # Inisialisasi umur

    # --- Getter dan Setter ---
    def get_nama(self):                     # Ambil nama
        return self.nama                    # Kembalikan nama

    def get_id(self):                       # Ambil ID
        return self.id                      # Kembalikan ID

    def get_umur(self):                     # Ambil umur
        return self.umur                    # Kembalikan umur

    def set_nama(self, n):                  # Ubah nama
        self.nama = n                       # Simpan nama baru

    def set_id(self, i):                    # Ubah ID
        self.id = i                         # Simpan ID baru

    def set_umur(self, u):                  # Ubah umur
        self.umur = u                       # Simpan umur baru

    def display(self):                      # Tampilkan data manusia
        return f"Nama: {self.nama} | ID: {self.id} | Umur: {self.umur}"  # Kembalikan data manusia