class Solution {
public:
    bool checkASCII(char ch){
        return ((ch >= 65 && ch <= 70) || (ch >= 97 && ch <= 102));
    }
    bool checkNum(char ch){
        int n = ch - '0';
        return (n <= 9 && n >= 0);
    }
    string checkIPv4(string IP){
        if(IP.length() > 15){
            return "Neither";
        }
        bool ans = true;
        int count = 0;
        for(int i = 0;i < IP.length();i++){
            int num = 0;
            count++;
            int j = i;
            for(;IP[j] != '.' && IP[j] !='\0';j++){
                if(checkNum(IP[j])){
                    num = num * 10 + (IP[j] - '0');
                }else{
                    ans = false;
                    break;
                }
            }
            if(num >= 256 || num < 0 || (j-i == 0) || (j-i > 1 && IP[i] == '0') || (count > 4) || (count == 4 && IP[j] != '\0')){
                ans = false;
                break;
            }
            i = j;
        }
        if(count < 4){
            ans = false;
        }
        return ans ? "IPv4" : "Neither";
    }
    string checkIPv6(string IP){
        if(IP.length() > 39){
            return "Neither";
        }
        int count = 0;
        bool ans = true;
        for(int i = 0;i < IP.length();i++){
            int num = 0;
            count++;
            int j = i;
            for(;IP[j] != ':' && IP[j] != '\0';j++){
                if(!checkASCII(IP[j]) && !checkNum(IP[j])){
                    ans = false;
                    break;
                }
                //cout<<IP[j]<<" ";
                num++;
            }
            if(num > 4 || num == 0 || count > 8 || (count == 8 && IP[j] != '\0')){
                ans = false;
                break;
            }
            i = j;
        }
        if(count < 8){
            ans = false;
        }
        return ans ? "IPv6" : "Neither";
    }
    string validIPAddress(string IP) {
        if(IP.find('.') != string::npos){
            return checkIPv4(IP);
        }else{
            return checkIPv6(IP);
        }
    }
};
