class Solution {
private:
    vector<string> result;
    vector<string> path;
    
    void solve(string s,int index)
    {
        
        if(path.size()==4)
        {
            if(index==s.length())
            {
                string ip=path[0];
            for(int i=1;i<4;i++)
            {
                ip+="."+path[i];
            }
            result.push_back(ip);
            }
            
            return;
        }
        if(index>=s.length())
            return;
        for(int j=1;j<=3;j++)
        {
            if((index+j)>s.length())
                break;
            string seg=s.substr(index,j);
            if(seg.length()>1 && seg[0]=='0')
                continue;
            int value=stoi(seg);
            if(value>255)
                continue;
            path.push_back(seg);
            solve(s,index+j);
            path.pop_back();
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        int index=0;
        solve(s,0);
        return result;
    }
};