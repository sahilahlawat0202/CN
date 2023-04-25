#include<bits/stdc++.h>
using namespace std;

string DecimalToBinary(int num)
{
    string str;
    while(num){
        if(num & 1)
            str+='1';
        else 
            str+='0';
        num>>=1; 
    }   
    reverse(str.begin(),str.end());
    return str;
}

string complement(string a){
    string s = "";
    for(int i = 0; i < a.length(); i++){
        if(a[i] == '0')
            s += '1';
        else
            s += '0';
    }
    return s;
}
string addBinary(string a, string b){
    int sum = stoi(a,0,2) + stoi(b,0,2);
    return DecimalToBinary(sum);
}

string checksum(string data, int block_size){
    string sum = "0";
    int i = 0;
    while(i < data.length()){
        string block = data.substr(i, block_size);
        sum = addBinary(sum, block);
        if(sum.length() > block_size){
            sum = sum.erase(0,1);
            sum = addBinary(sum, "1");
        }
        i += block_size;
    }
    while(sum.length() < block_size)
        sum = "0" + sum;
    sum = complement(sum);
    return sum;
}

int main(){
    string data;
    cout << "Enter data: ";
    getline(cin, data);
    int block_size;
    cout << "Enter block size: ";
    cin >> block_size;
    string checksum_data = checksum(data, block_size);
    cout << "Checksum: " << checksum_data << endl;
    return 0;
}
