#include <stdio.h>
int main() 
{
   // ==========================================
    // MENU DUMMY
    // ==========================================
    printf("=============================\n");
    printf("Silahkan pilih Menu Makanan\n"); 
    printf("=============================\n");
    printf("1. Nasi Goreng Spesial >>>>>> 20000\n");
    printf("2. Mie Goreng Seafood >>>>>> 22000\n");
    printf("3. Ayam Bakar + Nasi >>>>>> 25000\n");
    printf("4. Es Teh Manis >>>>>>> 5000\n");
    printf("5. Es Jeruk Segar >>>>>>> 8000\n");
    printf("==============================\n");
  // seumpama input ngene
    printf("\nMenu yang anda pilih adalah: Ayam Bakar + Nasi dengan total 6 porsi\n");

    // simulasi harga subtotal keseluruhan
    double subtotal_keseluruhan = 150000; 

    //iki bagian ku dukur wi project dummy ne
    double diskon, subtotal_setelah_diskon, pajak, total_bayar;
    
    if (subtotal_keseluruhan >= 100000) {
        diskon = subtotal_keseluruhan * 0.10;
    } else {
        diskon = 0; 
    }

    subtotal_setelah_diskon = subtotal_keseluruhan - diskon;
    pajak = subtotal_setelah_diskon * 0.10;
    total_bayar = subtotal_setelah_diskon + pajak;

    printf("\n===============nota================\n");
    printf("Subtotal Keseluruhan: %.2f\n", subtotal_keseluruhan);
    printf("Diskon (10%%): %.2f\n", diskon);
    printf("Subtotal Setelah Diskon: %.2f\n", subtotal_setelah_diskon);
    printf("Pajak (10%%): %.2f\n", pajak);
    printf("Total Bayar: %.2f\n", total_bayar);
    printf("====================================\n");

    return 0;
}
