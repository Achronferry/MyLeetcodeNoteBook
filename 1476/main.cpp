#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        map<int,int> sol_map;
        int bg=-1,ed=-1,cnt=0;
        for (int idx=0;idx<array.size();idx++)
        {
            if (array[idx][0]>='0' and array[idx][0]<='9')
                cnt++;
            else
                cnt--;

            if (cnt==0 and idx>=ed-bg+1)
            {
                bg=-1;
                ed=idx;
            }
            map<int ,int>::iterator ptr;
            ptr = sol_map.find(cnt);
            if (ptr==sol_map.end())
                sol_map[cnt] = idx;
            else if (idx-sol_map[cnt] > ed-bg)
            {
                ed=idx;
                bg=sol_map[cnt];
            }
        }

        vector<string> result;
        for (int i=bg+1;i<=ed;i++)
            result.push_back(array[i]);
        return result;
    }
};
int main()
{
    vector<string> a(3,"A");
    a.push_back("1");
    a.push_back("2");
    a.push_back("B");
    Solution s;
    for (int i=0;i<a.size();i++)
        cout<<a[i];
    cout<<endl;

    vector<string> b;
    b=s.findLongestSubarray(a);

    for (int i=0;i<b.size();i++)
        cout<<b[i];

    return 0;
}
