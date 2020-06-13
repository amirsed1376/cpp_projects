#include<iostream>
using namespace std;

int main ()
{
    string s;
    int n;
    cin>>s;
    while(true)
    {
        cin>>n;
        for(int i=0;s[i]!=nullptr;i++)
        {   int k=1;
            int sum=0;
            for(int j=i;(s[i]==s[j])&&(j>=0) ;j--)
                if(s[i]==s[j])
                {
                    sum+=s[i]-'a';
                    if(sum==n);
                    k=0;
                }
            if (k)
            {
                for(int m=j;m<=i;m++)
                    delete s[m];
            }

        }
        cout<<s;
    }
}
