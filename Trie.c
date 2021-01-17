#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define NUM_LETTERS ((int)26)
typedef enum {FALSE=0, TRUE=1} boolean;
typedef struct node {
long unsigned int count;
char letter;
struct node* children[NUM_LETTERS];
} 

node, *node_pointer;
node* newVertex();
node_pointer static addNode(char list, node_pointer current);
void static p_frequency(node_pointer root, int x, char *word, int y);
void static recursive_dest(node_pointer root)
int main(int argc, char *argv[])




node* newVertex(){
    node_pointer nv = (node_pointer)malloc(sizeof(struct node));
    if (nv)
    {
        nv -> letter = '\0';
        nv -> count = 0;
        int i;
        for (i = 0; i < NUM_LETTERS; ++i) {
            nv->children[i]=NULL;
        } 
        return nv;
    }
    return NULL;
}




node_pointer  addNode(char list, node_pointer current) {
    node_pointer ans = newVertex();
    if(ans)
    {
        current -> children [list - 'a'] = ans; //ascii table
        ans -> letter = list;
        return ans;
    }
    return NULL;
}





void static p_frequency (node_pointer root, int x, char *word, int y) {
    int i = 0;
    if(root -> count !=0)
    {
        printf("%s %lu\n", word, root -> count);
    }
    if (x)
        i = NUM_LETTERS-1;
    for (; x ? i >= 0 : i < NUM_LETTERS; x ? i-- : i++) {
        if (root- > children[i] != NULL) {
            word[y-1] = i + 'a';
            word[y]= '\0';
            p_frequency((root->children[i]), x, word, y + 1);
        }
    }
    free(root);
}






void static recursive_dest(node_pointer root){
    for(int i=0; i < 25; ++i) { //NUMLETTER - 1 = 25(define)
        if (root->children[i] != NULL) {
            recursive_dest((root -> children[i]));
        }
    }
    free(root);
}




int main(int argc, char *argv[]) {
    node_pointer root = newVertex();
    if(!root) {
        exit(0);
    }
    node_pointer t = root;
    int i = 0;
    int maximum = 0;
    char current;

    while ((current = fgetc(stdin)) && current != EOF) {
        current = tolower(current);
        if ((current == ' ' || current == '\r' || current == '\n' || current == '\t') && t != root) { //edge cases
            maximum = maximum < i ? i : maximum;
            i=0;
            t -> count++;
            t = root;
            continue;
        }

        if (t- > children[current - 'a'] != NULL) 
        {
            t = t -> children[current - 'a'];
            continue;
        }

        if (current > 'z' || current < 'a') //out of range
        {
            continue;
        }

        else {
            t = addNode(current, t);
            if(!t){
                recursive_dest(root);
                exit(0);
            }
            i++;
        }
    }
    maximum = maximum <i ? i : maximum;
    int t = 0;

    if (!word){
        recursive_dest(root);
        exit(0);
    }

    if(argc == 2 && argv[1][0] == 'r')
    {
        t=1;
        char *word = (char*)malloc(maximum* sizeof(char) + 1);
    }

    p_frequency(root,t,word,1);
    free(word);
    exit(0);
}