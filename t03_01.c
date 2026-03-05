#include <stdio.h> // Diperlukan untuk fungsi input/output seperti scanf dan printf

int main() {
    int n;          // Variabel untuk menyimpan jumlah baris masukkan (n)
    long long sum = 0; // Variabel untuk menyimpan total jumlah nilai, menggunakan long long untuk mengakomodasi jumlah besar
    int score;      // Variabel untuk menyimpan setiap nilai tugas mahasiswa
    double average; // Variabel untuk menyimpan nilai rata-rata

    // Membaca bilangan bulat positif pertama yang merepresentasikan jumlah baris masukkan n
    scanf("%d", &n);

    // Melakukan iterasi sebanyak n kali untuk membaca setiap nilai tugas
    for (int i = 0; i < n; i++) {
        scanf("%d", &score); // Membaca nilai tugas
        sum += score;        // Menambahkan nilai tugas ke total sum
    }

    // Menghitung nilai rata-rata
    // Pastikan n tidak nol untuk menghindari pembagian dengan nol
    if (n > 0) {
        average = (double)sum / n; // Melakukan casting sum ke double untuk memastikan hasil pembagian adalah floating-point
    } else {
        average = 0.0; // Jika n adalah 0, rata-rata juga 0 (atau bisa disesuaikan sesuai kebutuhan penanganan error)
    }

    // Mencetak total jumlah nilai
    printf("%lld\n", sum);

    // Mencetak nilai rata-rata dengan presisi 2 digit di belakang koma
    printf("%.2f\n", average);

    return 0; // Mengindikasikan bahwa program berjalan dengan sukses
}
