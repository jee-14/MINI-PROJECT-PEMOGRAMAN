#include <stdio.h>

// ========================================================
// 1. FUNGSI MENGHITUNG KEMBALIAN
// ========================================================
float hitungKembalian(float bayar, float totalBayar)
{
    return bayar - totalBayar;
}

// ========================================================
// 2. FUNGSI PROSES PEMBAYARAN (VALIDASI DO-WHILE)
// ========================================================
float prosesPembayaran(float totalBayar)
{
    float bayar;

    // Perulangan do-while: meminta input ulang jika uang pembayaran kurang
    do
    {
        printf("Masukkan Nominal Uang Pembayaran: Rp ");
        scanf("%f", &bayar);

        if (bayar < totalBayar)
        {
            printf("[!] Uang kurang Rp %.0f. Silakan masukkan nominal yang cukup!\n\n", totalBayar - bayar);
        }
    } while (bayar < totalBayar);

    return bayar;
}

// ========================================================
// 3. FUNGSI MENCETAK STRUK PEMBAYARAN
// ========================================================
void cetakStruk(float subtotal, float diskon, float pajak, float totalBayar, float bayar, float kembalian)
{
    printf("\n=========================================\n");
    printf("        STRUK PEMBAYARAN RESTORAN        \n");
    printf("=========================================\n");
    printf(" Subtotal Belanja : Rp %10.0f\n", subtotal);
    printf(" Potongan Diskon  : Rp %10.0f\n", diskon);
    printf(" Pajak (10%%)       : Rp %10.0f\n", pajak);
    printf("-----------------------------------------\n");
    printf(" TOTAL TAGIHAN    : Rp %10.0f\n", totalBayar);
    printf(" Uang Pembayaran  : Rp %10.0f\n", bayar);
    printf(" Kembalian        : Rp %10.0f\n", kembalian);
    printf("=========================================\n");
    printf("   Terima Kasih Atas Kunjungan Anda!     \n");
    printf("=========================================\n");
}

// ========================================================
// FUNGSI UTAMA (UJI COBA DENGAN DATA MOCK / TIRUAN)
// ========================================================
int main()
{
    // Data tiruan untuk mensimulasikan hasil dari Mahasiswa 1 & 2
    float subtotal = 120000.0;                      // Contoh total harga makanan
    float diskon = 12000.0;                         // Contoh diskon 10%
    float pajak = 10800.0;                          // Contoh pajak 10% dari 108rb
    float totalBayar = (subtotal - diskon) + pajak; // Total = Rp 118.800

    printf("=== TESTING MODUL PEMBAYARAN & STRUK (MAHASISWA 3) ===\n\n");
    printf("Total Tagihan Yang Harus Dibayar: Rp %.0f\n\n", totalBayar);

    // Langkah 1: Input uang pembayaran dari pengguna
    float bayar = prosesPembayaran(totalBayar);

    // Langkah 2: Hitung selisih kembalian
    float kembalian = hitungKembalian(bayar, totalBayar);

    // Langkah 3: Tampilkan struk akhir
    cetakStruk(subtotal, diskon, pajak, totalBayar, bayar, kembalian);

    return 0;
}
