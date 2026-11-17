#include <limits.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

int main(){
    srand(time(0)); 
    ull len_password = 0;
    fprintf(stderr,"Enter the size of password: ");
    scanf("%llu", &len_password);

    char *arr_password = (char *)malloc(sizeof(char) * len_password + 1);

    if(arr_password == 0){
        fprintf(stderr, "Error in malloc");
    }

    printf("Gerando a senha... aguarde...\n");
    clock_t tempo_inicio = clock();

    for(ull i = 0; i < len_password; i++){
        int type = rand() % 3;
        int chance = rand() % 4;
        if(i % 50 == 0){
            arr_password[i] = '\n';
        }
        if(chance == 1){
            arr_password[i] = (rand() % 2) ? '@' : '&';
        }else{
            switch (type) {
                case 0: arr_password[i] = rand() % 10 + 48; 
                    break;
                case 1: arr_password[i] = rand() % 26 + 65;
                    break;
                case 2: arr_password[i] = rand() % 26 + 97; 
                    break;
            }
        }
    }
    arr_password[len_password] = '\0';

    clock_t tempo_fim = clock();
    double tempo_gasto = (double)(tempo_fim - tempo_inicio) / CLOCKS_PER_SEC;

    printf("\n%s\n", arr_password);
    fprintf(stderr ,"Tempo de processamento: %f segundos.\n", tempo_gasto);
    free(arr_password); 
    return EXIT_SUCCESS;
}
