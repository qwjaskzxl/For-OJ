#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn=1000000;
struct Node{
    int address,data,next;
}node[maxn];
vector<Node> list1,list2;
int begin1,begin2,n;

int main(){
    cin>>begin1>>begin2>>n;
    int address;
    for(int i=0;i<n;i++){
        cin>>address;
        cin>>node[address].data>>node[address].next;
        node[address].address=address;
    }
    for(int now=begin1;now!=-1;now=node[now].next){
        list1.push_back(node[now]);
    }
    for(int now=begin2;now!=-1;now=node[now].next){
        list2.push_back(node[now]);
    }
    if(list2.size()>=2*list1.size()){
        vector<Node> tmp;
        tmp=list2;
        list2=list1;
        list1=tmp;
    }
    vector<Node> res;
    
    for(int i=0,j=list2.size()-1;;){
        if(i<list1.size())  res.push_back(list1[i++]);
        if(i<list1.size())  res.push_back(list1[i++]);
        if(j>=0) res.push_back(list2[j--]);
        if(i>=list1.size() && j<0) break;
    }
    int i=0;
    for(;i<res.size()-1;i++){
        printf("%05d %d %05d\n",res[i].address,res[i].data,res[i+1].address);
    }
    printf("%05d %d %d",res[i].address,res[i].data,-1);
    return 0;

}

