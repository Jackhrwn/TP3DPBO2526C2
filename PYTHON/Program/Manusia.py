class Manusia:                              # Class dasar untuk semua orang di universitas
    def __init__(self, nama, id, umur):     # Constructor untuk inisialisasi data
        self.nama = nama                    # Inisialisasi nama
        self.id = id                        # Inisialisasi id
        self.umur = umur                    # Inisialisasi umur

    # --- Getter dan Setter ---

    def get_nama(self):                     # Ambil nama
        return self.nama

    def get_id(self):                       # Ambil ID
        return self.id

    def get_umur(self):                     # Ambil umur
        return self.umur

    def set_nama(self, n):                  # Ubah nama
        self.nama = n

    def set_id(self, i):                    # Ubah ID
        self.id = i

    def set_umur(self, u):                  # Ubah umur
        self.umur = u

    def display(self):                      # Tampilkan data manusia
        return f"Nama: {self.nama} | ID: {self.id} | Umur: {self.umur}"
