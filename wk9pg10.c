#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORDHASH 2003
typedef struct WNode { char *word; int cnt; struct WNode *next; } WNode;
WNode *whash[WORDHASH];

unsigned int wh(const char *s){
    unsigned int h=5381; while(*s) h=((h<<5)+h)+(unsigned char)(*s++);
    return h % WORDHASH;
}

void add_word(const char *s){
    unsigned int k = wh(s);
    WNode *cur = whash[k];
    while(cur){ if(strcmp(cur->word, s)==0){ cur->cnt++; return; } cur=cur->next; }
    WNode *n = malloc(sizeof(WNode)); n->word = strdup(s); n->cnt = 1; n->next = whash[k]; whash[k]=n;
}

int use_word(const char *s){
    unsigned int k = wh(s);
    WNode *cur = whash[k];
    while(cur){ if(strcmp(cur->word,s)==0){ if(cur->cnt>0){ cur->cnt--; return 1; } else return 0;} cur=cur->next; }
    return 0;
}

int main(){
    char magazine[][16] = {"give","me","one","grand","today","night"};
    char ransom[][16] = {"give","one","grand","today"};
    int m = 6, n = 4;
    for(int i=0;i<WORDHASH;i++) whash[i]=NULL;
    for(int i=0;i<m;i++) add_word(magazine[i]);
    int possible = 1;
    for(int i=0;i<n;i++){
        if(!use_word(ransom[i])) { possible = 0; break; }
    }
    if(possible) printf("Yes\n"); else printf("No\n");
    return 0;
}
