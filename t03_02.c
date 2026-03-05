#include <stdio.h>  // Diperlukan untuk fungsi input/output seperti scanf dan printf
#include <stdlib.h> // Diperlukan untuk fungsi malloc dan free

int main() {
    int n;          // Variabel untuk menyimpan jumlah baris masukkan (n)
    long long sum = 0; // Variabel untuk menyimpan total jumlah nilai, menggunakan long long untuk mengakomodasi jumlah besar
    double average; // Variabel untuk menyimpan nilai rata-rata
    int *scores;    // Pointer untuk menyimpan array nilai tugas mahasiswa
    int count_above_average = 0; // Variabel untuk menyimpan banyaknya mahasiswa yang nilainya di atas atau sama dengan rata-rata

    // Membaca bilangan bulat positif pertama yang merepresentasikan jumlah baris masukkan n
    scanf("%d", &n);

    // Alokasi memori secara dinamis untuk menyimpan n nilai
    // Menggunakan calloc untuk menginisialisasi memori dengan nol, meskipun tidak mutlak diperlukan di sini
    scores = (int *)malloc(n * sizeof(int));

    // Periksa apakah alokasi memori berhasil
    if (scores == NULL) {
        // Penanganan error jika alokasi memori gagal
        return 1; // Keluar dengan kode error
    }

    // Melakukan iterasi sebanyak n kali untuk membaca setiap nilai tugas dan menyimpannya
    for (int i = 0; i < n; i++) {
        scanf("%d", &scores[i]); // Membaca nilai tugas dan menyimpannya di array
        sum += scores[i];        // Menambahkan nilai tugas ke total sum
    }

    // Menghitung nilai rata-rata
    // Pastikan n tidak nol untuk menghindari pembagian dengan nol
    if (n > 0) {
        average = (double)sum / n; // Melakukan casting sum ke double untuk memastikan hasil pembagian adalah floating-point
    } else {
        average = 0.0; // Jika n adalah 0, rata-rata juga 0
    }

    // Melakukan iterasi lagi untuk menghitung banyaknya mahasiswa yang nilainya di atas atau sama dengan rata-rata
    for (int i = 0; i < n; i++) {
        if (scores[i] >= average) {
            count_above_average++;
        }
    }

    // Mencetak total jumlah nilai
    printf("%lld\n", sum);

    // Mencetak nilai rata-rata dengan presisi 2 digit di belakang koma
    printf("%.2f\n", average);

    // Mencetak banyaknya mahasiswa yang nilainya di atas atau sama dengan rata-rata
    printf("%d\n", count_above_average);

    // Bebaskan memori yang dialokasikan secara dinamis
    free(scores);
    scores = NULL; // Hindari dangling pointer

    return 0; // Mengindikasikan bahwa program berjalan dengan sukses
}
