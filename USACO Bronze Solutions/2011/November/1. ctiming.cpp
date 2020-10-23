/*
ID: DragonFish
TASK: test
LANG: C++14
*/
#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ifstream myinputfile("ctiming.in");
    ofstream myoutputfile("ctiming.out");
    int d, h, m;
    myinputfile >> d >> h >> m;
    int mm = 0;
    if(h >= 11 && m >= 11){
        mm += (d-11) * 1440;
        mm += (h-11) * 60;
        mm += (m-11);
    }
    else{
        if(d == 11){
            mm = -1;
        }
        else if(d > 11){
            mm += (d-12) * 1440;
            h += 24;
            if(m >= 11){
                mm += (h-11)*60;
                mm += (m-11);
            }
            else if(m < 11){
                h--;
                m += 60;
                mm += (h-11)*60;
                mm += (m-11);
            }
        }
    }
    myoutputfile << mm << endl;
    myoutputfile.close();
    return 0;
}
