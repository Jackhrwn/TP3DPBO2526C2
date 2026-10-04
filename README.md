# 🏫 University Management System - OOP Implementation

Program ini merupakan implementasi **University Management System** (Sistem Manajemen Universitas) menggunakan pendekatan **Object-Oriented Programming (OOP)**. Program mengelola data Manusia, Dosen, Mahasiswa, Mata Kuliah, Program Studi, dan Fakultas dengan konsep pewarisan, composition, serta koleksi objek dan kode mata kuliah. Implementasi tersedia dalam **C++**, **Java**, dan **Python**.

## ❤️ Janji

Saya Jaka Permana Herawan dengan NIM 2509371 mengerjakan Tugas Praktikum 3 pada Mata Kuliah Desain dan Pemrograman Berorientasi Objek (DPBO) untuk keberkahan-Nya maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin

---

## 🎨 Desain Diagram Program

![Design](Design%20Diagram.png)

### Keterangan Simbol
- `#` = atribut protected.
- `-` = atribut private.
- `+` = method public.
- `▷` = inheritance.
- `◆` = composition.

### Penjelasan Desain Program

#### *a. Hierarchical Inheritance*

```
Manusia (Base Class)
├── Mahasiswa (Derived Class)
└── Dosen     (Derived Class)
```

- **Manusia** adalah base class yang berisi atribut dan method umum yang dimiliki semua orang dalam sistem universitas (nama, id, umur).
- **Mahasiswa** dan **Dosen** adalah derived class yang mewarisi semua atribut dan method dari Manusia, lalu menambahkan atribut spesifik masing-masing.
- Mahasiswa menambahkan: `program_studi`, `ipk`, `mata_kuliah_diambil`
- Dosen menambahkan: `program_studi`, `gaji`, `mata_kuliah_diajar`
- Mahasiswa dan Dosen memiliki method tampilan khusus yang menyertakan atribut masing-masing dan daftar kode mata kuliah.

#### *b. Composition (Has-A Relationship)*

**Fakultas memiliki ProgramStudi**

ProgramStudi dikelompokkan di bawah Fakultas yang menaunginya. Dalam model ini, Fakultas menyimpan objek ProgramStudi sebagai bagiannya; jika Fakultas dihapus, ProgramStudi di dalamnya juga tidak lagi menjadi bagian dari data.

**ProgramStudi memiliki MataKuliah**

MataKuliah merupakan bagian dari kurikulum ProgramStudi. Karena itu, ProgramStudi menyimpan objek MataKuliah; jika ProgramStudi dihapus, mata kuliah yang tersimpan di dalamnya juga ikut terhapus dari model.




#### *c. Array of Objects*

Array of Objects digunakan untuk menyimpan beberapa objek sejenis dalam satu kumpulan. Implementasi menggunakan `vector` di C++, `ArrayList` di Java, dan `list` di Python.

1. **Fakultas.programStudi / program_studi** — Kumpulan objek `ProgramStudi` milik Fakultas.
2. **ProgramStudi.mataKuliah / mata_kuliah** — Kumpulan objek `MataKuliah` dalam Program Studi.

Daftar mata kuliah pada **Mahasiswa** (`mataKuliahDiambil` / `mata_kuliah_diambil`) dan **Dosen** (`mataKuliahDiajar` / `mata_kuliah_diajar`) berisi kode bertipe teks, bukan objek `MataKuliah`.

---

## Penjelasan Atribut dan Methods Setiap Kelas

### 1. Manusia (Base Class)

| Atribut | Tipe Data | Keterangan |
|---------|-----------|------------|
| nama | String | Nama lengkap orang |
| id | String | ID unik (NIP/NIM) |
| umur | int | Umur dalam tahun |

| Method | C++ / Java | Python | Keterangan |
|--------|-----------|--------|------------|
| Menampilkan data | `display()` | `display()` | Menampilkan nama, ID, dan umur; Python mengembalikan teks. |
| Getter | `getNama()`, `getId()`, `getUmur()` | `get_nama()`, `get_id()`, `get_umur()` | Mengambil nilai atribut dasar. |
| Setter | `setNama()`, `setId()`, `setUmur()` | `set_nama()`, `set_id()`, `set_umur()` | Mengubah nilai atribut dasar. |

