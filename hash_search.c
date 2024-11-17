#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 1000

struct nlist {
        struct nlist *next;
        char *name;
        char *defn;
};

static struct nlist *hashtable[HASHSIZE];

unsigned hash(char *s)
{
        unsigned hash_val = 0;
        for ( ; *s != '\0'; s++)
                hash_val = *s + 31 * hash_val;
        return hash_val % HASHSIZE;
}

struct nlist *lookup(char *s)
{
        struct nlist *np;

        for (np = hashtable[hash(s)]; np != NULL; np = np->next) {
                if (strcmp(s, np->name) == 0)
                        return np;
        }
        return NULL;
}

struct nlist *insert(char *name, char *defn)
{
        struct nlist *np;
        unsigned hash_val;

        if ((np = lookup(name)) == NULL) {
                np = (struct nlist *) malloc(sizeof(*np));
                if (np == NULL || (np->name = strdup(name)) == NULL)
                        return NULL;
                hash_val = hash(name);
                np->next = hashtable[hash_val];
                hashtable[hash_val] = np;
        } else {
                free((void *) np->defn);
        }
        if ((np->defn = strdup(defn)) == NULL)
                return NULL;
        return np;
}

int main(void)
{
        insert("chick", "les");
        struct nlist *np = lookup("chick");
        if (np == NULL) {
                printf("can't found!\n");
                return 1;
        }
        printf("name: %s\n", np->name);
        printf("defn: %s\n", np->defn);
        return 0;
}
