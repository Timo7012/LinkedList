#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int val;
    int key;
    struct node* next;
}lnode;

lnode* list1 = NULL;

lnode * create_node (int key, int val, lnode * node){
    lnode * new_lnode = (lnode*)malloc(sizeof(lnode));
    new_lnode->key = key;
    new_lnode->val = val;
    new_lnode->next = node;
    return new_lnode;
}

void add_list(int key, int val){
    list1 = create_node(key, val, list1);
};

int find_list(int key, lnode* list){
    if(list != NULL){
        if (list->key == key)
            return list->val;
        else
            return find_list(key, list->next);
    }
    printf("Error:Not found key!\n");
    return -1;
}

lnode* del(int key,lnode* list, bool isFirst){
    if (isFirst){
        lnode * tmp;
        if (list->key == key){
            tmp = list->next;
            free(list);
            return tmp;
        } else {
            isFirst = false;
            tmp = del(key,list,isFirst);
            return list;
        }
    } else {
        if (list->next!=NULL){
            if(list->next->key == key){
                lnode* tmp = list->next->next;
                free(list->next);
                list->next = tmp;
                return list;
            } else {
                return del(key, list->next, isFirst);
            }
        } else {
            printf("Error:Not found key!\n");
            return NULL;
        }
    }
}

void delete_list(int key, lnode* list){
    bool isFirst = true;
    list1 = del(key, list,isFirst);
}

void list_nodes(lnode* list){
    if(list == NULL) return;
    printf("\n---------------\n");
    printf("Key is %d\nValue is %d", list->key, list->val);
    printf("\n---------------\n\n");
    list_nodes(list->next);
}

void menu(void){
    printf("----------------------------Linked List Menu----------------------------\n\n");
    printf("a - Add node\n");
    printf("f - Find node by key\n");
    printf("d - Delete node by key\n");
    printf("l - List all nodes\n");
    printf("e - Exit from program\n");
    printf("\n\n----------------------------Linked List Menu----------------------------\n\n");
}



int main(void) {
    menu();
    int key;
    int val;
    char com = 'a';
    while(com != 'e'){
        printf("Please enter the command: ");
        scanf(" %c",&com);
        switch (com) {
            case 'a':
                printf("\nPlease, enter the key: ");
                scanf("%d",&key);
                printf("\nPlease, enter the value: ");
                scanf("%d",&val);
                add_list(key,val);
                printf("Add is successful\n\n");
                break;
            case 'f':
                printf("\nPlease, enter the key: ");
                scanf("%d",&key);
                val = find_list(key,list1);
                printf("Value is %d\n\n",val);
                break;
            case 'd':
                printf("\nPlease, enter the key: ");
                scanf("%d",&key);
                delete_list(key,list1);
                printf("\nDelete is successful\n\n");
                break;
            case 'l':
                list_nodes(list1);
                break;
            case 'e':
                printf("\nGood bye\n");
                return 0;
            default:
                menu();
                break;
        }
    }
    return 0;
}
