#include <stdio.h>
#include <stdlib.h>
#include "lib_adresse.h"
#include <math.h>
#include <string.h>


void get_netmask(char *netmask, int bits_host)
{
    int byte_to_take;
    int byte_for_reseau;
    int counter = 0;
    int netmask_int[4];
    
    while (bits_host > 0)
    {
        byte_to_take = (bits_host >= 8) ? 8 : bits_host;
        bits_host -= byte_to_take;
        byte_for_reseau = 0;

        short i=byte_to_take;
        while (i < 8 )
        {
            byte_for_reseau += pow(2, i);
            i++;
        }

        netmask_int[4-counter-1] = byte_for_reseau;
        counter++;
    }

    while (counter < 4)
    {
        netmask_int[4-counter-1] = 255;    
        counter ++;
    }
    sprintf(netmask, "%d.%d.%d.%d\n", netmask_int[0], netmask_int[1], netmask_int[2], netmask_int[3]);


}

int get_bits_host (char *ip_str)
{
    int bits_host = 0;
    int bits_reseau = 0;
    char ip_without_sr[20] = "";
    sscanf(ip_str, "%[^/]/%d",ip_without_sr, &bits_reseau);
    bits_host = 32 - bits_reseau;
    
    if (bits_reseau == 0)
    {
        int first_byte = 0;
        sscanf(ip_without_sr, "%d.", &first_byte);

        if (first_byte >= 0 && first_byte < 128)
            bits_host = 24;
        else if (first_byte < 192)
            bits_host = 16;
        else if (first_byte < 224)
            bits_host = 8;
    }

    return bits_host;
}

void get_adresse_reseau (char *ip_str, char *netmask, char *adresse)
{
    int ip_int[4];
    int netmask_int[4];

    sscanf(netmask, "%d.%d.%d.%d", &netmask_int[0], &netmask_int[1], &netmask_int[2], &netmask_int[3]);
    sscanf(ip_str, "%d.%d.%d.%d", &ip_int[0], &ip_int[1], &ip_int[2], &ip_int[3]);
    
    sprintf(adresse, "%d.%d.%d.%d", ip_int[0]&netmask_int[0], ip_int[1]&netmask_int[1], ip_int[2]&netmask_int[2], ip_int[3]&netmask_int[3]);
}

void get_adresse_broadcast (char *adresse_reseau, char *adresse_broadcast, int bits_host)
{
    int adresse_reseau_int[4];

    sscanf(adresse_reseau, "%d.%d.%d.%d", &adresse_reseau_int[0], &adresse_reseau_int[1], &adresse_reseau_int[2], &adresse_reseau_int[3]);

    int byte_to_take;
    int byte_for_host;
    short counter=0;

    while (bits_host > 0)
    {
        byte_to_take = (bits_host >= 8) ? 8 : bits_host;
        bits_host -= byte_to_take;
        byte_for_host = 0;

        short i=0;
        while (i < byte_to_take )
        {
            byte_for_host += pow(2, i);
            i++;
        }

        adresse_reseau_int[4-counter-1] = byte_for_host | adresse_reseau_int[4-counter-1];
        counter++;
    }


    sprintf(adresse_broadcast, "%d.%d.%d.%d", adresse_reseau_int[0],adresse_reseau_int[1],adresse_reseau_int[2],adresse_reseau_int[3]);
}

int get_number_of_machine(int bits_host)
{
    int nbr = pow(2, bits_host) - 2;
    return nbr;
}


void display_reseau_and_broadcast_for_each(char *adresse_reseau, char *adresse_broadcast,int bits_host, int number_of_cuts)
{
    int *adresse_reseau_int;
    adresse_reseau_int = malloc(4*sizeof(int));

    int *adresse_broadcast_int;
    adresse_broadcast_int = malloc(4*sizeof(int));

    sscanf(adresse_reseau, "%d.%d.%d.%d", &adresse_reseau_int[0], &adresse_reseau_int[1], &adresse_reseau_int[2], &adresse_reseau_int[3]);
    sscanf(adresse_broadcast, "%d.%d.%d.%d", &adresse_broadcast_int[0], &adresse_broadcast_int[1], &adresse_broadcast_int[2], &adresse_broadcast_int[3]);

    int number_of_machine = get_number_of_machine(bits_host-number_of_cuts);


    printf("\n\n===============================================================================\n");
    printf("\t\tAdresse de Chaque découpe : \n");
    printf("===============================================================================\n");

    for (int i=0; i<pow(2, number_of_cuts); i++)
    {
        printf("@Réseau : %d.%d.%d.%d \t\t", adresse_reseau_int[0], adresse_reseau_int[1], adresse_reseau_int[2], adresse_reseau_int[3]);
        adresse_broadcast_int = get_reseau_and_broadcast_for_each(adresse_reseau_int, number_of_machine+1); 
        printf("@Broadcast : %d.%d.%d.%d \t\t Nombre machine : %d\n", adresse_broadcast_int[0], adresse_broadcast_int[1], adresse_broadcast_int[2], adresse_broadcast_int[3], number_of_machine);
        adresse_reseau_int = get_reseau_and_broadcast_for_each(adresse_broadcast_int, 1);

    }

}


int * get_reseau_and_broadcast_for_each(int *adresse_reseau_int, int number_of_machine)
{
    int *new_adresse;
    new_adresse = malloc(4*sizeof(int));
    new_adresse[0] = adresse_reseau_int[0];
    new_adresse[1] = adresse_reseau_int[1];
    new_adresse[2] = adresse_reseau_int[2];
    new_adresse[3] = adresse_reseau_int[3];

    while (number_of_machine > 0)
    {
        new_adresse[3] += (number_of_machine > 255) ? 256 : number_of_machine;
        number_of_machine -= new_adresse[3];
        while (new_adresse[3] > 255)
        {
            new_adresse[3] -= 255;
            new_adresse[2]++;
        }
        while (new_adresse[2] > 255)
        {
            new_adresse[2] -= 255;
            new_adresse[1]++;
        }
        while (new_adresse[1] > 255)
        {
            new_adresse[1] -= 255;
            new_adresse[0]++;
        }
    }

    return new_adresse;
}
