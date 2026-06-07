/* 
 *  Pembuat   : Rafif Setya Imaduddin (24060124130115)
 */

#include "../header/PCType.h"
#include "../header/CSPAlgorithm.h"

int main() {
    // Kamus
    /// Koleksi
    ListCPU lc1;
    ListMotherboard lm1;
    ListRAM lr1;
    ListPSU lp1;
    ListGPU lg1;
    ListStorage ls1;

    LListPC llpcBF;
    LListPC llpcBT;
    LListPC llpcIDS;

    /// Objek
    CPU cpu1, cpu2, cpu3, cpu4, cpu5;
    Motherboard mb1, mb2, mb3, mb4, mb5;
    RAM rm1, rm2, rm3, rm4, rm5;
    PSU ps1, ps2, ps3, ps4, ps5;
    GPU gp1, gp2, gp3, gp4, gp5;
    Storage sg1, sg2, sg3, sg4, sg5;

    PC tempPC;

    // Lainnya
    int size, opsi, max_n, n;
    int cpu, mobo, ram, psu, gpu, storage;
    int iterationBF, iterationBT, iterationIDS;
    bool start;

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

    createLListPC(&llpcBF);
    createLListPC(&llpcBT);
    createLListPC(&llpcIDS);

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
    
    // Brute Force
    iterationBF = 0;
    iterationBF = bruteForce(&llpcBF, lc1, lm1, lr1, lp1, lg1, ls1);
    
    // Backtracking
    iterationBT = 0;
    initializePC(&tempPC);
    backtracking(1, &iterationBT, &llpcBT, tempPC, lc1, lm1, lr1, lp1, lg1, ls1);
    
    
    // Iterative Deepening Search
    iterationIDS = 0;
    max_n = 6;
    initializePC(&tempPC);
    iterativeDeepeningSearch(max_n, &iterationIDS, &llpcIDS, tempPC, lc1, lm1, lr1, lp1, lg1, ls1);
    
    printf("\n/* ============ DATASET ============  */\n");
    printf("\n/* ============ CPU ============  */\n");
    printListCPU(lc1);
    
    printf("/* ============ Motherboard ============ */\n");
    printListMotherboard(lm1);
    
    printf("/* ============ RAM ============== */\n");
    printListRAM(lr1);
    
    printf("/* ============ PSU ============== */\n");
    printListPSU(lp1);
    
    printf("/* ============ GPU ============== */\n");
    printListGPU(lg1);
    
    printf("/* ============ Storage ============== */\n");
    printListStorage(ls1);
    
    cpu = nbElmCPU(lc1);
    mobo = nbElmMotherboard(lm1);
    ram = nbElmRAM(lr1);
    psu = nbElmPSU(lp1);
    gpu = nbElmGPU(lg1);
    storage = nbElmStorage(ls1);

    size = cpu * mobo * ram * psu * gpu * storage;
    n = cpu + mobo + ram + psu + gpu + storage;
    
    start = true;
    while (start) {
        printf("\n/* ============ PC Compabilitor ============== */\n");
        printf("/ ***** Pilihan Algoritma ***** /\n");
        printf("[1] Brute Force\n");
        printf("[2] Backtracking\n");
        printf("[3] Iterative Deepening Search\n\n");
        printf("/ ***** Opsi Lain ***** \n");
        printf("[4] /* Tampilkan Kombinasi */\n");
        printf("[5] /* Keluar Program */\n");
        printf("Opsi : ");
        scanf("%d", &opsi);
        
        switch(opsi) {
            case 1:
            printf("\n/************ Brute Force ************/\n");
            printf("Banyak Komponen CPU \t    = %d\n", cpu);
            printf("Banyak Komponen Motherboard = %d\n", mobo);
            printf("Banyak Komponen RAM \t    = %d\n", ram);
            printf("Banyak Komponen PSU \t    = %d\n", psu);
            printf("Banyak Komponen GPU \t    = %d\n", gpu);
            printf("Banyak Komponen Storage     = %d\n", storage);
            printf("Total n     \t\t    = %d\n", n);
            printf("\nKombinasi Seluruh Komponen  = %d\n", size);
            printf("Kombinasi PC yang Valid\t    = %d\n", nbElmPC(llpcBF));
            printf("Iterasi \t\t    = %d\n", iterationBF);
            break;
            
            case 2:
            printf("\n/************ Backtracking ************/\n");
            printf("Banyak Komponen CPU \t    = %d\n", cpu);
            printf("Banyak Komponen Motherboard = %d\n", mobo);
            printf("Banyak Komponen RAM \t    = %d\n", ram);
            printf("Banyak Komponen PSU \t    = %d\n", psu);
            printf("Banyak Komponen GPU \t    = %d\n", gpu);
            printf("Banyak Komponen Storage     = %d\n", storage);
            printf("Total n     \t\t    = %d\n", n);
            printf("\nKombinasi Seluruh Komponen  = %d\n", size);
            printf("Kombinasi PC yang Valid\t    = %d\n", nbElmPC(llpcBT));
            printf("Iterasi \t\t    = %d\n", iterationBT);
            break;
            
            case 3:
            printf("\n/**** Iterative Deepening Search ****/\n");
            printf("Banyak Komponen CPU \t    = %d\n", cpu);
            printf("Banyak Komponen Motherboard = %d\n", mobo);
            printf("Banyak Komponen RAM \t    = %d\n", ram);
            printf("Banyak Komponen PSU \t    = %d\n", psu);
            printf("Banyak Komponen GPU \t    = %d\n", gpu);
            printf("Banyak Komponen Storage     = %d\n", storage);
            printf("Total n     \t\t    = %d\n", n);
            printf("\nKombinasi Seluruh Komponen  = %d\n", size);
            printf("Kombinasi PC yang Valid\t    = %d\n", nbElmPC(llpcIDS));
            printf("Iterasi \t\t    = %d\n", iterationIDS);
            break;
            
            case 4:
                printLListPC(llpcBT);
                break;
            
            case 5:
            start = false;
            break;
            
            default:
            printf("Opsi tidak ada dalam pilihan\n");
            return 0;
        }
    }
    
    
    return 0;
    
}