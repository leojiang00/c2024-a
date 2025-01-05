#include <iostream>
#include <limits.h>
using namespace std;
int chess[16][16],ju_chess[16][16][4],choice=0,x,y,tx=0,ty=0,time1=0,boderup=1,boderdown=15,boderleft=1,boderright=15;
int dx[4]={1,1,-1,0},dy[4]={0,1,1,1},memory_chess[16*16][2];
int valueate() {
    for(int i=1;i<16;i++) {
        for(int j=1;j<16;j++) {
            for(int l=0;l<4;l++) ju_chess[i][j][l] = 0;
        }
    }
    int botpoint=0,f=0;
    for(int i=1;i<16;i++) {
        for(int j=1;j<16;j++) {
            for(int l=0;l<4;l++) {
                int tot=0;
                for(int k=0;k<=4&&(i+k*dx[l])<16&&(j+k*dy[l])<16;k++) {
                    if(chess[i+k*dx[l]][j+k*dy[l]]==1) tot++;
                    else if(chess[i+k*dx[l]][j+k*dy[l]]==2) tot--;
                }
                if(tot==5&&!ju_chess[i][j][l]) {

                    botpoint+=1000000;
                    //cout<<"botpoint add:"<<10000<<endl;
                    for(int m=0;m<=4;m++) {
                        ju_chess[i+m*dx[l]][j+m*dy[l]][l]=1;
                        //cout<<"        :"<<i+m*dx[l]<<" "<<j+m*dy[l]<<endl;
                    }

                }
                else if(tot==-5&&!ju_chess[i][j][l]) {
                    botpoint-=900000;
                    //cout<<"botpoint add:"<<-10000<<endl;
                    for(int m=0;m<=4;m++) {
                        ju_chess[i+m*dx[l]][j+m*dy[l]][l]=1;
                        //cout<<"        :"<<i+m*dx[l]<<" "<<j+m*dy[l]<<endl;
                    }
                }
                else if(tot==4&&!ju_chess[i][j][l]) {
                    if((chess[i][j]==0&&chess[i+5*dx[l]][j+5*dy[l]]==0)||(chess[i-dx[l]][j-dy[l]]==0&&chess[i+4*dx[l]][j+4*dy[l]]==0)) {
                        botpoint+=90500;
                        //cout<<"botpoint add:"<<9050<<endl;

                    }
                    else {
                        botpoint+=90400;
                        //cout<<"botpoint add:"<<9040<<endl;
                    }

                    for(int m=0;m<=4&&chess[i+m*dx[l]][j+m*dy[l]]==1;m++) {
                        ju_chess[i+m*dx[l]][j+m*dy[l]][l]=1;
                        //cout<<"        :"<<i+m*dx[l]<<" "<<j+m*dy[l]<<endl;
                    }
                }
                else if(tot==-4&&!ju_chess[i][j][l]) {
                    if((chess[i][j]==0&&chess[i+5*dx[l]][j+5*dy[l]]==0)||(chess[i-dx[l]][j-dy[l]]==0&&chess[i+4*dx[l]][j+4*dy[l]]==0)) {
                        botpoint-=90300;
                        //cout<<"botpoint add:"<<-9030<<endl;
                    }
                    else {
                        botpoint-=90200;
                        //cout<<"botpoint add:"<<-9020<<endl;

                    }
                    for(int m=0;m<=4&&chess[i+m*dx[l]][j+m*dy[l]]==2;m++) {
                        ju_chess[i+m*dx[l]][j+m*dy[l]][l]=1;
                        //cout<<"        :"<<i+m*dx[l]<<" "<<j+m*dy[l]<<endl;
                    }
                }

                else if(tot==3&&!ju_chess[i][j][l]) {
                    if((chess[i][j]==0&&chess[i+5*dx[l]][j+5*dy[l]]==0)){
                        botpoint+=8010;
                        //cout<<"botpoint add:"<<9010<<endl;
                    }
                    else {
                        botpoint+=7090;
                        //cout<<"botpoint add:"<<8090<<endl;
                    }
                    for(int m=0;m<=4&&chess[i+m*dx[l]][j+m*dy[l]]==1;m++) {
                        ju_chess[i+m*dx[l]][j+m*dy[l]][l]=1;
                        //cout<<"        :"<<i+m*dx[l]<<" "<<j+m*dy[l]<<endl;
                    }
                }
                else if(tot==-3&&!ju_chess[i][j][l]) {
                    if((chess[i][j]==0&&chess[i+5*dx[l]][j+5*dy[l]]==0)){
                        botpoint-=6010;
                       // cout<<"botpoint add:"<<-9000<<endl;
                    }
                    else {
                        botpoint-=5080;
                        //cout<<"botpoint add:"<<-8080<<endl;
                    }
                    for(int m=0;m<=4&&chess[i+m*dx[l]][j+m*dy[l]]==2;m++) {
                        ju_chess[i+m*dx[l]][j+m*dy[l]][l]=1;
                        //cout<<"        :"<<i+m*dx[l]<<" "<<j+m*dy[l]<<endl;
                    }
                }
                else if(tot==2&&!ju_chess[i][j][l]) {
                    if((chess[i][j]==0&&chess[i+5*dx[l]][j+5*dy[l]]==0)){
                        botpoint+=701;
                        //out<<"botpoint add:"<<7010<<endl;
                    }
                    else {
                        botpoint+=609;
                        //cout<<"botpoint add:"<<6090<<endl;
                    }
                    for(int m=0;m<=4&&chess[i+m*dx[l]][j+m*dy[l]]==1;m++) {
                        ju_chess[i+m*dx[l]][j+m*dy[l]][l]=1;
                       // cout<<"        :"<<i+m*dx[l]<<" "<<j+m*dy[l]<<endl;
                       // if(ju_chess[8][8][l] == 1) f=1;
                    }
                }
                else if(tot==-2&&!ju_chess[i][j][l]) {
                    if((chess[i][j]==0&&chess[i+5*dx[l]][j+5*dy[l]]==0)){
                        botpoint-=500;
                        //cout<<"botpoint add:"<<-5000<<endl;
                    }
                    else {
                        botpoint-=508;
                        //cout<<"botpoint add:"<<-5080<<endl;
                    }
                    for(int m=0;m<=4&&chess[i+m*dx[l]][j+m*dy[l]]==2;m++) {
                        ju_chess[i+m*dx[l]][j+m*dy[l]][l]=1;
                        //cout<<"        :"<<i+m*dx[l]<<" "<<j+m*dy[l]<<endl;
                    }
                }
                else if(tot==1) {
                    botpoint+=10;
                }
                else if(tot==-1) {
                    botpoint-=10;
                }
            }
        }
    }
    // if(f==1) {
    //     for(int i=1;i<16;i++) {
    //         for(int j=1;j<16;j++) {
    //             cout<<chess[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     cout<<botpoint<<endl;
    //     cout<<":dfasfsf"<<endl;
    // }
    //if(botpoint!=0) cout<<"the tot: "<<botpoint<<endl<<endl;
    return botpoint;
}
int max_min(int depth,int a,int b,int boderu,int boderd,int boderl,int boderr){
    //cout<<a<<" "<<b<<endl;
    if(depth<1) {
        return valueate();
    }
    int flag=1;
    for(int i=boderu;i<=boderd&&flag;i++) {
        for(int j=boderl;j<=boderr&&flag;j++) {
            if(depth%2==0&&chess[i][j]==0) {
                // time1++;
                // cout<<time1<<endl;
                int tme1=boderu,tme2=boderd,tme3=boderl,tme4=boderr;
                chess[i][j]=1;
                if(i-3<tme1) {
                    if(i-3<1) tme1=1;
                    else tme1=i-3;
                }
                if(i+3>tme2) {
                    if(i+3>15) tme2=15;
                    else tme2=i+3;
                }
                if(j-3<tme3) {
                    if(j-3<1) tme3=1;
                    else tme3=j-3;
                }
                if(j+3>tme4) {
                    if(j+3>15) tme4=15;
                    else tme4=y+3;
                }
                int value=max_min(depth-1,a,b,tme1,tme2,tme3,tme4);
                //cout<<value<<" max"<<endl;
                if(a<value) {
                    a = value;
                    tx=i; ty=j;
                    //if(depth==2) cout<<"dfasfsad"<<endl;
                }
                chess[i][j]=0;
                if(a>b) {
                    flag=0;
                    break;
                }
            }
            else if(depth%2==1&&chess[i][j]==0){
                // time1++;
                // cout<<time1<<endl;
                int tme1=boderu,tme2=boderd,tme3=boderl,tme4=boderr;
                chess[i][j]=2;
                if(i-3<tme1) {
                    if(i-3<1) tme1=1;
                    else tme1=i-3;
                }
                if(i+3>tme2) {
                    if(i+3>15) tme2=15;
                    else tme2=i+3;
                }
                if(j-3<tme3) {
                    if(j-3<1) tme3=1;
                    else tme3=j-3;
                }
                if(j+3>tme4) {
                    if(j+3>15) tme4=15;
                    else tme4=y+3;
                }if(i-3<tme1) {
                    if(i-3<1) tme1=1;
                    else tme1=i-3;
                }
                if(i+3>tme2) {
                    if(i+3>15) tme2=15;
                    else tme2=i+3;
                }
                if(j-3<tme3) {
                    if(j-3<1) tme3=1;
                    else tme3=j-3;
                }
                if(j+3>tme4) {
                    if(j+3>15) tme4=15;
                    else tme4=y+3;
                }
                b = min(b,max_min(depth-1,a,b,tme1,tme2,tme3,tme4));
                //cout<<depth<<" "<<b<<" min"<<endl;
                chess[i][j]=0;
                if(a>b) {
                    flag=0;
                    break;
                }
            }
        }
    }
    if(depth%2==0) return a;
    else if(depth%2==1) return b;
}
int check() {
        for(int i=1;i<16;i++) {
            for(int j=1;j<16;j++) {
                for(int l=0;l<4;l++) {
                    int tot=0;
                    for(int k=0;k<=4&&(i+k*dx[l])<16&&(j+k*dy[l])<16;k++) {
                        if(chess[i+k*dx[l]][j+k*dy[l]]==1) tot++;
                        else if(chess[i+k*dx[l]][j+k*dy[l]]==2) tot--;
                    }
                    if(tot==5) {
                        return 1;
                    }
                    else if(tot==-5) {
                        return 2;
                    }
                   // cout<<i<<" "<<j<<" "<<tot<<endl;
                }
            }
        }
        return 0;
    }
