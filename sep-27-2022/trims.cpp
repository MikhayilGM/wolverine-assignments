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