// #include <iostream>
// #include <vector>
// using namespace std;

// bool searchMatrix(vector<vector<int>> &matrix, int target){

//     int rows=matrix.size();
//     int cols=matrix[0].size();

//     int s=0;
//     int e=rows*cols-1;    

//     int mid=s+(e-s)/2;    

//     while(s<=e){    

//         int element=matrix[mid/cols][mid%cols];

//         if(element==target){
//             return 1;
//         }
//         else if(element<target){
//             s=mid+1;
//         }
//         else{
//             e=mid-1;
//         }
//         mid=s+(e-s)/2;
//     }
//     return 0;

// }

// #include <iostream>
// using namespace std;

// int main() {
//     int a[10] = {1, 2, 3, 4, 5, 6, 7, 8};
//     int p = (a + 1)[5];
//     cout << p;
//     return 0;
// }

//A functor is a class or struct that overloads operator(), allowing objects to be called like functions. They are widely used in STL algorithms like sort() to define custom comparison criteria

