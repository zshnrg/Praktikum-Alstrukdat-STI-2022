# Arsip Praktikum Alstrukdat STI IF2111 2022
Repository ini berisi soal-soal dan pembahasan praktikum mata kuliah Alstrukdat. File-file ini hanya boleh dijadikan referensi pembelajaran. Dilarang menduplikasi file untuk menjawab soal-soal praktikum.

## Referensi pembelajaran
- Diktat Pemrograman Paradigma Prosedural
- Diktat Struktur Data
- Diktat Catatan Singkat Bahasa C
- Diktat Program Kecil Bahasa C

Kalau kamu kebingungan mengenai cara kerja pointer, berikut ini video penjelasan mengenai pointer yang cukup ringkas.
https://www.youtube.com/watch?v=2ybLD6_2gKM

** POV Program Main **

Singkatnya pointer merupakan sebuah variabel yang menunjuk sebuah nilai. Jika sebuah fungsi mengharuskan parameternya sebuah pointer (ex: int *x) maka kamu harus mengirimkan address (ex: &x) dari sebuah variabel ke dalam fungsi tersebut.

** POV Program di Dalam Fungsi/Prosedur **

Jika fungsi/prosedur yang kamu gunakan sudah memiliki parameter berupa pointer, kamu bisa mengubah nilai dari pointer tersebut dengan menambahkan bintang (*) di depannya. Jika ingin menggunakan fungsi/prosedur lain di dalamnya yang menggunakan parameter pointer juga, kamu tidak perlu menambahkan bintang.

Mudahnya seperti itu :D

## Cara compile program C
Untuk compile program c, gunakan command di bawah ini (bisa digunakan untuk menggabungkan beberapa file body dari header adt yang digunakan)
```ps
gcc -o nama_executable main_program.c body_header1.c body_header2.c body_headerx.c
```
Nama file target executable jangan sampe lupa karna bisa bisa entar main program c nya ilang 😭.
Untuk run programmnya bisa double click hasil executable atau ketik `./nama_executable` di terminal

## Also pointer in a nutshell
<br>
<img src="https://preview.redd.it/kh726uczjnq71.png?auto=webp&s=7d5f0ab136a52bd319a99edf1ef54a6dd244c940">
<br>
