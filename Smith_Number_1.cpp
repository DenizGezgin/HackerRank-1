#include <iostream>
#include <vector>

using namespace std;

struct node
{
unsigned long int value;
node* next;

//constructor
node::node(int n, node* nextNode)
	:value(n), next(nextNode)
{	
}

};


unsigned long int sumDigits(unsigned long  int n)
{
    if(n == 0)
        return 0;
    else
    {   
        return n%10 +sumDigits(n/10);
    }
}

bool tryDivide(node &head,unsigned long int n){
    if(*head == NULL)
        *head = new node(n, NULL);
        return true;
    while(temp->next != NULL)
    {
        if(n%temp->value ==0)
            return false;
        temp = temp->next;
    }
    temp->next = new node(n, NULL);
    return true;
}

unsigned long int sumPrimeFactorDigits(unsigned long int n)
{
    unsigned long int sum = 0, total,factors = 1;
    node *head = NULL;

    for(unsigned long int i = 2; i*i < n; i++)
    {
        if(n%i == 0) //if found not crossed value
        {   
            if(tryDivide(head,i)){
                
                total = 0;
                unsigned long int power = i;
                while(n % power == 0)
                {
                    total++;
                    power *= i;
                }
                
                if (total != 0)
                {
                    sum += sumDigits(i)*total;
                    factors *= (power/i);
                }
            }
        }
    }
        if(factors != n)
            sum += sumDigits(n/factors);
        return sum;
}

 
int main() {

    unsigned long int n;
    cin >> n;
    if(sumPrimeFactorDigits(n) == sumDigits(n))
        cout << 1;
    else
        cout << 0;

    return 0;
}