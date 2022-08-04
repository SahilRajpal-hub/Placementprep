HashMap<Integer, Integer> pfs = new HashMap<Integer, Integer>();
int ans = 0;

int[] first = new int[A.length + 1];
first[0] = 0;

pfs.put(0, 1);

int[] second = new int[A.length + 1];
second[0] = 0;

for (int i = 1; i < A.length + 1; i++)
{
    first[i] = first[i - 1] + A[i - 1];
    second[i] = first[i] - S * i;

    if (!pfs.containsKey(second[i]))
    {
        pfs.put(second[i], 1);
    }
    else
    {
        Integer tmp = pfs.get(second[i]);
        tmp++;
        pfs.put(second[i], tmp);
    }
}
for (Map.Entry<Integer, Integer> entry : pfs.entrySet())
{
    int tmp = entry.getValue();
    ans += tmp * (tmp - 1) / 2;
}

return ans;




    int rb = 0;
    for (char ch : S) {
        if (ch == 'R') ++rb;
    }
    int l = 0, rp = S.size() - 1;
    int res = 0;
    while (l < rp) {
        if (S[l] == 'R' && S[rp] == 'R') {
            rb -= 2;
            res += rp - l - 1 - rb;
            ++l;
            --rp;
        } 
        else if (S[l] != 'R') {
            ++l;
        } 
        else {
            --rp;
        }
    }
    return res;


List<Integer> ri = new ArrayList<>();
        for(int i=0; i<S.length(); i++){
            if(S.charAt(i)=='R') ri.add(i);
        }
        int ans=0;
        int m=ri.size()/2;
        for(int i=0; i<ri.size(); i++){
            ans += Math.abs(ri.get(m)-ri.get(i))-Math.abs(m-i);
        }
        return ans;




        
