#include "Opsi.h"

int feedFish(){
    double maxFeedLimit = 100.0; // Mengatur maksimum limit pakan dalam gram
    double totalFeed = 0.0;
    double feedAmount;

    if (totalFeed >= maxFeedLimit){
        printf("%.2f\n", totalFeed);
        printf("Batasan maksimum telah tercapai (%.2f grams). Stop feeding.\n\n", maxFeedLimit);
    } else {
        printf("Masukkan Jumlah Pakan per Gram(gr): ");
        scanf("%lf", &feedAmount);

        totalFeed += feedAmount;
        if((totalFeed + feedAmount) <= maxFeedLimit) {
            printf("Feeding %.2f grams of fish feed...\n", feedAmount);
            Sleep(100);
            printf("Fish have been fed.\n\n");
        } else {
            printf("Exceeded maximum feed limit (%.2f grams). Cannot feed this amount (%.2f grams).\n\n", maxFeedLimit, totalFeed);
        }
    }
    return totalFeed;
}

void checkTemperature() {
    printf("Memeriksa Suhu Air...\n");
    float waterTemperature = rand(); // Baca suhu dalam derajat Celsius

    // Menampilkan suhu air pada Serial Monitor
    printf("Suhu air: %.1f °C\n", waterTemperature);

    // Logika sederhana untuk menangani suhu
    if (waterTemperature < 10.0) {
        printf("Temperature is too low. Taking corrective action...\n\n");
        // Implementasikan langka koreksi untuk temperatur rendah (Jika dibutuhkan)
    } else if (waterTemperature > 30.0) {
        printf("Temperature is too high. Taking corrective action...\n\n");
        // Implementasikan langka koreksi untuk temperatur tinggi (Jika dibutuhkan)
    } else {
        printf("Temperature is within acceptable range.\n\n");
    }
}

void checkOxygen_stabilizeOxygenLevels() {
    int oxygenLevel = 60;

    // Contoh logika sederhana untuk tindakan berdasarkan tingkat oksigen
    if (oxygenLevel < 30) {
        printf("Tingkat oksigen rendah! Memulai aerasi...\n\n");
        // Implementasikan tindakan untuk memperbaiki tingkat oksigen, misalnya dengan menambahkan aerasi dengan tumbuhan terapung
        // Atau Menyalakan mesin Aerator khusus tambak Ikan untuk membuat gelembung oksigen buatan
        printf("Menyalakan Aerator...\n");
    } else {
        printf("Tingkat oksigen dalam kisaran yang dapat diterima.\n\n");
    }
    Sleep(100);
}

void cleanFishPond() {
    // Baca nilai pH dari sensor
    float pHValue = 7;
    
    // Lakukan konversi nilai analog ke nilai pH yang tepat berdasarkan karakteristik sensor
    // Contoh: pH = map(pHValue, nilaiMinSensor, nilaiMaxSensor, pHMin, pHMax);

        // Lakukan tindakan berdasarkan nilai pH
    if (pHValue < 6.0) {
        printf("pH air terlalu rendah. Melakukan penyesuaian pH...\n");
        // Lakukan penyesuaian untuk meningkatkan pH jika terlalu rendah, misalnya dengan penambahan larutan basa.
        // Misalnya:
        // tambahkan sedikit larutan soda kue (natrium bikarbonat) untuk menaikkan pH air.
        // proses penambahan larutan bisa dilakukan dengan fungsi tambahan.

        // printf("Penyesuaian pH selesai. pH air sekarang: %.2f\n", adjustedPHValue);
    } else if (pHValue > 8.0) {
        printf("pH air terlalu tinggi. Melakukan penyesuaian pH...\n");
        // Lakukan penyesuaian untuk menurunkan pH jika terlalu tinggi, misalnya dengan penambahan larutan asam.
        // Misalnya:
        // tambahkan sedikit larutan asam (seperti asam sulfat encer) untuk menurunkan pH air.
        // proses penambahan larutan bisa dilakukan dengan fungsi tambahan.

        // printf("Penyesuaian pH selesai. pH air sekarang: %.2f\n", adjustedPHValue);
    } else {
        printf("pH air sudah berada dalam kisaran normal.\n");
    }
    Sleep(100);
}

float generateFishWeight() {
    return (float)(rand() % 801) / 100; // Menghasilkan bobot antara 0 hingga 8
}

int addFish(int tambakIkan[][10], int nomorKolam, int totalIkan[], char jenisIkan[][10][20], float beratIkan[][10]) {
    srand(time(NULL)); // Inisialisasi seed untuk rand() dengan waktu saat ini

    if (nomorKolam >= 1 && nomorKolam <= 2) {
        int tambahIkan;
        int ketersediaanKapasitas = 10 - totalIkan[nomorKolam - 1]; // Hitung ruang kosong yang tersedia di kolam

        printf("Berapa ikan yang akan ditambahkan? ");
        scanf("%d", &tambahIkan);

        if (totalIkan[nomorKolam - 1] + tambahIkan <= 10) {
            // Memilih kolam dan menambahkan ikan
            for (int i = 0; i < tambahIkan; i++) {
                float weight = generateFishWeight(); // Berat ikan bervariasi antara 0 hingga 8
                tambakIkan[nomorKolam - 1][totalIkan[nomorKolam - 1] + i] = weight;
                beratIkan[nomorKolam - 1][totalIkan[nomorKolam - 1] + i] = weight;
                
                printf("Masukkan jenis ikan: ");
                scanf("%s", jenisIkan[nomorKolam - 1][totalIkan[nomorKolam - 1] + i]);

                printf("%s: %.2f kilogram\n", jenisIkan[nomorKolam - 1][totalIkan[nomorKolam - 1] + i], weight);
            }
            totalIkan[nomorKolam - 1] += tambahIkan; // Perbarui total ikan di kolam yang telah ditambahkan

        } else {
            printf("Tambak %d sudah terisi penuh. Mohon untuk mengisi pada tambak yang belum penuh.\n", nomorKolam);
            return totalIkan[nomorKolam - 1]; // Kembalikan total ikan tanpa melakukan penambahan
        }
    } else {
        printf("Nomor kolam tidak valid.\n");
    }
    printf("\n");
    return totalIkan[nomorKolam - 1]; // Mengembalikan total ikan di kolam yang telah diupdate
}

void dataIkan(int tambakIkan[][10], int totalIkan[], char jenisIkan[][20], float beratIkan[][10]) {
    printf("Data Ikan di Tambak (diurutkan berdasarkan berat):\n");

    for (int k = 0; k < 2; k++) {
        int adaIkan = 0; // Variabel penanda apakah ada ikan di tambak tersebut

        float tempBerat[10];
        int count = 0;

        for (int i = 0; i < totalIkan[k]; i++) {
            if (beratIkan[k][i] > 0) {
                tempBerat[count++] = beratIkan[k][i];
                adaIkan = 1; // Ada ikan di tambak ini
            }
        }

        if (adaIkan) {
            printf("Tambak %d:\n", k + 1);
            sortBerakIkan(tempBerat, count); // Mengurutkan berat ikan di kolam

            // Mencetak hasil pengurutan
            for (int i = 0; i < count; i++) {
                printf("%s: %.2f kg\n", jenisIkan[k], tempBerat[i]);
            }
            printf("\n");
        } else {
            printf("Tambak %d kosong.\n\n", k + 1);
        }
    }
}

// Fungsi untuk mengurutkan berat ikan
void sortBerakIkan(float arr[], int n) {
    int i, j;
    float key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}