---

### 2. Mahasiswa (Turunan dari Manusia)

| Atribut | Tipe Data | Keterangan |
|---------|-----------|------------|
| programStudi / program_studi | String | Program studi tempat mahasiswa terdaftar |
| ipk | double | Indeks Prestasi Kumulatif |
| mataKuliahDiambil / mata_kuliah_diambil | List/Array | Daftar kode mata kuliah yang diambil |

| Method | C++ / Java | Python | Keterangan |
|--------|-----------|--------|------------|
| Mengambil mata kuliah | `ambilMataKuliah(kode)` | `ambil_mata_kuliah(kode)` | Menambahkan kode ke daftar mata kuliah yang diambil. |
| Menyusun tampilan | `render(nomor)` | `display(nomor=1)` | Membentuk tampilan data mahasiswa di dalam bingkai; C++/Java juga menyediakan `display()` untuk mencetaknya. |
| Getter | `getProgramStudi()`, `getIpk()`, `getMataKuliahDiambil()` | `get_program_studi()`, `get_ipk()`, `get_mata_kuliah_diambil()` | Mengambil nilai atribut mahasiswa. |
| Setter | `setProgramStudi()`, `setIpk()`, `setMataKuliahDiambil()` | `set_program_studi()`, `set_ipk()`, `set_mata_kuliah_diambil()` | Mengubah nilai atribut mahasiswa. |

---

### 3. Dosen (Turunan dari Manusia)

| Atribut | Tipe Data | Keterangan |
|---------|-----------|------------|
| programStudi / program_studi | String | Program studi tempat dosen bertugas |
| gaji | double | Gaji per bulan |
| mataKuliahDiajar / mata_kuliah_diajar | List/Array | Daftar kode mata kuliah yang diampu |

| Method | C++ / Java | Python | Keterangan |
|--------|-----------|--------|------------|
| Mengampu mata kuliah | `ampuMataKuliah(kode)` | `ampu_mata_kuliah(kode)` | Menambahkan kode ke daftar mata kuliah yang diampu. |
| Menyusun tampilan | `render(nomor)` | `display(nomor=1)` | Membentuk tampilan data dosen di dalam bingkai; C++/Java juga menyediakan `display()` untuk mencetaknya. |
| Getter | `getProgramStudi()`, `getGaji()`, `getMataKuliahDiajar()` | `get_program_studi()`, `get_gaji()`, `get_mata_kuliah_diajar()` | Mengambil nilai atribut dosen. |
| Setter | `setProgramStudi()`, `setGaji()`, `setMataKuliahDiajar()` | `set_program_studi()`, `set_gaji()`, `set_mata_kuliah_diajar()` | Mengubah nilai atribut dosen. |

---

### 4. MataKuliah

| Atribut | Tipe Data | Keterangan |
|---------|-----------|------------|
| kodeMataKuliah / kode_mata_kuliah | String | Kode unik mata kuliah |
| namaMataKuliah / nama_mata_kuliah | String | Nama mata kuliah |
| sks | int | Jumlah SKS |

| Method | C++ / Java | Python | Keterangan |
|--------|-----------|--------|------------|
| Menampilkan data | `display()` | `display()` | Menampilkan kode, nama, dan SKS dalam satu baris; Python mengembalikan teks. |
| Getter | `getKodeMataKuliah()`, `getNamaMataKuliah()`, `getSks()` | `get_kode_mata_kuliah()`, `get_nama_mata_kuliah()`, `get_sks()` | Mengambil nilai atribut mata kuliah. |
| Setter | `setKodeMataKuliah()`, `setNamaMataKuliah()`, `setSks()` | `set_kode_mata_kuliah()`, `set_nama_mata_kuliah()`, `set_sks()` | Mengubah nilai atribut mata kuliah. |

---

### 5. ProgramStudi (Composition)

