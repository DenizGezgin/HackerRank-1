#include <iostream>

using namespace std;

int divisorSum(int start,int end)
{
    int sumCurr, sum = 0;
    for(int num = start; num < end; num++)
    {
        sumCurr = 1;
        for(int i = 2; i*i < num; i++)
        {
            if(num%i == 0)
            {
                sumCurr += i;
            }
        }
        if(sumCurr > num)
            sum+= (sumCurr-num);
        else
            sum += (num-sumCurr);
    }
    return sum;
}


 
int main() {
    int A, B;
    cin >> A >> B;

    cout << divisorSum(A,B);
    return 0;
}