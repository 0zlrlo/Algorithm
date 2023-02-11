#include <iostream>

using namespace std;
int main(){
    int T;
    int[][] people=new int[15][15];
    cin>>T;
    for(int i=0;i<15;i++){
        people[i][1]=1;
        people[0][i]=i;
    }
    for(int i=1;i<15;i++){  //1~14층  0층은 제외
    for(int j=2;j<15;j++){   //2~14호  1호는 제외
    people[i][j]=people[i][j-1]+people[i-1][j];
    }
    }
    for(int i=0;i<T;i++){
        cout<<people[i][j]<<endl;
    }
}

//뇌절,, 이건 좀 나중에 하자