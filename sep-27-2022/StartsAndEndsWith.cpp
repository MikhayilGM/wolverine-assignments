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