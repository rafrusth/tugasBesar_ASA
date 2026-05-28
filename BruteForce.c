/* 
 *  Pembuat   : Rafif Setya Imaduddin (24060124130115)
 */

#include "PCType.h"

void bruteForce(LListPC *ll_pc, ListCPU l_cpu, ListMotherboard l_mobo, ListRAM l_ram) {
    // Kamus Lokal
    int i,j,k;
    PC tempPC;
    // int counter;

    // Algoritma
    // counter = 0;
    for (i = 0; i < l_cpu.size; i++) {
        for (j = 0; j < l_mobo.size; j++) {
            for (k = 0; k < l_ram.size; k++) {
                if (!strcmp(l_cpu.container[i].socket, l_mobo.container[j].socket)
                    &&
                   (l_mobo.container[j].ddr == l_ram.container[k].ddr)) {
                    makePC(&tempPC, l_cpu.container[i], l_mobo.container[j], l_ram.container[k]);
                    insertLListPC(ll_pc, tempPC);
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
    LListPC llpc1;

    /// Objek
    CPU cpu1;
    CPU cpu2;

    Motherboard mb1;

    RAM rm1;
    RAM rm2;

    /// Others
    int i;

    // Algoritma
    /// Make
    makeCPU(&cpu1, "AMD Ryzen 7 9800X3D", "AM5", 120);
    makeCPU(&cpu2, "AMD Ryzen 5 8600G", "AM5", 65);

    makeMotherboard(&mb1, "Asus TUF GAMING B650", "AM5", 5);

    makeRAM(&rm1, "Corsair Vengeance RGB 64 GB", 5);
    makeRAM(&rm2, "Crucial Pro 32 GB", 5);

    /// Create Koleksi
    createListCPU(&lc1);
    createListMotherboard(&lm1);
    createListRAM(&lr1);
    createLListPC(&llpc1);

    /// Insert Item
    insertListCPU(&lc1, cpu1);
    insertListCPU(&lc1, cpu2);

    insertListMotherboard(&lm1, mb1);
    
    insertListRAM(&lr1, rm1);
    insertListRAM(&lr1, rm2);

    printf("\n/* ============ CPU ============  */\n");
    printListCPU(lc1);

    printf("\n/* ============ Motherboard ============ */\n");
    printListMotheboard(lm1);

    printf("\n/* ============ RAM ============== */\n");
    printListRAM(lr1);

    bruteForce(&llpc1, lc1, lm1, lr1);

    printf("\nBanyak Kombinasi PC = %d\n", nbElmLList(llpc1));
    printLListPC(llpc1);    

}