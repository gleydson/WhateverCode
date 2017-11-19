#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { True = 1, False = 0 } Boolean;
enum { MAX_SIZE = 100, SIZE_NAME = 100, SIZE_DESCRIPTION = 100, SIZE_TYPE = 100 };

typedef struct {
    int code;
    char name[SIZE_NAME];
    char description[SIZE_DESCRIPTION];
    char type[SIZE_TYPE];
    Boolean exist;
} Equipment;

int main() {
    Equipment * listEquipment = (Equipment *) malloc(sizeof(Equipment) * MAX_SIZE);

    int code;
    char name[SIZE_NAME];
    char description[SIZE_DESCRIPTION];
    char type[SIZE_TYPE];

    Boolean registerEquipment(int code, char * name, char * description, char * type) {
        int i = 0;
        for(; i < MAX_SIZE; i++){
            if(listEquipment[i].exist != True){
                Equipment newEquipment;
                newEquipment.code = code;
                strcpy(newEquipment.name, name);
                strcpy(newEquipment.description, description);
                strcpy(newEquipment.type, type);
                newEquipment.exist = True;
                listEquipment[i] = newEquipment;
                return True;
            }
        }
        return False;
    }

    Boolean searchEquipment(char * name) {
        int i = 0;
        for(; i < MAX_SIZE; i++){
            if(strcmp(listEquipment[i].name, name) == 0 && listEquipment[i].exist == True) {
                printf("\n%d - %s - %s - %s\n", listEquipment[i].code, listEquipment[i].name, listEquipment[i].description, listEquipment[i].type);
                return True;
            }
        }
        return False;
    }

    int op;
    while(True) {
        //system("clear");
        code = 0;
        strcpy(name, "");
        strcpy(description, "");
        strcpy(type, "");

        printf("\n1 - Create new equipment | 2 - Search equipment | 3 - Exit\n");

        scanf("%d", &op);

        if(op == 3) break;

        switch(op) {
            case 1:
                printf("Enter a code for the product: ");
                scanf("%d", &code);
                printf("Enter a name for the product: ");
                scanf("%s", name);
                printf("Enter a description for the product: ");
                scanf("%s", description);
                printf("Enter a type for the product: ");
                scanf("%s", type);

                if(!registerEquipment(code, name, description, type))
                    printf("\nError recording equipment!\n");
                else
                    printf("\nSuccessfully registered equipment!\n");

                break;
            case 2:
                printf("\nEnter a name to search for a product: ");
                scanf("%s", name);

                if(!searchEquipment(name))
                    printf("\nEquipment not found!\n");
                else
                    printf("\nEquipment found!\n");
            default:
                printf("\nIncorrect code!\n");
        }
    }

    free(listEquipment);

    return 0;
}
