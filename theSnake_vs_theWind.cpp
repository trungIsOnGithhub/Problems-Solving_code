// 27/27 testcases successed
//HackerRank University CodeSprint problem


#include<iostream>

using namespace std;

int main(){
    short count=1; short n;
    short startx=0,starty=0; char wind;
    short* next=NULL;
    
    cin>>n;
    cin>>wind;
    cin>>startx>>starty;
    
    short tar=n*n;
    
    short N[8] = {-1,0,0,-1,0,1,1,0};
    short E[8] = {0,1,-1,0,1,0,0,-1}; 
    short S[8] = {1,0,0,1,0,-1,-1,0};
    short W[8] = {0,-1,1,0,-1,0,0,1};
    
    if (wind=='e') next=E;
    else if (wind=='w') next=W;
    else if (wind=='n') next=N;
    else if (wind=='s') next=S;
    
    short** area = new short*[n];
    for (int i=0; i<n; ++i){
        area[i]=new short[n];
    }
    
    for (int i=0; i<n; ++i){
        for (int j=0;j<n; ++j){
            area[i][j]=0;
        }
    }
    
    area[startx][starty]=1;
    
    while(count<tar){
        while (startx+next[0]>=0 && startx+next[0]<n && starty+next[1]>=0 && starty+next[1]<n){
            if (area[startx+next[0]][starty+next[1]]==0){
                ++count;
                area[startx+next[0]][starty+next[1]]=count;
                startx+=next[0];
                starty+=next[1];
            }
            else break;
        }
        while (startx+next[2]>=0 && startx+next[2]<n && starty+next[3]>=0 && starty+next[3]<n){
            if (area[startx+next[2]][starty+next[3]]==0){
                ++count;
                area[startx+next[2]][starty+next[3]]=count;
                startx+=next[2];
                starty+=next[3];
            }
            else break;
        }
        while (startx+next[4]>=0 && startx+next[4]<n && starty+next[5]>=0 && starty+next[5]<n){
            if (area[startx+next[4]][starty+next[5]]==0){
                ++count;
                area[startx+next[4]][starty+next[5]]=count;
                startx+=next[4];
                starty+=next[5];
            }
            else break;
        }
        if (startx+next[6]>=0 && startx+next[6]<n && starty+next[7]>=0 && starty+next[7]<n){
            if (area[startx+next[6]][starty+next[7]]==0){
                ++count;
                area[startx+next[6]][starty+next[7]]=count;
                startx+=next[6];
                starty+=next[7];
            }
        }
    }
    
    for (int i=0; i<n; ++i){
        for (int j=0;j<n; ++j){
            cout<<area[i][j]<<" ";
        }
        cout<<endl;
    }
    
    for (int i=0; i<n; ++i){
        delete[] area[i];
    }
    delete area;

    return 0;
}