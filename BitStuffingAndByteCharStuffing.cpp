//bit
#include <bits/stdc++.h>
using namespace std;

vector<int> bitStuffing(vector<int> &arr)
{
   int i = 0;
   int count = 0;
   vector<int> ans;
   
   while (i < arr.size()){
        while (i < arr.size() && arr[i] == 1 && count < 5){
           ans.emplace_back(arr[i++]);
           count++;
        }
        if (count == 5)
           ans.emplace_back(0);
        if (arr[i] == 0){
           ans.emplace_back(arr[i]);
           i++;
        }      
        count = 0;
   }
   return ans;
}

int main()
{
   int n;
   cout << "Enter the size of the array: ";
   cin >> n;
   vector<int> arr(n);
   cout << "Enter the elements in the array: ";
   for (int i = 0; i < n; i++)
   {
       cin >> arr[i];
   }
   cout << "Before Bit Stuffing: ";
   for (int i = 0; i < n; i++)
   {
       cout << arr[i] << "  ";
   }
   cout << endl;
   arr = bitStuffing(arr);
   cout << "After Bit Stuffing: ";
   for (int i = 0; i < arr.size(); i++)
   {
       cout << arr[i] << "  ";
   }
   cout << endl;
   return 0;
}


// //byte
// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     cout << "Flag byte Sequence: f\n";
//     cout << "Escape byte Sequence: e\n";
//     char flag = 'f';
//     char escape = 'e';
//     string oM;
//     cout << "Message to be sent : ";
//     getline(cin, oM);

//     string sM = "f";
//     for (int i = 0; i < oM.length(); i++)
//     {
//         if (oM[i] == flag){
//             sM += escape;
//             sM += flag;
//         }
//         else if (oM[i] == escape){
//             sM += escape;
//             sM += escape;
//         }
//         else{
//             sM += oM[i];
//         }
//     }
//     sM += flag;
//     cout << "\nencoded message : " << sM << endl
//          << endl;
//     string rM = "";

//     for (int i = 1; i <= (sM.length() - 2); i++){
//         if (sM[i] == escape) {
//             if (sM[i + 1] == flag)
//                 continue;
//             else{
//                 rM += escape;
//                 i++;
//             }
//         }
//         else{
//             rM += sM[i];
//         }
//     }
//     cout << "decoded message is: " << rM << endl;
//     return 0;
// }
