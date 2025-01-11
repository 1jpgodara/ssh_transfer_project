#include "decompress.h"
#include <zlib.h>
#include <fstream>
#include <iostream>

#define CHUNK 16384

bool decompressFile(const std::string& sourceFile, const std::string& destFile) {
    std::ifstream source(sourceFile, std::ios::binary);
    std::ofstream dest(destFile, std::ios::binary);

    if (!source.is_open() || !dest.is_open()) {
        std::cerr << "Error opening files for decompression.\n";
        return false;
    }

    z_stream strm = {0};
    inflateInit(&strm);

    char in[CHUNK];
    char out[CHUNK];

    do {
        source.read(in, CHUNK);
        strm.avail_in = source.gcount();
        if (strm.avail_in == 0) break;
        strm.next_in = reinterpret_cast<Bytef*>(in);

        do {
            strm.avail_out = CHUNK;
            strm.next_out = reinterpret_cast<Bytef*>(out);
            inflate(&strm, Z_NO_FLUSH);
            dest.write(out, CHUNK - strm.avail_out);
        } while (strm.avail_out == 0);
    } while (!source.eof());

    inflateEnd(&strm);
    source.close();
    dest.close();

    return true;
}
