#include <stdio.h>
#include <stdlib.h>

//array
struct anak{
    char nama[100];
    int usia;
    float tinggi, berat;
};

// fungsi
float MenghitungRataRata(struct anak ank) {
    return ank.berat / (ank.tinggi * ank.tinggi);
}

//prosedur
void tampilkanAnak(struct anak ank[], int totalAnak) {
    printf("================================================\n");
    printf("            DATA BALITA DAN HASIL GIZI          \n");
    printf("================================================\n");
    printf("%-20s %-10s %-10s %-10s %-10s\n", "Nama Anak", "Usia", "Tinggi", "Berat", "Rata-Rata Gizi");

    //perulangan
    for (int i = 0; i < totalAnak; i++) {
        float rataRataGizi = MenghitungRataRata(ank[i]);
        printf("%-20s %-10d %-10.2f %-10.2f %-10.2f\n", ank[i].nama, ank[i].usia, ank[i].tinggi, ank[i].berat, rataRataGizi);
    }

//    system("cls");
//    printf("\nlebih 5\n");
//    printf("%-20s %-10s %-10s %-10s %-10s\n", "Nama Anak", "Usia", "Tinggi", "Berat", "Rata-Rata Gizi");
//    for (int i = 0; i < totalAnak; i++) {
//        float rataRataGizi = MenghitungRataRata(ank[i]);
//
//        if(ank[i].usia > 5 ){
//            printf("%-20s %-10d %-10.2f %-10.2f %-10.2f\n", ank[i].nama, ank[i].usia, ank[i].tinggi, ank[i].berat, rataRataGizi);
//        }
//    }

    //menampilkan data yang usia anaknya diatas 5 dan gizinya diatas 10
    system("pause");
}

// prosedur dan sorting
void urutkan(struct anak ank[], int totalAnak) {
    struct anak temp;

    for (int i = 0; i < totalAnak - 1; i++) {
        for (int j = 0; j < totalAnak - i - 1; j++) {
            if (MenghitungRataRata(ank[j]) < MenghitungRataRata(ank[j + 1])) {
                temp = ank[j];
                ank[j] = ank[j + 1];
                ank[j + 1] = temp;
            }
        }
    }
    // Menampilkan data setelah diurutkan
    printf("================================================\n");
    printf("     DATA SETELAH DIURUTKAN BERDASARKAN GIZI    \n");
    printf("================================================\n");
    printf("%-20s %-10s %-10s %-10s %-10s\n", "Nama Anak", "Usia", "Tinggi", "Berat", "Rata-Rata Gizi");
    for (int i = 0; i < totalAnak; i++) {
        float rataRataGizi = MenghitungRataRata(ank[i]);
        printf("%-20s %-10d %-10.2f %-10.2f %-10.2f\n", ank[i].nama, ank[i].usia, ank[i].tinggi, ank[i].berat, rataRataGizi);
    }
    system("pause");
}

// Prosedur untuk mencari anak berdasarkan nama
void cariAnak(struct anak ank[], int totalAnak) {
    int found = 0;

    char cariNama[100];
//    printf("\nApakah Anda ingin mencari data anak berdasarkan nama? (y/n): ");
//    scanf(" %c", &pilihan);
//
//    if (pilihan == 'y' || pilihan == 'Y') {
    printf("\n==============================\n");
    printf("          PENCARIAN             \n");
    printf("================================\n");
    printf("Masukkan nama anak yang ingin dicari: ");
    scanf("%s", cariNama);
//        cariAnak(ank, totalAnak, cariNama);

    system("cls");
    printf("\n================================================\n");
    printf("          HASIL PENCARIAN DATA ANAK             \n");
    printf("================================================\n");
    printf("%-20s %-10s %-10s %-10s %-10s\n", "Nama Anak", "Usia", "Tinggi", "Berat", "Rata-Rata Gizi");

    // Perulangan untuk mencari anak berdasarkan nama
    for (int i = 0; i < totalAnak; i++) {
        if (strcmp(ank[i].nama, cariNama) == 0) {
            found = 1;
            float rataRataGizi = MenghitungRataRata(ank[i]);
            printf("%-20s %-10d %-10.2f %-10.2f %-10.2f\n", ank[i].nama, ank[i].usia, ank[i].tinggi, ank[i].berat, rataRataGizi);
            break; // Keluar dari loop setelah menemukan anak
        }
    }

    if (!found) {
        printf("Data anak dengan nama '%s' tidak ditemukan.\n", cariNama);
    }
    system("pause");
}

void simpanDataKeFile(struct anak ank[], int totalAnak) {
    FILE *file = fopen("D:\\TUBES\\data_anak.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < totalAnak; i++) {
        fprintf(file, "%s %d %.2f %.2f\n", ank[i].nama, ank[i].usia, ank[i].tinggi, ank[i].berat);
    }

    fclose(file);
}

void bacaDataDariFile(struct anak ank[], int *totalAnak) {
    FILE *file = fopen("D:\\TUBES\\data_anak.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %d %f %f", ank[*totalAnak].nama, &ank[*totalAnak].usia, &ank[*totalAnak].tinggi, &ank[*totalAnak].berat) == 4) {
        (*totalAnak)++;
    }

    fclose(file);
}

void tambahData(struct anak ank[], int *totalAnak){
    printf("==================================\n");
    printf("            TAMBAH DATA           \n");
    printf("==================================\n");
    char tambahLagi = 'y';
    //perulangan
    while (tambahLagi == 'y' || tambahLagi == 'Y') {
        printf("Masukkan Nama Anak      : ");
        scanf("%s", &ank[*totalAnak].nama);

        printf("Masukkan Usia Anak      : ");
        scanf("%d", &ank[*totalAnak].usia);

        printf("Masukkan Tinggi Anak(m) : ");
        scanf("%f", &ank[*totalAnak].tinggi);

        printf("Masukkan Berat Anak(kg) : ");
        scanf("%f", &ank[*totalAnak].berat);

        *totalAnak = *totalAnak + 1; // Menambah total anak yang sudah dimasukkan

        printf("Tambahkan Data Anak Lain? (y/n) : ");
        getchar(); // Mengonsumsi karakter newline
        scanf("%c", &tambahLagi);
    }
}

int main() {
    struct anak ank[100];
    int totalAnak = 0;
    int pilih;

//  char tambahLagi = 'y';
    do{
        system("cls");
        printf("================================================\n");
        printf("            SELAMAT DATANG DI POSYANDU          \n");
        printf("================================================\n");
        printf("\n1. Tambah Data Anak");
        printf("\n2. Lihat Data Anak");
        printf("\n3. Cari Data Anak");
        printf("\n4. Sorting Data Anak");
        printf("\n5. Keluar");
        printf("\nPilih Menu : ");
        scanf("%i", &pilih);

        if (pilih == 1){
            system("cls");
            tambahData(ank, &totalAnak);
        } else if (pilih == 2){
            system("cls");
            bacaDataDariFile(ank, &totalAnak);
            tampilkanAnak(ank,totalAnak);
        } else if (pilih == 3){
            system("cls");
            cariAnak(ank, totalAnak);
        } else if (pilih == 4){
            system("cls");
            urutkan(ank, totalAnak);
        }else if (pilih == 5){
            printf("\nTerimakasih ^^.");
            simpanDataKeFile(ank, totalAnak);
        }
    } while (pilih != 5);
    return 0;
}
