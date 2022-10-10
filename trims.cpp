// rtrim(s); որը վերադարձնում է տողը առանց աջից բացատների, այսինքն rtrim("hello   "); կվերադարձնի "hello"
// ltrim(s); որը վերադարձնում է տողը առանց ձախից բացատների, այսինքն ltrim("   hello"); կվերադարձնի "hello"
// trim(s); որը վերադարձնում է տողը առանց ձախից և աջից բացատների trim("  hello  "); կվերադարձնի "hello"
// split(s, d); որը կվերադարձնի տողերի զանգված, որտեղ յուրաքանչյուր տող ստացվել է s տողը կտրտելով ըստ տրված d բաժանիչների, այսինքն՝ split("he,ll,o", ","); կվերադարձնի ["he", "ll", "o"], իսկ split("he ,ll:o world,vui", " ,:"); կվերադարձնի ["he", "ll", "o", "world", "vui"]։ Փոխանցվող բաժանիչների քանակի սահմանափակում չկա։
// toUpperCase(s); վերադարձնում է տողը բոլոր տառերը մեծատառ փոխված
// toLowerCase(s); վերադարձնում է տողը բոլոր տառերը փոքրատառ փոխված
// startsWith(s, t); վերադարձնում է true, եթե s տողը սկսվում է t ենթատողով, օրինակ՝ startsWith("hello, world", "hell"); վերադարձնում է true, իսկ startsWith("hello, world", "world"); վերադարձնում է false։
// endsWith(s, t); վերադարձնում է true, եթե s տողը վերջանում է t ենթատողով
// replaceAll(s, t, r); վերադարձնում է s տողի փոփոխված տարբերակը, որտեղ յուրաքանչյուր հանդիպած t ենթատող փոխարինվել է r ենթատողով, օրինակ՝ replaceAll("hello, world", "l", "ch"); կվերադարձնի "hechcho, worchd"։

#include <cstring>
#include <vector>
#include <iostream>

std::string rtrim(const std::string& str)
{
    std::string tmp;
    tmp.resize(str.size());
    int q = 0; 
    for(int i = str.size() - 1; i >= 0; --i)
    {
        if(str[i] == ' ')
        {
            ++q;
        }
        else 
        {
            break;
        }
    }

    for(int i = 0; i < str.size() - q; ++i)
    {
        tmp[i] = str[i];
    }
    return tmp;
}

std::string ltrim(const std::string& str)
{
    std::string tmp;
    tmp.resize(str.size());
    
    for(int i = 0,  q = 0; i < str.size(); ++i)
    {
        if(str[i] != ' ')
        {
            tmp[q] = str[i];
            ++q;
        }
    }

    return tmp;
}

std::string trim(const std::string& str)
{
    std::string tmp;
    tmp.resize(str.size());

    
    int q = 0;

    for(int i = str.size() - 1; i >= 0; --i)
    {
        if(str[i] == ' ')
        {
            ++q;
        }
        else 
        {
            break;
        }
    }

    for(int i = 0,  k = 0; i < str.size() - q; ++i)
    {
        if(str[i] != ' ')
        {
            tmp[k] = str[i];
            ++k;
        }
    }

    return tmp;
}

std::vector<std::string> split(const std::string& str, const std::string& spliter)
{
    std::vector<std::string> vec;
    std::string tmp;

    for(size_t i = 0; i < str.size(); i++)
    {
        bool smt = 1;
        for (size_t j = 0; j < spliter.size(); j++)
        {
            if(spliter[j] == str[i])
            {
                vec.push_back(tmp);
                tmp.clear();
                smt = 0;
            }
        }

        if(smt)
        {
            tmp.push_back(str[i]);
        }
    }

    vec.push_back(tmp);

    return vec;
}   

void toUpperCase(std::string& str)
{
    std::cout << str;

    for (size_t i = 0; i < str.size(); i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32; 
        } 
    }

    std::cout << str;
    
}

void toLowerCase(std::string& str)
{
    std::cout << str;

    for (size_t i = 0; i < str.size(); i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32; 
        } 
    }

    std::cout << str;
    
}

bool startsWith(const std::string& str, const std::string& diff)
{
    if(diff.size() > str.size())
    {
        return false;
    }

    for (size_t i = 0; i < diff.size(); i++)
    {
        if(str[i] != diff[i])
        {
            return false;
        }
    }

    return true; 
}

bool endsWith(const std::string& str, const std::string& diff)
{
    if(diff.size() > str.size())
    {
        return false;
    }

    for (size_t i = 0; i < diff.size(); i++)
    {
        if(str[str.size()-i-1] != diff[diff.size()-i-1])
        {
            return false;
        }
    }

    return true; 
}

std::string replaceAll(const std::string& str, const std::string& t, const std::string& r)
{
    std::string tmp = str;
    for (size_t i = 0; i < tmp.size(); ++i)
    {
        int random = i;
        for (size_t j = 0; j < t.size(); ++j)
        {
            if(tmp[i] == t[j])
            {
                ++i;
            }
            else
            {
                random = (-1); 
                continue;
            }
        }

        if(random + 1)
        {
            tmp.erase(random, t.size());
            tmp.insert(random, r);
            i += r.size();
        }
        
    }
    
    return tmp;
}

int main()
{
    std::cout << replaceAll("gg arm gg kill", "gg", "ggggggggggggg");
    return 0;
}