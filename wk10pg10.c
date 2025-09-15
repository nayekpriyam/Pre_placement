#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Op {
    int type; 
    char *data; 
    struct Op *next;
} Op;

int main(){
    int Q; if(scanf("%d",&Q)!=1) return 0;
    char *s = malloc(1); s[0]=0; int len=0;
    Op *stack = NULL;
    while(Q--){
        int t; scanf("%d",&t);
        if(t==1){
            char tmp[100005]; scanf("%s", tmp);
            int addlen = strlen(tmp);
            s = realloc(s, len+addlen+1);
            memcpy(s+len, tmp, addlen); len+=addlen; s[len]=0;
            Op *op = malloc(sizeof(Op)); op->type=1; op->data=strdup(tmp); op->next=stack; stack=op;
        } else if(t==2){
            int k; scanf("%d",&k);
            if(k>len) k=len;
            char *deleted = malloc(k+1);
            memcpy(deleted, s+len-k, k); deleted[k]=0;
            s[len-k]=0; len-=k; s = realloc(s, len+1);
            Op *op = malloc(sizeof(Op)); op->type=2; op->data=deleted; op->next=stack; stack=op;
        } else if(t==3){
            int pos; scanf("%d",&pos);
            if(pos>=1 && pos<=len) printf("%c\n", s[pos-1]); else printf("\n");
        } else if(t==4){
            if(stack){
                Op *op = stack; stack = stack->next;
                if(op->type==1){
                    int k = strlen(op->data);
                    s[len-k]=0; len-=k; s = realloc(s, len+1);
                    free(op->data); free(op);
                } else if(op->type==2){
                    int k = strlen(op->data);
                    s = realloc(s, len+k+1);
                    memcpy(s+len, op->data, k); len+=k; s[len]=0;
                    free(op->data); free(op);
                }
            }
        }
    }
    free(s);
    while(stack){ Op *t=stack; stack=stack->next; free(t->data); free(t); }
    return 0;
}
