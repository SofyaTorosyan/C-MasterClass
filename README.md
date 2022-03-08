# C++-MasterClass
1. HugeInt project \
Implement a class which enables us to store and make arithmetic operations upon integers of huge sizes (several hundreds of digits long).


Here is the class interface:
class HugeInt
{
public:
     HugeInt(std::string value);
     HugeInt(int value);
     HugeInt operator + (const HugeInt & arg) const;
     HugeInt operator * (const HugeInt & arg) const;   
};
