#include <stdio.h>
#define MAX 256

void firstNonRepeating(char stream[]){
    int freq[MAX]={0};
    char q[1000];int f=0,r=0;
    for(int i=0;stream[i];i++){
        char ch=stream[i];freq[ch]++;
        q[r++]=ch;
        while(f<r && freq[q[f]]>1) f++;
        if(f==r) printf("-1 ");
        else printf("%c ",q[f]);
    }
}

int main(){
    char str[]="aabc";
    firstNonRepeating(str);
    return 0;
}
