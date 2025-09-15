#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 200003

typedef struct Node { char *sig; int count; struct Node *next; } Node;
Node *htable[HASH_SIZE];

unsigned long djb2(const char *s){
    unsigned long h=5381; while(*s) h = ((h<<5)+h) + (unsigned char)(*s++); return h;
}

char* signature(const char *s, int len){
    int cnt[26]={0};
    for(int i=0;i<len;i++) cnt[s[i]-'a']++;
    char *sig = malloc(26*3+1);
    char *p = sig;
    for(int i=0;i<26;i++){ int v=cnt[i]; p += sprintf(p, "%d#", v); }
    return sig;
}

int main(){
    int T; if(scanf("%d",&T)!=1) return 0;
    while(T--){
        char s[10005];
        scanf("%s", s);
        int n = strlen(s);
        for(int i=0;i<HASH_SIZE;i++){ Node *cur=htable[i]; while(cur){ Node *t=cur; cur=cur->next; free(t->sig); free(t); } htable[i]=NULL; }
        long long ans=0;
        for(int len=1; len<=n; len++){
            for(int i=0;i+len<=n;i++){
                char *sig = signature(s+i, len);
                unsigned long h = djb2(sig) % HASH_SIZE;
                Node *cur = htable[h];
                while(cur && strcmp(cur->sig, sig)!=0) cur=cur->next;
                if(cur){ ans += cur->count; cur->count++; free(sig); }
                else {
                    Node *nd = malloc(sizeof(Node));
                    nd->sig = sig; nd->count = 1; nd->next = htable[h]; htable[h] = nd;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
