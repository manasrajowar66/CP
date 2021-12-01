//https://www.hackerearth.com/challenges/competitive/code-monk-heaps-and-priority-queues-1/algorithm/little-monk-and-williamson/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lli long long int
#define ll long long
#define vec vector<int>
#define for0() for (int i = 0; i < n; i++)
#define for1() for (int i = 1; i <= n; i++)
#define backloop() for (int i = n - 1; i >= 0; i--)
#define tci() \
    int t;    \
    cin >> t; \
    while (t--)
#define endl "\n"
#define Mod 1000000007
int power(int, int);
bool isPrime(int);

class Monk_queue
{
private:
    priority_queue<int> pqs;

public:
    int count_high()
    {
        priority_queue<int> pq = this->pqs;
        if (pq.size() == 0)
            return -1;
        int top_element = pq.top();
        map<int, int> hash;
        if (pq.size() != 0)
        {
            hash[pq.top()] += 1;
            pq.pop();
        }
        for (auto x : hash)
        {
            cout << x.first << " " << x.second << " ";
        }
        return hash[top_element];
    }

    int cal_diff()
    {
        if (this->pqs.size() == 0)
            return -1;
        if (this->pqs.size() == 1)
        {
            this->pqs.pop();
            return 0;
        }
        int size = this->pqs.size();

        int first_element = this->pqs.top();
        int last_element = this->pqs.top();
        this->pqs.pop();
        priority_queue<int> temp;

        while (this->pqs.size() != 0)
        {
            last_element = this->pqs.top();
            if (this->pqs.size() > 1)
            {
                temp.push(this->pqs.top());
            }
            this->pqs.pop();
        }
        if (first_element == last_element)
        {
            while (temp.size() <= size - 1)
            {
                temp.push(first_element);
            }
        }
        this->pqs = temp;
        return first_element - last_element;
    }

    int count_low()
    {
        priority_queue<int> pq = this->pqs;
        if (pq.size() == 0)
        {
            return -1;
        }
        unordered_map<int, int> hash;
        int last_element;
        while (pq.size() != 0)
        {
            last_element = pq.top();
            hash[last_element]++;
            pq.pop();
        }
        return hash[last_element];
    }

    void push(int x)
    {
        this->pqs.push(x);
        cout << "Current Elements ";
        priority_queue<int> pq = this->pqs;
        while (pq.size() != 0)
        {
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << endl;
    }
};

signed main()
{
    Monk_queue pq;
    tci()
    {
        string s;
        cin >> s;
        if (s == "CountHigh")
        {
            cout << pq.count_high() << endl;
        }
        if (s == "Push")
        {
            int x;
            cin >> x;
            pq.push(x);
        }
        if (s == "Diff")
        {
            cout << pq.cal_diff() << endl;
        }
        if (s == "CountLow")
        {
            cout << pq.count_low() << endl;
        }
    }
    return 0;
}

// My Functions //

int power(int a, int n)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            res = (res * a);
            n--;
        }
        else
        {
            a = (a * a);
            n /= 2;
        }
    }
    return res;
}

bool isPrime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
