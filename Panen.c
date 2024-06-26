#include "Panen.h"

void searchByWeight(float beratIkan[][10], int totalIkan[], int nomorKolam) {
    float weightToSearch;

    printf("Masukkan nomor kolam: ");
    scanf("%d", &nomorKolam);
    printf("Masukkan berat ikan: ");
    scanf("%f", &weightToSearch);
    printf("Hasil Pencarian Ikan dengan Berat %.2f kg di Tambak %d:\n", weightToSearch, nomorKolam);

    int found = 0;

    for (int i = 0; i < totalIkan[nomorKolam - 1]; i++) {
        if (beratIkan[nomorKolam - 1][i] == weightToSearch) {
            printf("Ikan dengan berat %.2f kg ditemukan pada indeks ke-%d di Tambak %d.\n", weightToSearch, i, nomorKolam);
            found = 1;
        }
    }

    if (!found) {
        printf("Ikan dengan berat %.2f kg tidak ditemukan di Tambak %d.\n", weightToSearch, nomorKolam);
    }
}