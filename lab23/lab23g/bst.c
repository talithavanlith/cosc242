#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "bst.h"
#include <string.h>

struct bstnode{
    char *key;
    bst left;
    bst right;
};

bst bst_new(){
    bst b = emalloc(sizeof *b);
    b->left = NULL;
    b->right = NULL;
    b->key = NULL;
    return b;
}

bst bst_insert(bst b, char *str){
    if(b == NULL){
        b = bst_new();
    }
    if(b->key == NULL){
        b->key = emalloc((strlen(str)+1) * sizeof b->key[0]);
        strcpy(b->key, str);
    }else if(strcmp(str, b->key) == 0){
        return b;
    }else if(strcmp(str, b->key) < 0){
        b->left = bst_insert(b->left, str);
    }else{
        b->right = bst_insert(b->right, str);
    }
    return b;
}

bst bst_free(bst b){
    free(b->key);
    if(b->left != NULL){
        b->left = bst_free(b->left);
    }
    if(b->right != NULL){
        b->right = bst_free(b->right);
    }
    free(b);
    return b;
}

void bst_preorder(bst b, void f(char *str)){
    if(b == NULL){
        return;
    } 
    if(b->key != NULL){
        f(b->key);
    }
    if (b->left != NULL){
        bst_preorder(b->left, f);
    }
    if(b->right != NULL){
        bst_preorder(b->right, f);
    }
    return;
    
}

void bst_inorder(bst b, void f(char *str)){
    if(b == NULL){
        return;
    } 
    if (b->left != NULL){
        bst_inorder(b->left, f);
    }
    if(b->key != NULL){
        f(b->key);
    }
    if(b->right != NULL){
        bst_inorder(b->right, f);
    }
    return;
}

int bst_search(bst b, char *str){
    if(b == NULL){
        return 0;
    }else if(strcmp(str, b->key) == 0){
        return 1;
    }else if(strcmp(str, b->key) <0){
        return bst_search(b->left, str);
    }else if(strcmp(str, b->key) >0){
        return bst_search(b->right, str);
    }else{
        return 0;
    }
}
