class Solution{
public:
vector<string>letterCombinations(string digits){
if(digits.empty())return{};
vector<string>mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"},res;
res.push_back("");
for(char d:digits){
vector<string>tmp;
for(string s:res){
for(char c:mp[d-'0']){
tmp.push_back(s+c);
}
}
res=tmp;
}
return res;
}
};