#include <iostream>
using namespace std;

// int factorial(int n){
//     if(n==0){
//         return 1;
//     }
//     else
//     {
//         return n*factorial(n-1);
//     }
// }

// int main(){
//     int n;
//     cin>>n;
//     int ans = factorial(n);
//     cout<<ans<<endl;
// }

void ReachHome(int src, int dest){

    cout << "source " << src << endl << "destination " << dest << endl;
    //base case
    if(src == dest){
        cout<< "pahuch gye" <<endl;
        return;
    }

    //processing - ek step aage badhjao
    src++;

    //recursive call
    ReachHome(src,dest);

}

int main(){

    int dest = 10;
    int src = 1;

    ReachHome(src,dest);

    return 0;

}