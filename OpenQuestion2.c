#include<stdio.h>

int main(){
    int t,p,x,r1,n,y,r2;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&p);
        scanf("%d",&x);
        scanf("%d",&r1);

        scanf("%d",&n);
        scanf("%d",&y);
        scanf("%d",&r2);

        if(((p/x)+r1)<((n/y)+r2)){
            printf("PAUL\n%d\n",(p/x)+r1);
        }
        else if(((p/x)+r1)>((n/y)+r2)){
            printf("NINA\n%d\n",(n/y)+r2);
        }
        else{
            printf("BOTH\n%d\n",(n/y)+r2);
        }
    }
    return 0;
}
