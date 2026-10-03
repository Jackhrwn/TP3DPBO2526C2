from Dosen import Dosen                                           # Import class Dosen dari Dosen.py
from Mahasiswa import Mahasiswa                                   # Import class Mahasiswa dari Mahasiswa.py
from MataKuliah import MataKuliah                                 # Import class MataKuliah dari MataKuliah.py
from ProgramStudi import ProgramStudi                             # Import class ProgramStudi dari ProgramStudi.py
from Fakultas import Fakultas                                     # Import class Fakultas dari Fakultas.py


def tampilkan_gabungan(kartu):                                    # Tampilkan beberapa kartu dengan satu bingkai luar
    isi_kartu = []                                                # Simpan isi tiap kartu
    lebar = 52                                                    # Gunakan lebar tetap untuk semua bingkai
    for kartu_data in kartu:                                      # Proses setiap kartu
        baris_kartu = []                                          # Siapkan baris untuk satu kartu
        for baris in kartu_data.splitlines():                     # Periksa setiap baris kartu
            if not baris.startswith("| "):
                continue                                          # Abaikan batas kartu lama
            akhir = baris.rfind(" |")                             # Cari penutup kolom isi
            if akhir < 2:
                continue                                          # Abaikan baris yang bukan isi
            isi = baris[2:akhir].rstrip()                         # Buang padding lama
            baris_kartu.append(isi)                               # Simpan baris isi
        isi_kartu.append(baris_kartu)                             # Simpan satu kartu

    batas = "+" + "-" * (lebar + 2) + "+"                         # Buat garis bingkai
    print(batas)                                                  # Cetak batas atas
    for indeks, baris_kartu in enumerate(isi_kartu):              # Tampilkan isi semua kartu
        for baris in baris_kartu:
            print(f"| {baris:<{lebar}} |")                        # Cetak isi kartu
        if indeks + 1 < len(isi_kartu):
            print(batas)                                          # Pisahkan kartu dengan satu garis
    print(batas)                                                  # Cetak batas bawah


