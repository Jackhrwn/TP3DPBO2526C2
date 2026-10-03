from Dosen import Dosen                                         # Import class Dosen dari Dosen.py
from Mahasiswa import Mahasiswa                                 # Import class Mahasiswa dari Mahasiswa.py
from MataKuliah import MataKuliah                               # Import class MataKuliah dari MataKuliah.py
from Fakultas import Fakultas                                   # Import class Fakultas dari Fakultas.py


def main():                                                     # Fungsi utama program
    print("=" * 50)                                             # Separator atas
    print("           SISTEM MANAJEMEN UNIVERSITAS")            # Judul program
    print("=" * 50 + "\n")                                      # Separator bawah judul

    # --- Buat Dosen ---
    dosen1 = Dosen("Bu Rosa", "P001", 45, "FPMIPA", 850000)     # Dosen pertama
    dosen2 = Dosen("Pak Yudi", "P002", 50, "FPOK", 900000)      # Dosen kedua
    dosen3 = Dosen("Pak Budi", "P003", 55, "FIP", 950000)       # Dosen ketiga

    # --- Buat Mahasiswa ---
    mhs1 = Mahasiswa("Bentar", "S001", 20, "Matematika", 3.8)   # Mahasiswa pertama
    mhs2 = Mahasiswa("Rian", "S002", 19, "PKO", 3.9)            # Mahasiswa kedua

    # --- Mahasiswa ambil mata kuliah ---
    mhs1.ambil_mata_kuliah("MIPA101")                           # mhs1 ambil MIPA101
    mhs1.ambil_mata_kuliah("MIPA201")                           # mhs1 ambil MIPA201
    mhs2.ambil_mata_kuliah("PJK101")                            # mhs2 ambil PJK101

    # --- Dosen ampu mata kuliah ---
    dosen1.ampu_mata_kuliah("MIPA101")                          # dosen1 ampu MIPA101
    dosen1.ampu_mata_kuliah("MIPA201")                          # dosen1 ampu MIPA201
    dosen2.ampu_mata_kuliah("PJK101")                           # dosen2 ampu PJK101

    # --- Buat Mata Kuliah (Composition: MataKuliah has-a Dosen) ---
    mk1 = MataKuliah("MIPA101", "Statistika Dasar", 3, dosen1)  # MK pertama
    mk2 = MataKuliah("MIPA201", "Biologi Sel", 4, dosen1)       # MK kedua
    mk3 = MataKuliah("PJK101", "Pendidikan Jasmani", 3, dosen2) # MK ketiga

    # --- Buat Fakultas (Composition: FAKULTAS has-a Dosen as dekan) ---
    fak_ilkom = Fakultas("FPMIPA", dosen1)                      # Fakultas FPMIPA
    fak_ilkom.tambah_mata_kuliah(mk1)                           # Tambah mk1 ke prodiIlkom
    fak_ilkom.tambah_mata_kuliah(mk2)                           # Tambah mk2 ke prodiIlkom

    fak_fisika = Fakultas("FPOK", dosen2)                       # Fakultas FPOK
    fak_fisika.tambah_mata_kuliah(mk3)                          # Tambah mk3 ke prodiFisika

    # ========================= TAMPILKAN SEBELUM MENAMBAH ==========================
    print(">>> DATA SEBELUM DITAMBAHKAN <<<\n")                 # Label sebelum menambah

    print("--- DOSEN ---")                                      # Label dosen
    print(dosen1.display())                                     # Tampilkan dosen1
    print(dosen2.display())                                     # Tampilkan dosen2
    print(dosen3.display())                                     # Tampilkan dosen3
    print()

    print("--- MAHASISWA ---")                                  # Label mahasiswa
    print(mhs1.display())                                       # Tampilkan mhs1
    print(mhs2.display())                                       # Tampilkan mhs2
    print()

    print("--- FAKULTAS ---")                                   # Label Fakultas
    print(fak_ilkom.display())                                  # Tampilkan prodiIlkom
    print(fak_fisika.display())                                 # Tampilkan prodiFisika

    # =============================== TAMBAH DATA BARU ===============================
    print("\n>>> MENAMBAHKAN DATA BARU <<<\n")                  # Label menambah data

    # --- Tambah dosen baru ---
    dosen4 = Dosen("Bu Dini", "P004", 60, "FIP", 500000)        # Dosen keempat
    dosen4.ampu_mata_kuliah("PGSD101")                          # dosen4 ampu PGSD101
    print("Ditambahkan dosen baru: Bu Dini")                    # Pesan

    # --- Tambah mahasiswa baru ---
    mhs3 = Mahasiswa("Repan", "S003", 22, "PGSD", 3.7)          # Mahasiswa ketiga
    mhs3.ambil_mata_kuliah("PGSD101")                           # mhs3 ambil PGSD101
    print("Ditambahkan mahasiswa baru: Repan")                  # Pesan

    # --- Tambah mata kuliah baru ---
    mk4 = MataKuliah("PGSD101", "Landasan Pendidikan", 4, dosen4)           # MK keempat
    print("Ditambahkan mata kuliah baru: PGSD101 - Landasan Pendidikan")    # Pesan

    # --- Tambah fakultas baru ---
    fak_fip = Fakultas("FIP", dosen4)                           # Fakultas FIP
    fak_fip.tambah_mata_kuliah(mk4)                             # Tambah mk4 ke prodiFIP
    print("Ditambahkan fakultas baru: FIP")                     # Pesan

    # --- Tambah mata kuliah yang diajar Pak Budi ---
    mk6 = MataKuliah("BIM201", " Bimbingan Konseling", 3, dosen3)  # MK keenam
    fak_fip.tambah_mata_kuliah(mk6)                             # Tambah mk6 ke prodiFIP
    dosen3.ampu_mata_kuliah("BIM201")                           # dosen3 ampu BIM201
    print("Ditambahkan mata kuliah baru yang diajar Pak Budi: BIM201 - Bimbingan Konseling")  # Pesan

    # --- Tambah mata kuliah ke FAKULTAS yang ada ---
    mk5 = MataKuliah("MIPA301", "Kimia Analitik", 3, dosen1)    # MK kelima
    fak_ilkom.tambah_mata_kuliah(mk5)                           # Tambah mk5 ke prodiIlkom
    dosen1.ampu_mata_kuliah("MIPA301")                          # dosen1 ampu MIPA301
    print("Ditambahkan mata kuliah baru ke fakultas FPMIPA: MIPA301 - Kimia Analitik")  # Pesan

    # ========================== TAMPILKAN SESUDAH MENAMBAH ==========================
    print("\n>>> DATA SESUDAH DITAMBAHKAN <<<\n")               # Label sesudah menambah

    print("--- DOSEN ---")                                      # Label dosen
    print(dosen1.display())                                     # Tampilkan dosen1
    print(dosen2.display())                                     # Tampilkan dosen2
    print(dosen3.display())                                     # Tampilkan dosen3
    print(dosen4.display())                                     # Tampilkan dosen4
    print()

    print("--- MAHASISWA ---")                                  # Label mahasiswa
    print(mhs1.display())                                       # Tampilkan mhs1
    print(mhs2.display())                                       # Tampilkan mhs2
    print(mhs3.display())                                       # Tampilkan mhs3
    print()

    print("--- FAKULTAS ---")                                   # Label Fakultas
    print(fak_ilkom.display())                                  # Tampilkan prodiIlkom
    print(fak_fisika.display())                                 # Tampilkan prodiFisika
    print(fak_fip.display())                                    # Tampilkan prodiFIP

    print("\n" + "=" * 51)                                      # Separator bawah (51 karakter)
    print("                  PROGRAM SELESAI")                  # Pesan selesai
    print("=" * 51)                                             # Separator akhir (51 karakter)


if __name__ == "__main__":
    main()