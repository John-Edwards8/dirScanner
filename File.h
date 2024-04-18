#pragma once
#include "extType.h"
#include <iostream>
#include <vector>
#include <map>
#include <chrono>
#include <filesystem>

namespace fs = std::filesystem;
namespace chrono = std::chrono;


std::map<std::string, extType> extensionMap = {
    {".mp3", Audio},
    {".wav", Audio},
    {".mp4", Video},
    {".avi", Video},
    {".txt", Text},
    {".docx", Text},
    {".pdf", Text},
    {".jpg", Photo},
    {".png", Photo},
    {".zip", Compressed},
    {".rar", Compressed},
    {".exe", Executable}
};


class File
{
    std::string name;
    std::string path;
    std::string extension;
    extType extensionType;
    uintmax_t size;
    std::time_t lastAccessTime;
public:
    void setName(auto name) { this->name = name; }
    void setPath(auto path) { this->path = path; }
    void setExtType(auto extensionType) { this->extensionType = extensionType; }
    void setSize(auto size) { this->size = size; }
    void setLastAT(auto lastAccessTime) { this->lastAccessTime = lastAccessTime; }
    void setExt(auto extension) {
        this->extension = extension;
        this->setExtType(extensionMap[extension]);
    }

    std::string getName() { return this->name; }
    std::string getPath() { return this->path; }
    std::string getExt() { return this->extension; }
    extType getExtType() { return this->extensionType; }
    uintmax_t getSize() { return this->size; }
    std::time_t getLastAT() { return this->lastAccessTime; }
    
};
