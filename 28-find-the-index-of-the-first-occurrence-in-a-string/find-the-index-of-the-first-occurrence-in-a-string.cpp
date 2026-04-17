class Solution{
public:
int strStr(string h,string n){
int m=h.size(),k=n.size();
for(int i=0;i<=m-k;i++){
int j=0;
while(j<k&&h[i+j]==n[j])j++;
if(j==k)return i;
}
return -1;
}
};