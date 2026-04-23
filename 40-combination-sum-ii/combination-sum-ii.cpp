class Solution{
public:
vector<vector<int>>res;
void f(int i,vector<int>&c,int t,vector<int>&v){
if(t==0){res.push_back(v);return;}
for(int j=i;j<c.size();j++){
if(j>i&&c[j]==c[j-1])continue;
if(c[j]>t)break;
v.push_back(c[j]);
f(j+1,c,t-c[j],v);
v.pop_back();
}}
vector<vector<int>>combinationSum2(vector<int>&c,int t){
sort(c.begin(),c.end());
vector<int>v;
f(0,c,t,v);
return res;
}};