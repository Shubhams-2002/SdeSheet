#include <bits/stdc++.h>
int tour(petrolPump p[],int n)
    {
      int start=0;// front=0, rear=0;
      int balance=0, deficit=0;
      for(int i=0; i<n; i++) {
          balance = balance + p[i].petrol - p[i].distance;
          if(balance < 0) {
              start = i+1;
              deficit += balance;
              balance = 0;
          }
      }
       
      if(deficit + balance >= 0) return start;
      return -1;
    }