| Atribut | Tipe Data | Keterangan |
|---------|-----------|------------|
| idProgramStudi / id_program_studi | String | ID unik program studi |
| nama | String | Nama program studi, misalnya Ilmu Komputer, PKO, atau Matematika |
| jenjang | String | Jenjang pendidikan program studi, misalnya S1 |
| mataKuliah / mata_kuliah | List/Vector<MataKuliah> | Daftar objek mata kuliah milik program studi (composition) |

| Method | C++ / Java | Python | Keterangan |
|--------|-----------|--------|------------|
| Menambah mata kuliah | `tambahMataKuliah(mk)` | `tambah_mata_kuliah(mk)` | Menambahkan objek MataKuliah ke dalam program studi. |
| Getter | `getIdProgramStudi()`, `getNama()`, `getJenjang()`, `getMataKuliah()` | `get_id_program_studi()`, `get_nama()`, `get_jenjang()`, `get_mata_kuliah()` | Mengambil data program studi dan daftar mata kuliah. |
| Setter | `setIdProgramStudi()`, `setNama()`, `setJenjang()` | `set_id_program_studi()`, `set_nama()`, `set_jenjang()` | Mengubah ID, nama, dan jenjang program studi. |

---

### 6. Fakultas (Composition)

| Atribut | Tipe Data | Keterangan |
|---------|-----------|------------|
| idFakultas | String | ID unik fakultas |
| nama | String | Nama fakultas |
| programStudi / program_studi | List/Vector<ProgramStudi> | Daftar objek program studi milik fakultas (composition) |

| Method | C++ / Java | Python | Keterangan |
|--------|-----------|--------|------------|
| Menambah program studi | `tambahProgramStudi(prodi)` | `tambah_program_studi(prodi)` | Menambahkan prodi baru atau mengganti data prodi ber-ID sama. |
| Menyusun tampilan | `render(nomor)` | `display(nomor_fakultas=1)` | Membentuk tampilan Fakultas beserta prodi dan mata kuliahnya; C++/Java juga menyediakan `display()` untuk mencetaknya. |
| Getter | `getIdFakultas()`, `getNama()`, `getProgramStudi()` | `get_id_fakultas()`, `get_nama()`, `get_program_studi()` | Mengambil data Fakultas dan daftar program studi. |
| Setter | `setIdFakultas()`, `setNama()` | `set_id_fakultas()`, `set_nama()` | Mengubah ID dan nama Fakultas. |

---

## Penjelasan Alur Program

Alur program untuk ketiga bahasa (C++, Python, Java):

1. **Inisialisasi Data Awal**
   - Membuat FPMIPA (`F001`) dan FPOK (`F002`), lalu memasukkan Ilmu Komputer (`PS001`), Matematika (`PS002`), dan PKO (`PS003`) ke fakultas masing-masing.
   - Membuat ILK101 Dasar Pemrograman (3 SKS), MTK101 Statistika Dasar (3 SKS), MTK201 Kalkulus I (4 SKS), dan PJK101 Pendidikan Jasmani (3 SKS).
   - Membuat tiga Dosen (`D001`–`D003`) dan dua Mahasiswa (`M001`–`M002`) dengan data serta kode mata kuliah seperti pada program.

2. **Display Data Sebelum Penambahan**
   - Menampilkan Fakultas beserta ProgramStudi dan MataKuliah yang dimiliki.
   - Menampilkan daftar Dosen dan Mahasiswa.

3. **Penambahan Data Baru**
   - Menambahkan Fakultas F003 (FIP) dan Program Studi PS004 (Pendidikan Guru SD, S1).
   - Menambahkan PGSD101 (Landasan Pendidikan, 4 SKS) dan PGSD201 (Bimbingan Konseling, 3 SKS) ke PS004.
   - Menambahkan MTK301 (Kalkulus II, 3 SKS) ke Matematika (`PS002`).
   - Membuat Dosen D004 (Bu Dini), yang mengampu PGSD101 dan PGSD201; Pak Budi juga ditambahkan sebagai pengampu MTK301.
   - Membuat Mahasiswa M003 (Repan), yang mengambil PGSD101 dan PGSD201.
   - Saat penambahan, program mencetak ringkasan berlabel “Fakultas baru”, “Program studi baru”, “Mata kuliah baru”, “Dosen baru”, dan “Mahasiswa baru”; ringkasan tersebut bukan pesan status `[BERHASIL]`.

