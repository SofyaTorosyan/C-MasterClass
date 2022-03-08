#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/* Let's keep our huge integer in the string and work with strings instead of huge integers */
class HugeInt
{
public:
    HugeInt(std::string value);
    HugeInt(int value);
    HugeInt operator + (const HugeInt & arg) const;
    HugeInt operator * (const HugeInt & arg) const;
    friend ostream &operator<<(ostream &out,const HugeInt &a);
private:
    std::string m_str;
};

HugeInt::HugeInt(int value)
{
    m_str = std::to_string(value);
    std::reverse(m_str.begin(), m_str.end()); /* reversed string will be convinient for our use. */
    std::cout << m_str << std::endl;
}
HugeInt::HugeInt(std::string value)
{
    m_str = value;
    std::reverse(m_str.begin(), m_str.end()); /* reversed string will be convinient for our use. */
}

ostream &operator<<(ostream &out,const HugeInt &a){
    for (int i = a.m_str.size() - 1; i >= 0; i--)
        cout << (short)a.m_str[i];
    return cout;
}

HugeInt HugeInt::operator+ (const HugeInt& arg) const
{
    HugeInt res(*this);
    int carry = 0;
    int sum   = 0;
    unsigned int i = 0;
    if(arg.m_str.size() > res.m_str.size()) {
        res.m_str.append((arg.m_str.size() - res.m_str.size()), 0 + '0');
    }
    for (; i < arg.m_str.size() && i < res.m_str.size(); i++) { 
        int s1 = res.m_str[i] - '0';
        int s2 = arg.m_str[i] - '0'; 
        sum = s1 + s2 + carry;
        carry = sum / 10;
        sum %= 10;
        res.m_str[i] = (char)sum + '0';
    }
    if(carry) 
    {
        if(i < res.m_str.size())
        {
            res.m_str[i] = res.m_str[i] + carry;
        }
        else if(i < arg.m_str.size())
        {
            res.m_str.append(std::to_string(arg.m_str.size() + carry));
        }
        res.m_str.append(std::to_string(carry));
    }
    std::cout << "result of " << (*this).m_str << " + " << arg.m_str << " is: " << res.m_str << std::endl;
    return res;
}

HugeInt HugeInt::operator* (const HugeInt& arg) const
{
    HugeInt res(*this);
    int n = res.m_str.size(), m = arg.m_str.size();
    res.m_str.resize(n + m);
    int carry = 0;
    int mult = 0;
    
    vector<int> vec(n + m, 0);
    for (int i = 0; i < n;i++)
        for (int j = 0; j < m;j++) {
            int s1 = res.m_str[i] - '0';
            int s2 = arg.m_str[j] - '0';
            vec[i + j] += s1 * s2;
        }
    for(unsigned int i = 0; i < vec.size(); i++) {
        mult = vec[i] + carry;
        carry = mult / 10;
        mult %= 10;
        char c = (char)mult + '0';
        res.m_str[i] = c;
    }
    res.m_str.pop_back();
    std::cout << "result of " << (*this).m_str << " * " << arg.m_str << " is: " << res.m_str << std::endl;
    return res;
}

int main()
{
    HugeInt h1(112);
    HugeInt h2(12);
    h1 * h2; /*results and input numbers are printed in reverse order*/
}