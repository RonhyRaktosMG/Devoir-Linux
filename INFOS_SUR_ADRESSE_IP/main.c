#include <stdio.h>
#include <stdlib.h>
#include "lib_adresse.h"
#include <math.h>
#include <string.h>



int main()
{
    char data[25] = "";

    printf("Entrer le ip : ");
    scanf("%s", data);
    
    int bits_host = get_bits_host(data);
    char netmask[21] = "";
    char adresse_reseau[21] = "";
    char adresse_broadcast[21] = "";
    int number_of_machine = get_number_of_machine(bits_host);
    int number_of_cuts;
    
    printf("Data : %s\n", data);

    get_netmask(netmask, bits_host);
    printf("netmask : %s", netmask);

    get_adresse_reseau(data, netmask, adresse_reseau);
    printf("adresse réseau : %s\n", adresse_reseau);

    get_adresse_broadcast(adresse_reseau, adresse_broadcast, bits_host);
    printf("adresse broadcast : %s\n", adresse_broadcast);

    printf("Nombre de machine : %d \n", number_of_machine);

    
    printf("\n\n==>Entrer le nombre de fois de découpe : ");
    scanf("%d", &number_of_cuts);
    display_reseau_and_broadcast_for_each(adresse_reseau, adresse_broadcast, bits_host, number_of_cuts);

    return 0;
}