int main(){
        int f=0;
        while(!choice) {
            cout << "Welcome !" << endl;
            cout << "Do you want to hold" << endl;
            cout << " black enter 1" << endl;
            cout << " white enter 2" << endl;
            cout << " please enter: " << endl;
            cin >> choice;
            if (choice == 2) {
                chess[8][8] = 1;
                boderup=5;
                boderdown=11;
                boderleft=5;
                boderright=11;
                for(int i=1;i<16;i++) {
                    for(int j=1;j<16;j++) {
                        cout<<chess[i][j]<<" ";
                    }
                    cout<<endl;
                }
                cout<<"x: ";
                cin>>x;
                cout<<"y: ";
                cin>>y;
                while(x<1||x>16||y<1||y>16||chess[x][y]) {
                    cout<<"Wrong input!"<<endl;;
                    cout<<"please enter a number between 1 and 16"<<endl;;
                    cout<<"x: ";
                    cin>>x;
                    cout<<"y: ";
                    cin>>y;
                }
                if(x-3<boderup) {
                    if(x-3<1) boderup=1;
                    else boderup=x-3;
                }
                if(x+3>boderdown) {
                    if(x+3>15) boderdown=15;
                    else boderdown=x+3;
                }
                if(y-3<boderup) {
                    if(y-3<1) boderup=1;
                    else boderup=y-3;
                }
                if(y+3>boderdown) {
                    if(y+3>15) boderdown=15;
                    else boderdown=y+3;
                }
                chess[x][y] = 2;
            }
            else if(choice==1){
                cout<<"x: ";
                cin>>x;
                cout<<"y: ";
                cin>>y;
                while(x<1||x>16||y<1||y>16) {
                    cout<<"Wrong input!"<<endl;;
                    cout<<"please enter a number between 1 and 16"<<endl;;
                    cout<<"x: ";
                    cin>>x;
                    cout<<"y: ";
                    cin>>y;
                }
                if(x-3<boderup) {
                    if(x-3<1) boderup=1;
                    else boderup=x-3;
                }
                if(x+3>boderdown) {
                    if(x+3>15) boderdown=15;
                    else boderdown=x+3;
                }
                if(y-3<boderup) {
                    if(y-3<1) boderup=1;
                    else boderup=y-3;
                }
                if(y+3>boderdown) {
                    if(y+3>15) boderdown=15;
                    else boderdown=y+3;
                }
                chess[x][y] = 2;
            }
            else {
                cout<<"Wrong input!"<<endl;
                choice=0;
            }
        }

        for(int i=1;i<16;i++) {
            for(int j=1;j<16;j++) {
                cout<<chess[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        while(1) {
            int point = max_min(2,INT_MIN,INT_MAX,boderup,boderdown,boderleft,boderright);
            cout<<"the bot choose x: "<<tx<<endl;
            cout<<"the bot choose y: "<<ty<<endl;
            chess[tx][ty] = 1;
            f=check();
            for(int i=1;i<16;i++) {
                for(int j=1;j<16;j++) {
                    cout<<chess[i][j]<<" ";
                }
                cout<<endl;
            }
            if(f==1) {
                cout<<"loss";
                break;
            }
            else if(f==2) {
                cout<<"wins";
                break;
            }
            cout<<"x: ";
            cin>>x;
            cout<<"y: ";
            cin>>y;
            while(x<1||x>16||y<1||y>16||chess[x][y]) {
                cout<<"Wrong input!"<<endl;
                cout<<"please enter a number between 1 and 16"<<endl;
                cout<<"x: ";
                cin>>x;
                cout<<"y: ";
                cin>>y;
            }
            chess[x][y] = 2;
            f=check();
            if(f==1) {
                cout<<"loss";
                break;
            }
            else if(f==2) {
                cout<<"wins";
                break;
            }
        }
        return 0;
}
