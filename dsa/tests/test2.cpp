priority_queue<pair<int,char>> pq;
if(a) pq.push({a,'a'});
if(b) pq.push({b,'b'});
if(c) pq.push({c,'c'});

string ans="";
while(!pq.empty())
{
    int x=0,y=0;
    pair<int,char> p=pq.top();
    pq.pop();
    if(pq.empty())
    {
        if(ans.length()>0 && ans[ans.length()-1]==p.second)
            break;
    }
    if(p.first>0)
    {
        for(int i=0;i<min(2,p.first);i++)
        {
            x++;
            ans+=p.second;
        }
    }
    if(!pq.empty())
    {
        pair<int,char> q=pq.top();
        pq.pop();
        
        if(q.first>0)
        {
            int tmp=min(2,q.first);
            if(tmp>1 && p.first-x>q.first)
                tmp=1;
            for(int i=0;i<tmp;i++)
            {
                y++;
                ans+=q.second;
            }
        }
        if(q.first-y>0)
            pq.push({q.first-y,q.second});
    }
    if(p.first>x)
        pq.push({p.first-x,p.second});
}
return ans;