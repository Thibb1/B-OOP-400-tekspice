/*
** EPITECH PROJECT, 2022
** /home/hugo/Epitach/tekspice
** File description:
** RegUtil.cpp
*/

#include "Parser.hpp"

std::ifstream Parser::checkFile(std::string filename)
{
    std::ifstream file;
    if (!RegUtils::isMatch(filename, "^(.*\\/)*[^\\.]+\\.nts$")) {
        throw std::invalid_argument("Invalid file name");
    }
    file.open(filename);
    if (!file.is_open()) {
        throw std::invalid_argument("File not found");
    }
    return file;
}

bool Parser::isInVector(std::string str, std::vector<std::string> vec)
{
    return std::find(vec.begin(), vec.end(), str) != vec.end();
}

void Parser::parse(std::string filename)
{
    std::ifstream file = checkFile(filename);
    std::string line;
    std::string arg = "([\\w]+)$";
    std::string linkPattern = "^((\\w+):(\\d+)) ((\\w+):(\\d+))$";
    std::string chipsets[] = {
        "^(input)" + arg,
        "^(output)" + arg,
        "^(2716)" + arg,
        "^(4001)" + arg,
        "^(4008)" + arg,
        "^(4011)" + arg,
        "^(4013)" + arg,
        "^(4017)" + arg,
        "^(4930)" + arg,
        "^(4040)" + arg,
        "^(4069)" + arg,
        "^(4071)" + arg,
        "^(4081)" + arg,
        "^(4094)" + arg,
        "^(4512)" + arg,
        "^(4514)" + arg,
        "^(4801)" + arg,
        "^(clock)" + arg,
        "^(false)" + arg,
        "^(input_output)" + arg,
        "^(logger)" + arg,
        "^(true)" + arg,
        "^(altered-counter)" + arg,
        "^(and-or-not)" + arg,
        "^(and)" + arg,
    };
    std::map<std::string, std::vector<std::string>> chipsetsMap;
    std::vector<std::string> chipsetsVec;
    std::vector<std::string> linksInputVec;
    std::vector<std::string> linksOutputVec;
    bool sectionChipsets = false;
    bool sectionLinks = false;

    while (getline(file, line)) {
        bool found = false;

        if (line.empty() || line[0] == '#')
            continue;
        if (RegUtils::isMatch(line, "^\\.chipsets:$")) {
            if (sectionChipsets)
                throw std::invalid_argument("Two chipset section");
            sectionChipsets = true;
            continue;
        }
        if (RegUtils::isMatch(line, "^\\.links:$")) {
            if (sectionLinks)
                throw std::invalid_argument("Two link section");
            sectionLinks = true;
            continue;
        }
        if (sectionChipsets) {
            for (std::string regex : chipsets) {
                if (RegUtils::isMatch(line, regex)) {
                    std::smatch smatch = RegUtils::getMatch(line, regex);
                    std::string type = smatch[1].str();
                    std::string val = smatch[2].str();

                    if (isInVector(val, chipsetsVec))
                        throw std::invalid_argument("Duplicate link name: " + val);
                    chipsetsVec.push_back(val);
                    if (chipsetsMap.find(type) == chipsetsMap.end())
                        chipsetsMap[type] = {val};
                    else
                        chipsetsMap[type].push_back(val);
                    found = true;
                    break;
                }
            }
        } else if (sectionLinks) {
            if (RegUtils::isMatch(line, linkPattern)) {
                std::smatch smatch = RegUtils::getMatch(line, linkPattern);
                std::string chipsetLink = smatch[1].str();                      //string avec input et link
                std::string chipset = smatch[2].str();                          //chipset
                int pin = std::stoi(smatch[3].str());                           //pin du chipset
                std::string linkLinkPin = smatch[4].str();                      //link et pin du link
                std::string link = smatch[5].str();                             //link
                int linkPin = std::stoi(smatch[6].str());                       //pin du link

                if (isInVector(chipsetLink, linksInputVec))
                    throw std::invalid_argument("Duplicate link input: " + line);
                linksInputVec.push_back(chipsetLink);
                if (isInVector(linkLinkPin, linksOutputVec))
                    throw std::invalid_argument("Duplicate link output: " + line);
                linksInputVec.push_back(linkLinkPin);
            }
            throw std::invalid_argument("Invalid link: " + line);
        }
        if (found)
            continue;
        throw std::invalid_argument("Invalid nts: " + line);
    }
}

//pas de chipset, on affiche une erreur et on quitte
//si pas de links, pas genant
//pas de .liks ou .chipset, on exit car errueur de fichier