#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1000
#define HASHS 2003
#define STRLEN 64

typedef struct StrNode { char dest[STRLEN]; struct StrNode *next; } StrNode;
typedef struct MapEntry {
    char src[STRLEN];
    StrNode *dests;
    struct MapEntry *next;
} MapEntry;

MapEntry *htable[HASHS];

unsigned int hashstr(const char *s){
    unsigned int h=5381;
    while(*s) h = ((h<<5) + h) + (unsigned char)(*s++);
    return h % HASHS;
}

MapEntry* get_entry_create(const char *src){
    unsigned int h = hashstr(src);
    MapEntry *e = htable[h];
    while(e){ if(strcmp(e->src, src)==0) return e; e=e->next;}
    e = malloc(sizeof(MapEntry));
    strcpy(e->src, src);
    e->dests = NULL;
    e->next = htable[h];
    htable[h] = e;
    return e;
}

void add_ticket(const char *src, const char *dst){
    MapEntry *e = get_entry_create(src);
    StrNode *n = malloc(sizeof(StrNode));
    strncpy(n->dest, dst, STRLEN-1); n->dest[STRLEN-1]=0;
    n->next = e->dests; e->dests = n;
}

int cmpstr(const void *a,const void *b){ return strcmp(*(const char**)a, *(const char**)b); }

void sort_dest_list(StrNode **head){
    int cap=8, cnt=0;
    char **arr = malloc(sizeof(char*)*cap);
    StrNode *cur = *head;
    while(cur){
        if(cnt==cap){ cap*=2; arr=realloc(arr,sizeof(char*)*cap); }
        arr[cnt] = strdup(cur->dest);
        cnt++; cur = cur->next;
    }
    if(cnt==0){ free(arr); return; }
    qsort(arr, cnt, sizeof(char*), cmpstr);
    StrNode *new = NULL;
    for(int i=0;i<cnt;i++){
        StrNode *n = malloc(sizeof(StrNode));
        strncpy(n->dest, arr[i], STRLEN-1); n->dest[STRLEN-1]=0;
        n->next = new; new = n;
        free(arr[i]);
    }
    free(arr);
    cur = *head;
    while(cur){ StrNode *t=cur; cur=cur->next; free(t);}
    *head = new;
}

void prepare_all(){
    for(int i=0;i<HASHS;i++){
        MapEntry *e = htable[i];
        while(e){ sort_dest_list(&e->dests); e = e->next; }
    }
}

StrNode* pop_dest(MapEntry *e){
    if(!e->dests) return NULL;
    StrNode *n = e->dests;
    e->dests = n->next;
    n->next = NULL;
    return n;
}

void dfs(const char *src, char result[][STRLEN], int *ri){
    unsigned int h = hashstr(src);
    MapEntry *e = htable[h];
    while(e && strcmp(e->src, src)!=0) e=e->next;
    while(e && e->dests){
        StrNode *n = pop_dest(e);
        dfs(n->dest, result, ri);
        free(n);
    }
    strncpy(result[(*ri)++], src, STRLEN-1);
}

int main(){
    const char *tickets[][2] = {
        {"Chennai","Banglore"},
        {"Bombay","Delhi"},
        {"Goa","Chennai"},
        {"Delhi","Goa"}
    };
    int m = 4;
    for(int i=0;i<HASHS;i++) htable[i]=NULL;
    for(int i=0;i<m;i++) add_ticket(tickets[i][0], tickets[i][1]);
    prepare_all();
    char result[200][STRLEN];
    int ri=0;
    dfs("Bombay", result, &ri);
    for(int i=ri-1;i>=0;i--) printf("%s ", result[i]);
    printf("\n");
    return 0;
}
