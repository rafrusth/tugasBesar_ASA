/* 
 *  Pembuat   : Rafif Setya Imaduddin (24060124130115)
 */

#include "../Header/include/PCType.h"
#include "../Header/include/BruteForce.h"

int main() {
    // Kamus
    /// Koleksi
    ListCPU lc1;
    ListMotherboard lm1;
    ListRAM lr1;
    ListPSU lp1;
    ListGPU lg1;
    ListStorage ls1;
    LListPC llpc1;

    /// Objek
    CPU cpu1;
    CPU cpu2;
    CPU cpu3;
    CPU cpu4;
    CPU cpu5;

    Motherboard mb1;
    Motherboard mb2;
    Motherboard mb3;
    Motherboard mb4;
    Motherboard mb5;

    RAM rm1;
    RAM rm2;
    RAM rm3;
    RAM rm4;
    RAM rm5;

    PSU ps1;
    PSU ps2;
    PSU ps3;
    PSU ps4;
    PSU ps5;

    GPU gp1;
    GPU gp2;
    GPU gp3;
    GPU gp4;
    GPU gp5;

    Storage sg1;
    Storage sg2;
    Storage sg3;
    Storage sg4;
    Storage sg5;

    // Size
    int size;

    // Algoritma
    /// Make
    makeCPU(&cpu1, "AMD Ryzen 7 9800X3D", "AM5", 120);
    makeCPU(&cpu2, "AMD Ryzen 5 8600G", "AM5", 65);
    makeCPU(&cpu3, "Intel Core i9-14900K", "LGA1700", 150);
    makeCPU(&cpu4, "Intel Core i9-10850K", "LGA1200", 125);
    makeCPU(&cpu5, "Intel Core i7-13700T", "LGA1700", 125);

    makeMotherboard(&mb1, "Asus TUF GAMING B650-PLUS WIFI", "AM5", 5, "M.2");
    makeMotherboard(&mb2, "ASRock Phantom Gaming X870E Nova WiFi", "AM5", 5, "M.2");
    makeMotherboard(&mb3, "Asus PRIME Z790-A WIFI", "LGA1700", 5, "SATA");
    makeMotherboard(&mb4, "Gigabyte H510M H", "LGA1200", 4, "M.2");
    makeMotherboard(&mb5, "MSI MAG B560 TOMAHAWK WIFI", "LGA1200", 4, "SATA");

    makeRAM(&rm1, "Corsair Vengeance RGB [64 GB]", 5);
    makeRAM(&rm2, "Crucial Pro [32 GB]", 5);
    makeRAM(&rm3, "G.Skill Trident Z RGB [16 GB]", 4);
    makeRAM(&rm4, "Corsair Vengeance RGB Pro [32 GB]", 4);
    makeRAM(&rm5, "ADATA XPG SPECTRIX D35G RGB [32 GB]", 4);

    makePSU(&ps1, "MSI MAG A750GL PCIE5", 750);
    makePSU(&ps2, "Gigabyte P450B", 450);
    makePSU(&ps3, "KOLINK KL-SFX250", 250);
    makePSU(&ps4, "Corsair RM1000x", 1000);
    makePSU(&ps5, "Segotep GN", 650);

    makeGPU(&gp1, "MSI VENTUS 2X PLUS OC [GeForce RTX 5060 Ti]", 180);
    makeGPU(&gp2, "Asus PRIME OC [GeForce RTX 5070 Ti]", 300);
    makeGPU(&gp3, "NVIDIA Founders Edition [GeForce RTX 4090]", 575);
    makeGPU(&gp4, "Asus ROG Matrix Platinum 30th Anniversary Edition [GeForce RTX 5090]", 800);
    makeGPU(&gp5, "PNY VERTO [GeForce RTX 4060]", 115);

    makeStorage(&sg1, "Crucial P310 [1 TB]", "M.2");
    makeStorage(&sg2, "Western Digital AV-GP [250 GB]", "SATA");
    makeStorage(&sg3, "MSI SPATIUM M482 [2 TB]", "M.2");
    makeStorage(&sg4, "TEAMGROUP T-Force Vulcan Z [1 TB]", "SATA");
    makeStorage(&sg5, "Patriot P210 [512 GB]", "SATA");

    /// Create Koleksi
    createListCPU(&lc1);
    createListMotherboard(&lm1);
    createListRAM(&lr1);
    createListPSU(&lp1);
    createListGPU(&lg1);
    createListStorage(&ls1);
    createLListPC(&llpc1);

    /// Insert Item
    insertListCPU(&lc1, cpu1);
    insertListCPU(&lc1, cpu2);
    insertListCPU(&lc1, cpu3);
    insertListCPU(&lc1, cpu4);
    insertListCPU(&lc1, cpu5);

    insertListMotherboard(&lm1, mb1);
    insertListMotherboard(&lm1, mb2);
    insertListMotherboard(&lm1, mb3);
    insertListMotherboard(&lm1, mb4);
    insertListMotherboard(&lm1, mb5);
    
    insertListRAM(&lr1, rm1);
    insertListRAM(&lr1, rm2);
    insertListRAM(&lr1, rm3);
    insertListRAM(&lr1, rm4);
    insertListRAM(&lr1, rm5);

    insertListPSU(&lp1, ps1);
    insertListPSU(&lp1, ps2);
    insertListPSU(&lp1, ps3);
    insertListPSU(&lp1, ps4);
    insertListPSU(&lp1, ps5);

    insertListGPU(&lg1, gp1);
    insertListGPU(&lg1, gp2);
    insertListGPU(&lg1, gp3);
    insertListGPU(&lg1, gp4);
    insertListGPU(&lg1, gp5);

    insertListStorage(&ls1, sg1);
    insertListStorage(&ls1, sg2);
    insertListStorage(&ls1, sg3);
    insertListStorage(&ls1, sg4);
    insertListStorage(&ls1, sg5);

    printf("\n/* ============ CPU ============  */\n");
    printListCPU(lc1);

    printf("\n/* ============ Motherboard ============ */\n");
    printListMotherboard(lm1);

    printf("\n/* ============ RAM ============== */\n");
    printListRAM(lr1);

    printf("\n/* ============ PSU ============== */\n");
    printListPSU(lp1);

    printf("\n/* ============ GPU ============== */\n");
    printListGPU(lg1);
    
    printf("\n/* ============ Storage ============== */\n");
    printListStorage(ls1);

    // Brute Force
    bruteForce(&llpc1, lc1, lm1, lr1, lp1, lg1, ls1);

    printLListPC(llpc1);    
    
    size = lc1.size * lm1.size * lr1.size * lp1.size * lg1.size * ls1.size;
    printf("\nBanyak Kombinasi Seluruh Komponen = %d\n", size);
    printf("Banyak Kombinasi Valid PC = %d\n", nbElmLList(llpc1));
    
    return 0;

}