Proyek Sistem Rumah Sakit atau disebut Soal TUBES No. 20 Data Pasien ini merupakan implementasi struktur data Multi Linked List dengan jenis relasi Many-to-Many. Sistem ini digunakan untuk mencatat berbagai jenis penyakit serta pasien yang memiliki keterkaitan dengan satu atau lebih penyakit tersebut.
Dalam implementasinya, satu pasien dapat memiliki lebih dari satu penyakit, dan satu penyakit juga dapat dimiliki oleh banyak pasien. Oleh karena itu, struktur many-to-many dipilih agar relasi data dapat dikelola secara fleksibel dan efisien.
Selain pengelolaan data, sistem ini juga menyediakan fitur analisis penyakit, seperti menampilkan penyakit dengan jumlah pasien terbanyak. Fitur ini bertujuan untuk membantu pihak Rumah Sakit atau dokter dalam menentukan prioritas penanganan berdasarkan tingkat prevalensi penyakit pada sistem.
Struktur data yang digunakan bukanlah Double Linked List, karena tidak menyediakan akses kembali ke node sebelumnya. Sebagai gantinya, digunakan Multi Linked List dengan pemisahan struktur parent dan child, di mana:
-Penyakit berperan sebagai parent
-Pasien berperan sebagai child
-Relasi disimpan dalam node tersendiri

Penggunaan dua struktur yang terpisah ini bertujuan agar data lebih terorganisir, mudah dipahami, dan mudah ditelusuri oleh pengguna. Dengan pendekatan ini, setiap entitas dapat dikelola secara mandiri tanpa saling bergantung secara langsung.
Proyek ini dikembangkan sebagai bentuk penerapan materi pada Mata Kuliah Struktur Data Semester III, dengan fokus utama pada penggunaan pointer, linked list, serta relasi data yang terstruktur dan terorganisir.
Tujuan Program:
-Mengelola data pasien dan penyakit secara terpisah agar lebih terorganisir dan mudah digunakan
-Mengimplementasikan berbagai operasi struktur data seperti insert, delete, search, dan traversal
-Merealisasikan relasi Many-to-Many antara pasien dan penyakit secara dua arah
-Menerapkan konsep pointer dan linked list dalam kasus nyata sistem Rumah Sakit
-Memberikan gambaran analisis penyakit untuk mendukung pengambilan keputusan
