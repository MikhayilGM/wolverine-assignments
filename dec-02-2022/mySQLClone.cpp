#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

enum class Command
{
    CREATEDATABASE = 0,
    CREATETABLE,
    INSERTINTO,
    SELECT,
    UPDATE,
    DELETE,
};

std::map<std::string, Command> CommandParse;
std::string DataBase;
std::vector<std::string> Tables;
std::vector<std::vector<std::string>> FieldsName;
std::vector<std::vector<std::vector<std::string>>> FieldsInfo; // ays ereq vektornery poxarinvelu en maperov

size_t find_pos(std::vector<std::string>& vec, const std::string& value)
{
    for(size_t i = 0; i < vec.size(); ++i)
    {
        if(vec[i] == value)
        {
            return i;
        }
    }

    return UINT_MAX;
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

std::string remove_if(const std::string& value, char removal_value)
{
    std::string tmp;
    for(size_t i = 0; i < value.size(); ++i)
    {
        if(value[i] != removal_value)
        {
            tmp.push_back(value[i]);
        }
    }

    return tmp;
}

void update(std::vector<std::string>& CommandLine)
{
    int tableName = find_pos(Tables, CommandLine[1] + ".tb");
    std::ifstream fin{CommandLine[1] + ".tb"};
    FieldsName.resize(Tables.size());
    FieldsInfo.resize(Tables.size());
    while(!fin.eof())
    {
        char tmp[64];
        fin.getline(tmp, 64, '\n');
        FieldsName[tableName].push_back(tmp);
    }
    FieldsInfo[tableName].resize(FieldsName[tableName].size());

    for(size_t i = 0 ; i < FieldsName[tableName].size(); ++i)
    {
        fin.close();
        fin.open(FieldsName[tableName][i]);
        while(!fin.eof())
        {
            char tmp[64];
            fin.getline(tmp, 64, '\n');
            FieldsInfo[tableName][i].push_back(tmp);
        }
    }

    std::string field1;
    std::string relocatable_value;
    for(size_t i = 0 ; i < CommandLine[3].size(); ++i)
    {
        if(CommandLine[3][i] != '=')
        {
            field1.push_back(CommandLine[3][i]);
        }
        else
        {
            break;
        }
    }

    for(size_t i = field1.size() + 1; i < CommandLine[3].size(); ++i)
    {
            relocatable_value.push_back(CommandLine[3][i]);
    }

 //  where

    std::string field2;
    std::string condition_value;
    for(size_t i = 0 ; i < CommandLine[5].size(); ++i)
    {
        if(CommandLine[5][i] != '=')
        {
            field2.push_back(CommandLine[5][i]);
        }
        else
        {
            break;
        }
    }

    for(size_t i = field2.size() + 1; i < CommandLine[5].size(); ++i)
    {
        condition_value.push_back(CommandLine[5][i]);
    }

    condition_value = remove_if(condition_value, '\"');

    int reloc_fields = find_pos(FieldsName[tableName], "age.field");
    int condition_field = find_pos(FieldsName[tableName],  "name.field");

    std::cout << "|" <<FieldsName[tableName][condition_field] << "|";
    for(size_t i = 0; i < FieldsInfo[tableName][condition_field].size(); ++i)
    {
        if(FieldsInfo[tableName][condition_field][i] == condition_value)
        {
            std::cout << FieldsInfo[tableName][condition_field][i] << " " << FieldsInfo[tableName][reloc_fields][i] << " "; 
            FieldsInfo[tableName][reloc_fields][i] = relocatable_value;
            std::cout << FieldsInfo[tableName][reloc_fields][i];
        }
    }

    for(size_t i = 0; i < Tables.size(); ++i)
    {
        std::ofstream fieldOut{Tables[i] + "as"};
        for(size_t j = 0; j < FieldsName[i].size(); ++j)
        {
            fieldOut << FieldsName[i][j] << '\n';
            std::ofstream infoOut{FieldsName[i][j] + "sa"};
            for(size_t k = 0; k < FieldsInfo[i][j].size(); ++k)
            {
                infoOut << FieldsInfo[i][j][k] << '\n';
            }  
        }  
    }  
    
}// ays funkciayi tvjalneri pushy kkatarvi urish funkciayum

void execute(const std::string& line)
{
    CommandParse["CREATEDATABASE"] = Command::CREATEDATABASE;
    CommandParse["CREATETABLE"] = Command::CREATETABLE;
    CommandParse["INSERTINTO"] = Command::INSERTINTO;
    CommandParse["SELECT"] = Command::SELECT;
    CommandParse["UPDATE"] = Command::UPDATE;
    CommandParse["DELETE"] = Command::DELETE;

    std::vector<std::string> CommandLine = split(line, " ");

    update(CommandLine);

}

int main()
{
    Tables.push_back("table.tb");
    std::string comm = "UPDATE table SET age=24 WHERE name=\"Steve\"";
    execute(comm);
}
