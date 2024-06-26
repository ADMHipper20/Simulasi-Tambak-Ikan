#include <stdio.h>
#include "Opsi.h"
#include "Panen.h"

int main(){
    time_t rawtime;
    struct tm *timeInfo;

    time(&rawtime);
    timeInfo = localtime(&rawtime);

    int hari = timeInfo->tm_wday, jam = timeInfo->tm_hour, menit = timeInfo->tm_min, tanggal = timeInfo->tm_mday, bulan = timeInfo->tm_mon, tahun = timeInfo->tm_year+1900;
    char *day[] = {"Senin", "Selasa", "Rabu", "Kamis", "Jum'at", "Sabtu", "Minggu"};
    char *month[] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni",
        "Juli", "Agustus", "September", "Oktober", "November", "Desember"
    };

    if (jam >= 0 && jam < 12) printf("Selamat Pagi!\n"); 
    else if (jam >= 12 && jam < 14) printf("Selamat Siang!\n"); 
    else printf("Selamat Sore!\n");

    printf("\nHari: %s\nTanggal: %02d, %s %d %02d:%02d\n\n", day[hari], tanggal, month[bulan], tahun, jam, menit);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("        AquaTech v0.1        \n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n");
    
    int option, nomorKolam;
    float beratIkan[2][10];
    int tambakIkan[2][10], totalIkan[2] = {0};
    char jenisIkan[2][20];

    do{
        printf("Automasi Tambak Ikan AquaTech v0.1\n");
        printf("1. Beri makan ikan\n");
        printf("2. Periksa suhu air\n");
        printf("3. Periksa tingkat oksigen\n");
        printf("4. Bersihkan tambak\n");
        printf("5. Tambah ikan ke dalam tambak\n");
        printf("6. Data ikan di tambak\n");
        printf("7. Panen!\n");
        printf("0. Keluar\n");
        printf("Masukkan Pilihan Anda:\n");
        scanf("%d", &option);

        switch (option){
            case 1:
                feedFish(); // selesai
                break;
            case 2:
                checkTemperature(); // selesai
                break;
            case 3:
                checkOxygen_stabilizeOxygenLevels(); // selesai
                break;
            case 4:
                cleanFishPond();
                break;
            case 5:
                printf("Pilih kolam yang ingin diisi: ");
                scanf("%d", &nomorKolam);
                
                printf("Jenis ikan: ");
                scanf("%s", jenisIkan[nomorKolam - 1]);

                totalIkan[nomorKolam - 1] = addFish(tambakIkan, nomorKolam, totalIkan, jenisIkan, beratIkan);
                break;
            case 6:
                dataIkan(tambakIkan, totalIkan, jenisIkan, beratIkan);
                break;
            case 7:
                searchByWeight(beratIkan, totalIkan, nomorKolam);
                break;
            case 0:
                printf("Keluar...\n");
                break;
            default:
                printf("Pilihan tidak valid. Harap masukkan pilihan yang benar.\n");
        }
    } while (option != 0);
}