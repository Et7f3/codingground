#include <stdio.h>
#include <stdlib.h>
#define MAX_TEST 3

int test11()
{
  return 1;//succès
}

int test12()
{
  return 0;//echec
}

int test13()
{
  return 1;//succès
}

int test21()
{
  return 1;//succès
}

int test22()
{
  return 1;//succès
}

int test23()
{
  return 1;//succès
}

void action1(int* rep){
    //j'ai accès à un array type [rep_test1,...]
    //je gère a coup de if/switch
    if(rep[0])
        puts("commande 11");
    if(rep[0] || rep[2])
        puts("commande 12");
    if(rep[1])
        puts("commande 13");
}

void action2(int* rep){
    if(rep[0] || rep[2])
        puts("commande 21");
    if(rep[1] || rep[2])
        puts("commande 22");
}
typedef int(*check_t[MAX_TEST + 1])(void);
typedef void(*action_t)(int *);

check_t check_1 = {test11, test12, test13};
check_t check_2 = {test21, test22, test23};

check_t *checks[] = {&check_1, &check_2};

action_t actions[] = {&action1, &action2};

int exec_check(int ch)
{
    int repf = 0;
    int i = 0;
    int rep[MAX_TEST] = {0};
    for(;(*checks[ch])[i]; i++)
    {
        rep[i] = (*checks[ch])[i]();
        repf += rep[i];
    }
    (*actions[ch])(&(rep[0]));
    return repf;
}
int exec_checks()
{
    int i = 0;
    int rep = 0;
    int nb_check = sizeof(checks) / sizeof(check_t*);
    for(; i < nb_check ; i++)
    {
        rep += exec_check(i);
    }
    //all is good
    return rep; 
}

int main()
{
    exec_checks();
    //printf("Hello, World!%d\n%d\n", (*checks[0])[0](), exec_checks());

    return 0;
}

