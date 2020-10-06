/* Shivam Kumar 
  IES College of technology,Bhopal
  
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,m=0,h=nums.size()-1;
        while(m<=h)
        {
            if(nums[m]==0)
            {
                swap(nums[m],nums[l]);
                m++;l++;
            }
            else if(nums[m]==1) m++;
            else
            {
                swap(nums[h],nums[m]);
                h--;
            }
        }   
    }
};

int main()
{
  
  int n;
  cin>>n;
  vector<int>v;
  for(int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    v.push_back(x);
  }
  Solution ob;
  ob.sortColors(v);
  for(auto i:v)
    cout<<i<<" ";
  return 0;
}
