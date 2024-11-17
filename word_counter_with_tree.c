#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

struct tnode {
        int count;
        char *word;
        struct tnode *left;
        struct tnode *right;
};


struct tnode *addtree(struct tnode *p, const char *w)
{
        int cond;

        if (p == NULL) {
                p = (struct tnode *) malloc(sizeof(struct tnode));
                p->word  = strdup(w);
                p->left  = NULL;
                p->right = NULL;
        } else if ((cond = strcmp(w, p->word)) == 0) {
                p->count++;
        } else if (cond < 0) {
                p->left = addtree(p->left, w);
        } else {
                p->right = addtree(p->right, w);
        }
        return p;
}


void treeprint(struct tnode *p)
{
        if (p != NULL) {
                treeprint(p->left);
                printf("%4d %s\n", p->count, p->word);
                treeprint(p->right);
        }
}


int getword(char *line, int lim)
{
        int c = 0, i = 0;

        while ((c = getchar()) != EOF && c != '\n' && --lim > 0)
                line[i++] = c;
        line[i] = '\0';
        return i;
}


int main(void)
{
        struct tnode *root;
        char word[MAX];

        root = NULL;
        while (getword(word, MAX) > 0) {
                if (isalpha(word[0])) {
                        root = addtree(root, word);
                }
        }
        treeprint(root);
        return 0;
}
