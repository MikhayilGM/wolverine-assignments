void toUpperCase(std::string& str)
{

    for (size_t i = 0; i < str.size(); i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32; 
        } 
    }
    
}

void toLowerCase(std::string& str)
{

    for (size_t i = 0; i < str.size(); i++)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32; 
        } 
    }
    
}