#ifndef DECOMPRESS_H
#define DECOMPRESS_H

#include <string>

// Decompress a file using zlib
bool decompressFile(const std::string& sourceFile, const std::string& destFile);

#endif // DECOMPRESS_H
