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