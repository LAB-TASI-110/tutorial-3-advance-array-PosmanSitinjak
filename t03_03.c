#include <stdio.h>  // Diperlukan untuk fungsi input/output seperti scanf dan printf
#include <stdlib.h> // Diperlukan untuk fungsi malloc dan free
#include <limits.h> // Diperlukan untuk INT_MIN dan INT_MAX, untuk inisialisasi min/max

int main() {
    int n;          // Variabel untuk menyimpan jumlah baris masukkan (n)
    long long sum = 0; // Variabel untuk menyimpan total jumlah nilai
    double average; // Variabel untuk menyimpan nilai rata-rata
    int *scores;    // Pointer untuk menyimpan array nilai tugas mahasiswa
    int count_above_average = 0; // Variabel untuk menyimpan banyaknya mahasiswa yang nilainya di atas atau sama dengan rata-rata
    int min_score = INT_MAX; // Variabel untuk menyimpan nilai minimum, diinisialisasi dengan nilai maksimum integer
    int max_score = INT_MIN; // Variabel untuk menyimpan nilai maksimum, diinisialisasi dengan nilai minimum integer
    int range;      // Variabel untuk menyimpan rentang nilai

    // Membaca bilangan bulat positif pertama yang merepresentasikan jumlah baris masukkan n
    scanf("%d", &n);

    // Alokasi memori secara dinamis untuk menyimpan n nilai
    scores = (int *)malloc(n * sizeof(int));

    // Periksa apakah alokasi memori berhasil
    if (scores == NULL) {
        // Penanganan error jika alokasi memori gagal
        fprintf(stderr, "Memori gagal dialokasikan.\n");
        return 1; // Keluar dengan kode error
    }

    // Melakukan iterasi sebanyak n kali untuk membaca setiap nilai tugas, menyimpannya, dan menghitung sum, min, dan max
    for (int i = 0; i < n; i++) {
        scanf("%d", &scores[i]); // Membaca nilai tugas dan menyimpannya di array
        sum += scores[i];        // Menambahkan nilai tugas ke total sum

        // Memperbarui nilai minimum dan maksimum
        if (scores[i] < min_score) {
            min_score = scores[i];
        }
        if (scores[i] > max_score) {
            max_score = scores[i];
        }
    }

    // Menghitung nilai rata-rata
    // Pastikan n tidak nol untuk menghindari pembagian dengan nol
    if (n > 0) {
        average = (double)sum / n; // Melakukan casting sum ke double untuk memastikan hasil pembagian adalah floating-point
    } else {
        average = 0.0; // Jika n adalah 0, rata-rata juga 0
        min_score = 0; // Jika tidak ada nilai, rentang bisa dianggap 0 (atau definisi lain)
        max_score = 0;
    }

    // Melakukan iterasi lagi untuk menghitung banyaknya mahasiswa yang nilainya di atas atau sama dengan rata-rata
    for (int i = 0; i < n; i++) {
        if (scores[i] >= average) {
            count_above_average++;
        }
    }

    // Menghitung rentang nilai
    range = max_score - min_score;

    // Mencetak total jumlah nilai
    printf("%lld\n", sum);

    // Mencetak nilai rata-rata dengan presisi 2 digit di belakang koma
    printf("%.2f\n", average);

    // Mencetak banyaknya mahasiswa yang nilainya di atas atau sama dengan rata-rata
    printf("%d\n", count_above_average);

    // Mencetak rentang nilai (maksimum - minimum)
    printf("%d\n", range);

    // Bebaskan memori yang dialokasikan secara dinamis
    free(scores);
    scores = NULL; // Hindari dangling pointer

    return 0; // Mengindikasikan bahwa program berjalan dengan sukses
}
