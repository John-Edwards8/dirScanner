#include <iostream>
#include <Windows.h>
#include "File.h"


std::vector<File> scanDirectory(const std::string& directoryPath) {
    std::vector<File> files;

    for (const auto& entry : fs::directory_iterator(directoryPath)) {
        if (fs::is_regular_file(entry)) {
            File File;
            File.setName(entry.path().filename().string());
            File.setPath(entry.path().string());
            File.setExt(entry.path().extension().string());
            File.setSize(fs::file_size(entry));
            const auto fileTime = fs::last_write_time(entry);
            const auto systemTime = chrono::clock_cast<chrono::system_clock>(fileTime);
            File.setLastAT(chrono::system_clock::to_time_t(systemTime));
            files.push_back(File);
        }
    }

    return files;
}

void displayFiles(std::vector<File>& files) {
    for (auto& File : files) {
        auto time = File.getLastAT();
        std::cout << File.getName() << " - " << File.getPath() << " - "
            << File.getExt() << " - " << File.getSize() << " bytes - "
            << std::asctime(std::localtime(&time));
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string directoryPath = "C:\\KHNURE\\־־ְ\\ַֿ דמעמגûו";
    std::vector<File> files = scanDirectory(directoryPath);
    displayFiles(files);

    return 0;
}