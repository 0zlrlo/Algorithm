#include <stdio.h>
double factorial(int k){
    if(k==0||k==1){
        return 1;
    }
    else{
        return k*factorial(k-1);
    }
}
double result(int n, int m){
    return factorial(m)/factorial(m-n)*factorial(n);
}
int main(void){
    int num, n, m, ans;
    scanf("%d",&num);
    for(int i=0;i<num;i++){
        scanf("%d %d",&n ,&m);
    }
    for(int i=0;i<num;i++){
        printf("%.lf\n",result(n,m));
    }

    return 0;
}