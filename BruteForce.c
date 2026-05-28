/* 
 *  Pembuat   : Rafif Setya Imaduddin (24060124130115)
 */

#include "PCType.h"

void bruteForce(LListPC *ll_pc, ListCPU l_cpu, ListMotherboard l_mobo, ListRAM l_ram, ListPSU l_psu, ListGPU l_gpu) {
    // Kamus Lokal
    int count_cpu, count_mobo, count_ram, count_psu, count_gpu;
    PC tempPC;

    // Algoritma
    for (count_cpu = 0; count_cpu < l_cpu.size; count_cpu++) {
        for (count_mobo = 0; count_mobo < l_mobo.size; count_mobo++) {
            for (count_ram = 0; count_ram < l_ram.size; count_ram++) {
                for (count_psu = 0; count_psu < l_psu.size; count_psu++) {    
                    for (count_gpu = 0; count_gpu < l_gpu.size; count_gpu++) {
                        if (!strcmp(l_cpu.container[count_cpu].socket, l_mobo.container[count_mobo].socket)
                            &&
                            (l_mobo.container[count_mobo].ddr == l_ram.container[count_ram].ddr)
                            &&
                            ((l_cpu.container[count_cpu].tdp + l_gpu.container[count_gpu].tdp) <= l_psu.container[count_psu].power)) {
                                makePC(&tempPC, l_cpu.container[count_cpu], l_mobo.container[count_mobo], l_ram.container[count_ram], l_psu.container[count_psu], l_gpu.container[count_gpu]);
                                insertLListPC(ll_pc, tempPC);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    // Kamus
    /// Koleksi
    ListCPU lc1;
    ListMotherboard lm1;
    ListRAM lr1;
    ListPSU lp1;
    ListGPU lg1;
    LListPC llpc1;

    /// Objek
    CPU cpu1;
    CPU cpu2;
    Motherboard mb1;
    Motherboard mb2;
    RAM rm1;
    RAM rm2;
    PSU ps1;
    PSU ps2;
    GPU gp1;
    GPU gp2;

    // Algoritma
    /// Make
    makeCPU(&cpu1, "AMD Ryzen 7 9800X3D", "AM5", 120);
    makeCPU(&cpu2, "AMD Ryzen 5 8600G", "AM5", 65);

    makeMotherboard(&mb1, "Asus TUF GAMING B650-PLUS WIFI", "AM5", 5);
    makeMotherboard(&mb2, "ASRock Phantom Gaming X870E Nova WiFi", "AM5", 5);

    makeRAM(&rm1, "Corsair Vengeance RGB [64 GB]", 5);
    makeRAM(&rm2, "Crucial Pro [32 GB]", 5);

    makePSU(&ps1, "MSI MAG A750GL PCIE5", 750);
    makePSU(&ps2, "Gigabyte P450B ", 450);

    makeGPU(&gp1, "MSI VENTUS 2X PLUS OC [GeForce RTX 5060 Ti]", 180);
    makeGPU(&gp2, "Asus PRIME OC [GeForce RTX 5070 Ti]", 300);

    /// Create Koleksi
    createListCPU(&lc1);
    createListMotherboard(&lm1);
    createListRAM(&lr1);
    createListPSU(&lp1);
    createListGPU(&lg1);
    createLListPC(&llpc1);

    /// Insert Item
    insertListCPU(&lc1, cpu1);
    insertListCPU(&lc1, cpu2);

    insertListMotherboard(&lm1, mb1);
    insertListMotherboard(&lm1, mb2);
    
    insertListRAM(&lr1, rm1);
    insertListRAM(&lr1, rm2);

    insertListPSU(&lp1, ps1);
    insertListPSU(&lp1, ps2);

    insertListGPU(&lg1, gp1);
    insertListGPU(&lg1, gp2);

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

    bruteForce(&llpc1, lc1, lm1, lr1, lp1, lg1);

    printf("\nBanyak Kombinasi PC = %d\n", nbElmLList(llpc1));
    printLListPC(llpc1);    

}