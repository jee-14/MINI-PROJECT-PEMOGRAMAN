#include <stdio.h>

// ============================================================================
// MODUL MAHASISWA 1: MENU & INPUT PESANAN (Validasi do-while)
// ============================================================================

// Menampilkan daftar makanan & minuman
void tampilkanMenu()
{
    printf("=====================================\n");
    printf("      MENU MAKANAN & MINUMAN         \n");
    printf("=====================================\n");
    printf("1. Nasi Goreng Spesial  >>>>>> 20000 \n");
    printf("2. Mie Goreng Seafood   >>>>>> 22000 \n");
    printf("3. Ayam Bakar + Nasi    >>>>>> 25000 \n");
    printf("4. Es Teh Manis         >>>>>>  5000 \n");
    printf("5. Es Jeruk Segar       >>>>>>  8000 \n");
    printf("=====================================\n");
}

// Input pilihan menu dengan validasi do-while
int inputPilihanMenu()
{
    int pilihan;
    do
    {
        tampilkanMenu();
        printf("Pilih nomor menu (1-5): ");
        scanf("%d", &pilihan);
        if (pilihan < 1 || pilihan > 5)
        {
            printf("[!] Pilihan tidak valid! Masukkan angka 1 sampai 5.\n\n");
        }
    } while (pilihan < 1 || pilihan > 5);
    return pilihan;
}

// Input jumlah pesanan dengan validasi do-while
int inputJumlahPesanan()
{
    int jumlah;
    do
    {
        printf("Masukkan jumlah porsi/gelas: ");
        scanf("%d", &jumlah);
        if (jumlah <= 0)
        {
            printf("[!] Jumlah pesanan harus lebih dari 0!\n\n");
        }
    } while (jumlah <= 0);
    return jumlah;
}

// Mendapatkan harga satuan berdasarkan pilihan menu
double getHargaItem(int pilihan)
{
    if (pilihan == 1)
        return 20000.0;
    else if (pilihan == 2)
        return 22000.0;
    else if (pilihan == 3)
        return 25000.0;
    else if (pilihan == 4)
        return 5000.0;
    else if (pilihan == 5)
        return 8000.0;
    return 0.0;
}

// ============================================================================
// MODUL MAHASISWA 2: PROSES & PERHITUNGAN (Subtotal, Diskon, Pajak)
// ============================================================================

void hitungKalkulasi(double subtotal_keseluruhan, double *diskon, double *subtotal_setelah_diskon, double *pajak, double *total_bayar)
{
    // Logika Diskon dari Mahasiswa 2
    if (subtotal_keseluruhan >= 100000.0)
    {
        *diskon = subtotal_keseluruhan * 0.10;
    }
    else
    {
        *diskon = 0.0;
    }

    *subtotal_setelah_diskon = subtotal_keseluruhan - *diskon;
    *pajak = *subtotal_setelah_diskon * 0.10;
    *total_bayar = *subtotal_setelah_diskon + *pajak;
}

// ============================================================================
// MODUL MAHASISWA 3: INPUT PEMBAYARAN, STRUK & INTEGRASI PROGRAM
// ============================================================================

// Input pembayaran dengan validasi do-while jika uang kurang
double prosesPembayaran(double total_bayar)
{
    double bayar;
    do
    {
        printf("\nTotal Tagihan yang Harus Dibayar: Rp %.2f\n", total_bayar);
        printf("Masukkan Uang Pembayaran        : Rp ");
        scanf("%lf", &bayar);

        if (bayar < total_bayar)
        {
            printf("[!] Uang kurang Rp %.2f. Silakan masukkan nominal yang cukup!\n", total_bayar - bayar);
        }
    } while (bayar < total_bayar);
    return bayar;
}

// Menampilkan Struk Pembayaran Akhir
void cetakStruk(double subtotal_keseluruhan, double diskon, double subtotal_setelah_diskon, double pajak, double total_bayar, double bayar, double kembalian)
{
    printf("\n=====================================\n");
    printf("          STRUK PEMBAYARAN           \n");
    printf("=====================================\n");
    printf("Subtotal Keseluruhan    : Rp %10.2f\n", subtotal_keseluruhan);
    printf("Diskon (10%%)            : Rp %10.2f\n", diskon);
    printf("Subtotal Setelah Diskon : Rp %10.2f\n", subtotal_setelah_diskon);
    printf("Pajak (10%%)             : Rp %10.2f\n", pajak);
    printf("-------------------------------------\n");
    printf("TOTAL BAYAR             : Rp %10.2f\n", total_bayar);
    printf("Kembalian               : Rp %10.2f\n", kembalian);
    printf("Uang Pembayaran         : Rp %10.2f\n", bayar);
    printf("=====================================\n");
    printf("   Terima Kasih atas Kunjungan Anda! \n");
    printf("=====================================\n");
}

// FUNGSI UTAMA INTEGRASI
int main()
{
    int pilihan, jumlah;
    char ulang;
    double subtotal_keseluruhan = 0;

    printf("=== SISTEM PEMESANAN MAKANAN (KELOMPOK 2) ===\n");

    // 1. Alur Mahasiswa 1: Input Pesanan Berulang (do-while)
    do
    {
        pilihan = inputPilihanMenu();
        jumlah = inputJumlahPesanan();

        double harga_item = getHargaItem(pilihan);
        subtotal_keseluruhan += (harga_item * jumlah);

        printf("\nSubtotal sementara: Rp %.2f\n", subtotal_keseluruhan);
        printf("Apakah ingin menambah pesanan lain? (y/n): ");
        scanf(" %c", &ulang);
        printf("\n");
    } while (ulang == 'y' || ulang == 'Y');

    // 2. Alur Mahasiswa 2: Perhitungan Subtotal, Diskon, & Pajak
    double diskon, subtotal_setelah_diskon, pajak, total_bayar;
    hitungKalkulasi(subtotal_keseluruhan, &diskon, &subtotal_setelah_diskon, &pajak, &total_bayar);

    // 3. Alur Mahasiswa 3: Input Uang Bayar, Kembalian & Cetak Struk
    double bayar = prosesPembayaran(total_bayar);
    double kembalian = bayar - total_bayar;

    cetakStruk(subtotal_keseluruhan, diskon, subtotal_setelah_diskon, pajak, total_bayar, bayar, kembalian);

    return 0;
}
