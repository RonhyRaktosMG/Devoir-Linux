
void get_netmask(char *netmask, int bits_host);
int get_bits_host (char *ip_str);
void get_adresse_reseau (char *ip_str, char *netmask, char *adresse);
void get_adresse_broadcast (char *adresse_reseau, char *adresse_broadcast, int bits_host);
int get_number_of_machine(int bits_host);
void display_reseau_and_broadcast_for_each(char *adresse_reseau, char *adresse_broadcast,int bits_host, int number_of_cuts);
int * get_reseau_and_broadcast_for_each(int *adresse_reseau_int, int number_of_machine);

