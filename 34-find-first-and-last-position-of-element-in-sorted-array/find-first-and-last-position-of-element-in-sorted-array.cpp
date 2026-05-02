class Solution{
public:
int l(vector<int>&a,int t){
int s=0,e=a.size()-1,ans=-1;
while(s<=e){
int m=(s+e)/2;
if(a[m]>=t){
if(a[m]==t)ans=m;
e=m-1;
}else s=m+1;
}
return ans;
}
int r(vector<int>&a,int t){
int s=0,e=a.size()-1,ans=-1;
while(s<=e){
int m=(s+e)/2;
if(a[m]<=t){
if(a[m]==t)ans=m;
s=m+1;
}else e=m-1;
}
return ans;
}
vector<int> searchRange(vector<int>&a,int t){
return {l(a,t),r(a,t)};
}
};