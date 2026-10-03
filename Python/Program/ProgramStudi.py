from copy import deepcopy                                    # Salin mata kuliah milik program studi


# ================= PROGRAM STUDI (Composition) =================
class ProgramStudi:                                          # Class program studi
    def __init__(self, id_program_studi, nama, jenjang):     # Constructor
        self.id_program_studi = id_program_studi             # Menyimpan ID program studi
        self.nama = nama                                     # Menyimpan nama program studi
        self.jenjang = jenjang                               # Menyimpan jenjang program studi
        self.mata_kuliah = []                                # Objek mata kuliah milik program studi

    def salin(self):                                         # Salin program studi beserta mata kuliah
        hasil = ProgramStudi(self.id_program_studi, self.nama, self.jenjang) # Salin data program studi
        hasil.mata_kuliah = deepcopy(self.mata_kuliah)       # Salin objek mata kuliah
        return hasil                                         # Kembalikan salinan program studi

    # --- Getter dan Setter ---
    def get_id_program_studi(self):                          # Ambil ID program studi
        return self.id_program_studi                         # Kembalikan ID program studi

    def get_nama(self):                                      # Ambil nama program studi
        return self.nama                                     # Kembalikan nama program studi

    def get_jenjang(self):                                   # Ambil jenjang program studi
        return self.jenjang                                  # Kembalikan jenjang program studi

    def get_mata_kuliah(self):                               # Ambil salinan daftar mata kuliah
        return deepcopy(self.mata_kuliah)                    # Kembalikan salinan daftar

    def set_id_program_studi(self, nilai):                   # Ubah ID program studi
        self.id_program_studi = nilai                        # Simpan ID baru

    def set_nama(self, nilai):                               # Ubah nama program studi
        self.nama = nilai                                    # Simpan nama baru

    def set_jenjang(self, nilai):                            # Ubah jenjang program studi
        self.jenjang = nilai                                 # Simpan jenjang baru

    def tambah_mata_kuliah(self, mk):                        # Tambah mata kuliah ke program studi
        self.mata_kuliah.append(deepcopy(mk))                # Simpan salinan mata kuliah
