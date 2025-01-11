#include "transfer.h"
#include <fstream>
#include <iostream>

bool transferFile(const std::string& sourceFile, const std::string& destFile) {
    std::ifstream source(sourceFile, std::ios::binary);
    std::ofstream dest(destFile, std::ios::binary);

    if (!source.is_open() || !dest.is_open()) {
        std::cerr << "Error opening files for transfer.\n";
        return false;
    }

    dest << source.rdbuf();

    source.close();
    dest.close();

    return true;
}
