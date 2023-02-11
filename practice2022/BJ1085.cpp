#include <iostream>
using namespace std;
int main(){
    int x,y,w,h;
    cin>>x>>y>>w>>h;
    int tmp;

    if(x>y){
        tmp=y;
    }
    else{
        tmp=x;
    }

    if(w-x>h-y){
        if(h-y>tmp){
            cout<<tmp;
        }
        else{
        cout<<h-y;
        }

        }

    else{

        if(w-x>tmp){
            cout<<tmp;
        }
        else{
        cout<<w-x;
        }

    }

    return 0;
}
