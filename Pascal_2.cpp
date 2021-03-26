#include <iostream>

using namespace std;

const int MAX_MOD = 1e9 + 7;


unsigned long long int exp_by_squaring(long long int x, long long int n) {
    if (n == 0)
        return 1;
    if (n%2 == 1) 
        return (x*exp_by_squaring(x, n-1))%MAX_MOD;

    long long int temp = exp_by_squaring(x, n/2);
    return (temp*temp)%MAX_MOD;
}



 
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    unsigned long long int T,N,result;
    cin >> T;
    for (int i = 0; i < T; i++){
        cin >> N;
        result = (exp_by_squaring(2,N) - 1)%MAX_MOD;
        cout << result << endl;
    }
    return 0;
}