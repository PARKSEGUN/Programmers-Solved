#include <string>
#include <vector>
#include<iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int allDeliver=0;
    int allPickup=0;

    for(auto x: deliveries){allDeliver+=x;}
    for(auto x: pickups){allPickup+=x;}

    int i=n-1;
    while(1){
        if(allDeliver==0&&allPickup==0){return answer;}

        for(;i>=0;i--){
            if(deliveries[i]!=0||pickups[i]!=0){
                answer+=(i+1)*2;
                int deliver=cap;
                for(int j=i;j>=0;j--){
                    if(deliveries[j]>=deliver){
                        deliveries[j]-=deliver;
                        allDeliver-=deliver;
                        break;
                    }
                    else{
                        deliver-=deliveries[j];
                        allDeliver-=deliveries[j];
                        deliveries[j]=0;
                    }
                }
                deliver=cap;
                for(int j=i;j>=0;j--){
                    if(pickups[j]>=deliver){
                        pickups[j]-=deliver;
                        allPickup-=deliver;
                        break;
                    }
                    else{
                        deliver-=pickups[j];
                        allPickup-=pickups[j];
                        pickups[j]=0;
                    }
                } 
                break;
            }

        }
    }

}
