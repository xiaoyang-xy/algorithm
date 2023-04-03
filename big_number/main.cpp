#include <iostream>
#include <vector>
#include <string>
using namespace std;


vector<int> add(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || i < B.size(); i++)
    {
        if (i < A.size()) t += A[i];
        if (i < B.size()) t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if(t) C.push_back(1);
    return C;
}
bool cmp(vector<int> &A, vector<int> &B)
{
    if (A.size() != B.size()) return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; i -- )
    {
        if (A[i] != B[i]) return A[i] > B[i];
        
    }
    return true;
}
vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++)
    {
        t = A[i] - t;
        if (i < B.size()) t -= B[i];
        C.push_back((t + 10)%10);
        if (t < 0) t = 1;
        else t = 0;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    
    return C;
}

vector<int> mul(vector<int> &A, int B)
{
    vector<int> C;
    
    long t = 0;
    for (int i = 0; i < A.size() || t; i++)
    {
        if(i < A.size())t += A[i] * B;
        C.push_back(t % 10);
        t /= 10;
    }
    
    return C;
}

vector<int> div(vector<int> &A, int &B, int &r)
{
    vector<int> C;
    r = 0;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        r = r * 10 + A[i];
        C.push_back(r / B);
        r %= B;
    }
    reverse(C.begin(),C.end());
    while (C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}


int main()
{
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
    vector<int> C = add(A, B);

    for (int i = C.size() -1; i >= 0; i--)
    {
        printf("%d",C[i]);
    }
    printf("\n");
    if(cmp(A,B))
    {
        vector<int> D = sub(A, B);

        for (int i = D.size() -1; i >= 0; i--)
        {
            printf("%d",D[i]);
        }
    }
    else
    {
        vector<int> D = sub(B, A);
        printf("-");
        for (int i = D.size() -1; i >= 0; i--)
        {
            printf("%d",D[i]);
        }
    }
    return 0;
}