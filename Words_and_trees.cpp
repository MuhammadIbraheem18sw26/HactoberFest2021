/*Words and Trees is a problem from Hackerearth. The following is the sollution.*/

    #include<iostream>
    #include<vector>
     
     
    #define vi vector<int> 
    #define vii vector<vector<int> > 
    #define pb push_back
     
    #define pr std::pair
    #define mp std::make_pair
    #define ff first
    #define ss second
     
    #define ll long long
     
    #define foc(i,st) for(i=0;st[i]!=NULL;i++)
    #define fo(k,n) for(k=0;k<n;k++)
     
    using namespace std;
     
    int src(string a,char b){
    	int i,t= -1;
    	fo(i,a.size()){
    		if(a[i]==b)
    		{
    			t=i;
    		break;
    		}
    	}
    	return t;
     
    }
     
     
    void dfs(vi v[],int lvl,int r[],int node){
    	r[node]=lvl;
    	int i;
    	fo(i,v[node].size()){
    		if(r[v[node][i]]==0)
    		dfs(v,lvl-1,r,v[node][i]);
    	}
    }
     
    void gr_cnt(vi v[],int x,string &s,char a[],int r[]){
    	
    	int k=src(s,a[x]);
    	if(k!=-1)
    	s.erase(s.begin()+k);
    	fo(k,v[x].size()){
    		if(r[v[x][k]]<r[x])
    		gr_cnt(v,v[x][k],s,a,r);
    	}
    }
     
    int main()
    {
    int i,n,q,a,b,vis[100001];
    char list[100001];
    string str;
    vi gr[100001];
    cin>>n>>q;
    fo(i,n)
    cin>>list[i+1];
    fo(i,n-1){
    	cin>>a>>b;
    	gr[a].pb(b);
    	gr[b].pb(a);
    }
     
     
    dfs(gr,100005,vis,1);
     
     
    fo(i,q){
    	cin>>a>>str;
    	gr_cnt(gr,a,str,list,vis);	
    	cout<<str.size()<<"\n";
    }
     
     
    }