4. **Display Data Sesudah Penambahan**
   - Menampilkan Fakultas beserta ProgramStudi dan MataKuliah yang telah diperbarui.
   - Menampilkan seluruh Dosen dan Mahasiswa.

---

## 📷 Dokumentasi

### Contoh keluaran CPP(C++), Java dan Python


**Data Awal:**

![Data Awal1](Python/Dokumentasi/Data%20Awal1.png)
![Data Awal2](Python/Dokumentasi/Data%20Awal2.png)

**Tambah Data**

![Tambah Data](Python/Dokumentasi/Tambah%20Data.png)

**Data Baru**

![Data Baru1](Python/Dokumentasi/Data%20Baru1.png)
![Data Baru1](Python/Dokumentasi/Data%20Baru1.png)
![Data Baru1](Python/Dokumentasi/Data%20Baru1.png)

*Catatan: Dokumentasi tangkapan layar untuk masing-masing bahasa tersedia di folder [C++](CPP/Dokumentasi/), [Java](Java/Dokumentasi/), dan [Python](Python/Dokumentasi/).*


## 📁 Struktur Folder

```
TP3DPBO2526C2/
├── README.md
├── CPP/
│   ├── Dokumentasi/
│   │   ├── Data Awal1.png
│   │   ├── Data Awal2.png
│   │   ├── Data Baru1.png
│   │   ├── Data Baru2.png
│   │   ├── Data Baru3.png
│   │   └── Tambah Data.png
│   └── Program/
│       ├── main.cpp
│       ├── Manusia.cpp
│       ├── Mahasiswa.cpp
│       ├── Dosen.cpp
│       ├── MataKuliah.cpp
│       ├── ProgramStudi.cpp
│       └── Fakultas.cpp
├── Java/
│   ├── Dokumentasi/
│   │   ├── Data Awal1.png
│   │   ├── Data Awal2.png
│   │   ├── Data Baru1.png
│   │   ├── Data Baru2.png
│   │   ├── Data Baru3.png
│   │   └── Tambah Data.png
│   └── Program/
│       ├── Main.java
│       ├── Manusia.java
│       ├── Mahasiswa.java
│       ├── Dosen.java
│       ├── MataKuliah.java
│       ├── ProgramStudi.java
│       └── Fakultas.java
└── Python/
    ├── Dokumentasi/
    │   ├── Data Awal1.png
    │   ├── Data Awal2.png
    │   ├── Data Baru1.png
    │   ├── Data Baru2.png
    │   ├── Data Baru3.png
    │   └── Tambah Data.png
    └── Program/
        ├── main.py
        ├── Manusia.py
        ├── Mahasiswa.py
        ├── Dosen.py
        ├── MataKuliah.py
        ├── ProgramStudi.py
        └── Fakultas.py
```

---

## Kesimpulan

Program University Management System ini menerapkan konsep OOP dalam tiga bahasa pemrograman:

- **Data statis:** data awal dan data tambahan sudah ditentukan di dalam kode program; data tidak dimasukkan oleh pengguna atau disimpan dalam database.
- **Hierarchical inheritance:** `Mahasiswa` dan `Dosen` mewarisi atribut dasar dari `Manusia`.
- **Composition:** `Fakultas` memiliki `ProgramStudi`, dan setiap `ProgramStudi` memiliki `MataKuliah`.
- **Array of Objects:** kumpulan objek `ProgramStudi` disimpan pada `Fakultas`, sementara kumpulan objek `MataKuliah` disimpan pada `ProgramStudi`.
- **Daftar kode mata kuliah:** `Dosen` dan `Mahasiswa` menyimpan kode mata kuliah yang diajar atau diambil.
- **Pengelolaan data:** penambahan program studi, mata kuliah, serta kode mata kuliah untuk dosen dan mahasiswa sudah ditentukan dalam alur program.
- **Tampilan data:** data awal dan data setelah penambahan ditampilkan dalam format yang terstruktur.
