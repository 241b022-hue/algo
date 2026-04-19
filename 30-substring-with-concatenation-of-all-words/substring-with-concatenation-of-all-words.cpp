class Solution{
public:
vector<int> findSubstring(string s,vector<string>& words){
vector<int> ans;
int n=words.size(),len=words[0].size(),total=n*len;
unordered_map<string,int> mp;
for(string w:words)mp[w]++;
for(int i=0;i<len;i++){
unordered_map<string,int> seen;
int left=i,count=0;
for(int j=i;j+len<=s.size();j+=len){
string word=s.substr(j,len);
if(mp.count(word)){
seen[word]++;
count++;
while(seen[word]>mp[word]){
string t=s.substr(left,len);
seen[t]--;
left+=len;
count--;
}
if(count==n){
ans.push_back(left);
string t=s.substr(left,len);
seen[t]--;
left+=len;
count--;
}
}else{
seen.clear();
count=0;
left=j+len;
}}}
return ans;
}};