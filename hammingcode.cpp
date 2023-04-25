#include<bits/stdc++.h>
using namespace std;
int main(){
    string s = "10101101110";
    cout << "RECEIVED SIGNAL: " << s << endl;
    reverse(s.begin(), s.end());

    int n = ceil(log2(s.length()));
    vector<int> parity;
    for(int i = 0; i < n; i++){
        int p = 0;
        int skip = pow(2, i);
        int j = skip-1;
        while(j < s.length()){
            for(int k=1; k<=skip && j<s.size(); k++){
                p^=(s[j]-'0');
                j++;
            }
            j+=skip;
        }
        parity.push_back(p);
    }
    string check = "";
    for(auto x: parity){
        check += to_string(x);
    }
    reverse(check.begin(), check.end());
    int ans = stoi(check, 0, 2);
    if(ans == 0)
        cout << "NO ERROR DETECTED" << endl;
    else{
        cout << "ERROR DETECTED AT POSITION: " << ans << endl;
    }

    return 0;
}
