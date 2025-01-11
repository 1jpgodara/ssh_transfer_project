#include <iostream>
#include "compress.h"
#include "decompress.h"
#include "transfer.h"

int main() {
    std::string source = "ssh_test_file.txt";
    std::string compressed = "compressed.gz";
    std::string decompressed = "output.txt";
    std::string transferred = "transferred_output.txt";

    // Step 1: Compress
    if (!compressFile(source, compressed)) {
        std::cerr << "Compression failed.\n";
        return 1;
    }
    std::cout << "File compressed successfully.\n";

    // Step 2: Decompress
    if (!decompressFile(compressed, decompressed)) {
        std::cerr << "Decompression failed.\n";
        return 1;
    }
    std::cout << "File decompressed successfully.\n";

    // Step 3: Transfer
    if (!transferFile(decompressed, transferred)) {
        std::cerr << "File transfer failed.\n";
        return 1;
    }
    std::cout << "File transferred successfully.\n";

    return 0;
}
