int findMinimumCoins(int amount) 
{
    int currency[] = {1000,500,100,50,20,10,5,2,1};
    
    int i=0, count=0;
    int value=amount;
    while(value) {
        if(value >= currency[i]) {
            count += value/currency[i];
            value=value%currency[i];
        }
        i++;
    }
    
    return count;
}
