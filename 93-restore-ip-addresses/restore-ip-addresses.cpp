class Solution {
public:
    bool isvalid(string str){
        if(str == "")
        return false;

        int num = stoi(str);
        if(str.size() > 3 || num > 255 || (str.size() > 1 && str[0] == '0'))
        return false;
        return true;
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int n = s.size();
        if(n < 4 || n > 12)
        return ans;

        for(int i = 0; i<3 && i<n; i++){
            for(int j = i+1; j<i+4 && j<n; j++){
                for(int k = j+1; k<j+4 && k<n; k++){
                    int l = k+1;
                    string str = "", temp = "";
                    int num;

                    temp = s.substr(0,i+1);
                    if(!isvalid(temp)){
                        continue;
                    }else{
                        str += temp;
                        str += ".";
                    }

                    temp = s.substr(i+1,j-i);
                    if(!isvalid(temp)){
                        continue;
                    }else{
                        str += temp;
                        str += ".";
                    }

                    temp = s.substr(j+1,k-j);
                    if(!isvalid(temp)){
                        continue;
                    }else{
                        str += temp;
                        str += ".";
                    }
                    
                    temp = s.substr(k+1,n-k);
                    if(!isvalid(temp)){
                        continue;
                    }else{
                        str += temp;
                    }
                    ans.push_back(str);
                }
            }
        }
        return ans;
    }
};