#include <stdio.h>
#include <stdlib.h>

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
    return NULL;
}

lnode* del(int key,lnode* list, char* isFirst){
    if (isFirst){
        lnode * tmp;
        if (list->key == key){
            tmp = list->next;
            free(list);
            return tmp;
        } else {
            *isFirst = 0;
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

lnode* delete_list(int key, lnode* list){
    char* isFirst=(char*)malloc(sizeof(char));
    lnode* tmp=del(key, list,isFirst);
    free(isFirst);
    return tmp;
}

int main(void) {

    return 0;
}
