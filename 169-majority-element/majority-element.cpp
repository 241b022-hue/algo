class Solution{
public:
int majorityElement(vector<int>&a){
int c=0,x=0;
for(int i=0;i<a.size();i++){
if(c==0)x=a[i];
if(a[i]==x)c++;
else c--;
}
return x;
}
};