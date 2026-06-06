#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Encoding_Decoding
{
    public:
    string encoding(vector<string> &str)
    {
        string res = "";
        for (string& s : str)
        {
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    vector<string> decoding(string str)
    {
        int i = 0;
        vector<string> res;
        while (i < str.size())
        {
            int j = i;
            while(str[j]!='#'){
                ++j;
            }
            int len = stoi(str.substr(i, j - i));
            ++j;
            string s = str.substr(j, len);
            res.push_back(s);
            i = j + len;
        }
        return res;
    }
};

int main(){
    Encoding_Decoding ed;
    vector<string> strs = {"Prayag", "Sahu"};
    string encode = ed.encoding(strs);
    // cout << encode;
    vector<string> decode = ed.decoding(encode);
    cout << "[";
    for(string ans : decode){
        cout << "[" << ans << "],";
    }
    cout << "]";
}