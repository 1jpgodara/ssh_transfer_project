#ifndef COMPRESS_H
#define COMPRESS_H

#include <string>

// Compress a file using zlib
bool compressFile(const std::string& sourceFile, const std::string& destFile);

#endif // COMPRESS_H