def main():                                                       # Fungsi utama program
    print("=" * 50)                                               # Separator atas
    print("           SISTEM MANAJEMEN UNIVERSITAS")              # Judul program
    print("=" * 50 + "\n")                                        # Separator bawah judul

    # --- Buat Fakultas ---
    fak_mipa = Fakultas("F001", "FPMIPA")                         # Fakultas FPMIPA
    fak_pok = Fakultas("F002", "FPOK")                            # Fakultas FPOK

    # --- Buat Program Studi ---
    prodi_ilkom = ProgramStudi("PS001", "Ilmu Komputer", "S1")    # Program Studi Ilmu Komputer
    prodi_matematika = ProgramStudi("PS002", "Matematika", "S1")  # Program Studi Matematika
    prodi_pko = ProgramStudi("PS003", "PKO", "S1")                # Program Studi PKO

    # --- Buat Mata Kuliah ---
    mk1 = MataKuliah("ILK101", "Dasar Pemrograman", 3)            # MK pertama
    mk2 = MataKuliah("MTK101", "Statistika Dasar", 3)             # MK kedua
    mk3 = MataKuliah("MTK201", "Kalkulus I", 4)                   # MK ketiga
    mk4 = MataKuliah("PJK101", "Pendidikan Jasmani", 3)           # MK keempat
    prodi_ilkom.tambah_mata_kuliah(mk1)                           # Tambah mk1 ke prodi_ilkom
    prodi_matematika.tambah_mata_kuliah(mk2)                      # Tambah mk2 ke prodi_matematika
    prodi_matematika.tambah_mata_kuliah(mk3)                      # Tambah mk3 ke prodi_matematika
    prodi_pko.tambah_mata_kuliah(mk4)                             # Tambah mk4 ke prodi_pko

    # --- Buat Dosen ---
    dosen1 = Dosen("Bu Rosa", "D001", 45, "Ilmu Komputer", 850000) # Dosen pertama
    dosen2 = Dosen("Pak Yudi", "D002", 50, "PKO", 900000)          # Dosen kedua
    dosen3 = Dosen("Pak Budi", "D003", 55, "Matematika", 950000)   # Dosen ketiga
    dosen1.ampu_mata_kuliah("ILK101")                              # dosen1 mengampu ILK101
    dosen2.ampu_mata_kuliah("PJK101")                              # dosen2 mengampu PJK101
    dosen3.ampu_mata_kuliah("MTK101")                              # dosen3 mengampu MTK101
    dosen3.ampu_mata_kuliah("MTK201")                              # dosen3 mengampu MTK201

    # --- Susun program studi ke Fakultas ---
    fak_mipa.tambah_program_studi(prodi_ilkom)                     # Tambah prodi_ilkom ke FPMIPA
    fak_mipa.tambah_program_studi(prodi_matematika)                # Tambah prodi_matematika ke FPMIPA
    fak_pok.tambah_program_studi(prodi_pko)                        # Tambah prodi_pko ke FPOK

    # --- Buat Mahasiswa ---
    mhs1 = Mahasiswa("Bentar", "M001", 20, "Ilmu Komputer", 3.8)   # Mahasiswa pertama
    mhs2 = Mahasiswa("Rian", "M002", 19, "PKO", 3.9)               # Mahasiswa kedua
    mhs1.ambil_mata_kuliah("ILK101")                               # mhs1 mengambil ILK101
    mhs2.ambil_mata_kuliah("PJK101")                               # mhs2 mengambil PJK101

    # ========================= TAMPILKAN SEBELUM MENAMBAH ==========================
    print(">>> DATA SEBELUM DITAMBAHKAN <<<\n")                    # Label sebelum menambah

    print("--- FAKULTAS, PROGRAM STUDI, DAN MATA KULIAH ---")      # Label hierarki akademik
    tampilkan_gabungan([fak_mipa.display(1), fak_pok.display(2)])  # Tampilkan hierarki dalam satu bingkai

    print("\n--- DOSEN ---")                                       # Label dosen
    tampilkan_gabungan([dosen1.display(1), dosen2.display(2), dosen3.display(3)])  # Tampilkan dosen dalam satu bingkai

    print("\n--- MAHASISWA ---")                                   # Label mahasiswa
    tampilkan_gabungan([mhs1.display(1), mhs2.display(2)])         # Tampilkan mahasiswa dalam satu bingkai

    # =============================== TAMBAH DATA BARU ===============================
    print("\n>>> MENAMBAHKAN DATA BARU <<<\n")                     # Label menambah data
    # --- Buat Fakultas baru ---
    fak_fip = Fakultas("F003", "FIP")                              # Fakultas FIP
    print(f"{'Fakultas baru':<22}: F003 - FIP")                    # Tampilkan data Fakultas baru

    # --- Buat Program Studi baru ---
    prodi_pgsd = ProgramStudi("PS004", "Pendidikan Guru SD", "S1")         # Program Studi PGSD
    print(f"{'Program studi baru':<22}: PS004 - Pendidikan Guru SD (S1)")  # Tampilkan data prodi baru

    # --- Buat Mata Kuliah baru ---
    mk5 = MataKuliah("PGSD101", "Landasan Pendidikan", 4)          # MK kelima
    mk6 = MataKuliah("PGSD201", "Bimbingan Konseling", 3)          # MK keenam
    mk7 = MataKuliah("MTK301", "Kalkulus II", 3)                   # MK ketujuh
    prodi_pgsd.tambah_mata_kuliah(mk5)                             # Tambah mk5 ke prodi_pgsd
    print(f"{'Mata kuliah baru':<22}: PGSD101 - Landasan Pendidikan (4 SKS)")  # Tampilkan mata kuliah baru
    prodi_pgsd.tambah_mata_kuliah(mk6)                             # Tambah mk6 ke prodi_pgsd
    print(f"{'':<22}: PGSD201 - Bimbingan Konseling (3 SKS)")      # Tampilkan mata kuliah tambahan
    prodi_matematika.tambah_mata_kuliah(mk7)                       # Tambah mk7 ke prodi_matematika
    print(f"{'':<22}: MTK301 - Kalkulus II (3 SKS)")               # Tampilkan mata kuliah tambahan

    # --- Buat Dosen baru ---
    dosen4 = Dosen("Bu Dini", "D004", 60, "Pendidikan Guru SD", 500000)  # Dosen keempat
    print(f"{'Dosen baru':<22}: D004 - Bu Dini")                   # Tampilkan data Dosen baru
    dosen4.ampu_mata_kuliah("PGSD101")                             # dosen4 mengampu PGSD101
    dosen4.ampu_mata_kuliah("PGSD201")                             # dosen4 mengampu PGSD201
    dosen3.ampu_mata_kuliah("MTK301")                              # dosen3 mengampu MTK301

    # --- Susun program studi baru ke Fakultas ---
    fak_fip.tambah_program_studi(prodi_pgsd)                       # Tambah prodi_pgsd ke FIP
    fak_mipa.tambah_program_studi(prodi_matematika)                # Perbarui data prodi_matematika

    # --- Buat Mahasiswa baru ---
    mhs3 = Mahasiswa("Repan", "M003", 22, "Pendidikan Guru SD", 3.7)  # Mahasiswa ketiga
    print(f"{'Mahasiswa baru':<22}: M003 - Repan\n")               # Tampilkan data Mahasiswa baru
    mhs3.ambil_mata_kuliah("PGSD101")                              # mhs3 mengambil PGSD101
    mhs3.ambil_mata_kuliah("PGSD201")                              # mhs3 mengambil PGSD201

    # ========================== TAMPILKAN SESUDAH MENAMBAH ==========================
    print("\n>>> DATA SESUDAH DITAMBAHKAN <<<\n")                  # Label sesudah menambah
    print("--- FAKULTAS, PROGRAM STUDI, DAN MATA KULIAH ---")      # Label hierarki akademik
    tampilkan_gabungan([fak_mipa.display(1), fak_pok.display(2), fak_fip.display(3)])  # Tampilkan hierarki dalam satu bingkai

    print("\n--- DOSEN ---")                                       # Label dosen
    tampilkan_gabungan([dosen1.display(1), dosen2.display(2), dosen3.display(3), dosen4.display(4)])  # Tampilkan dosen dalam satu bingkai

    print("\n--- MAHASISWA ---")                                   # Label mahasiswa
    tampilkan_gabungan([mhs1.display(1), mhs2.display(2), mhs3.display(3)])  # Tampilkan mahasiswa dalam satu bingkai

    print("\n" + "=" * 51)                                         # Separator bawah
    print("                  PROGRAM SELESAI")                     # Pesan selesai
    print("=" * 51)                                                # Separator akhir


if __name__ == "__main__":
    main()
