#include<iostream>
using namespace std;

int main(){
    int ttime, num;
    int timecost[110]{0};
    int value[110]{0};
    int package[1010][110]{0};
    cin >> ttime >> num;
    for(int i = 1; i <= num; i++){
        cin >> timecost[i] >> value[i];
    }
    for(int i = 1; i <= num ; i++){
        for( int j = 1; j <= ttime; j++){
            if(j < timecost[i]){
                package[j][i] = package[j][i - 1];
            }else{
                if(package[j - timecost[i]][i - 1] + value[i] > package[j][i - 1]){
                    package[j][i] = package[j - timecost[i]][i - 1] + value[i];
                }else{
                    package[j][i] = package[j][i - 1];
                }
            }
        }
    }
    cout << package[ttime][num] << endl;
}