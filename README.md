Here’s a **README.md** file for your project:

---

# **SSH Transfer Project**

This project is a simple C++ application that performs file compression, decompression, and simulates SSH-like file transfer. The goal is to handle files of varying sizes (from a few bytes to large files up to 100 GB) and demonstrate modular programming with proper code documentation.

---

## **Features**
1. **File Compression**: Compresses files using the zlib library.
2. **File Decompression**: Decompresses files back to their original state.
3. **File Transfer Simulation**: Simulates SSH-based file transfer using basic file copy functionality.

---

## **Directory Structure**
```
ssh_transfer_project/
├── src/               # Source code files
│   ├── compress.cpp   # File compression logic
│   ├── decompress.cpp # File decompression logic
│   ├── transfer.cpp   # File transfer simulation logic
│   ├── main.cpp       # Main entry point of the application
├── include/           # Header files
│   ├── compress.h     # Header for compression functions
│   ├── decompress.h   # Header for decompression functions
│   ├── transfer.h     # Header for transfer functions
├── input.txt          # Example input file (used for testing)
├── Makefile           # Build system
├── README.md          # Project documentation
```

---

## **Requirements**
1. **C++ Compiler**: Any C++17-compatible compiler (e.g., GCC or Clang).
2. **zlib Library**: For compression and decompression. Install using:
   - On Ubuntu/Debian: `sudo apt install zlib1g-dev`
   - On MacOS: `brew install zlib`
   - On Windows: Download zlib from [zlib.net](https://zlib.net).
3. **Make**: For building the project.

---

## **Build Instructions**
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd ssh_transfer_project
   ```

2. Build the project using the Makefile:
   ```bash
   make
   ```

3. Run the executable:
   ```bash
   ./bin/ssh_transfer
   ```

4. Clean the build files (optional):
   ```bash
   make clean
   ```

---

## **How to Use**
1. **Prepare Input File**:
   - Create or place a test file named `input.txt` in the project directory.
   
2. **Run the Application**:
   - The program performs the following steps:
     - Compresses `input.txt` to `compressed.gz`.
     - Decompresses `compressed.gz` to `output.txt`.
     - Transfers `output.txt` to `transferred_output.txt`.

3. **Verify Results**:
   - Check the output files:
     - `compressed.gz`: Compressed file.
     - `output.txt`: Decompressed file (should match the original `input.txt`).
     - `transferred_output.txt`: File transferred (should match `output.txt`).

---

## **Project Workflow**
1. **Compression**:
   - Uses `zlib` to compress a file and write it to a `.gz` file.
2. **Decompression**:
   - Reads the `.gz` file and restores the original file.
3. **File Transfer**:
   - Simulates file transfer by copying the decompressed file to a new destination.

---

## **File Details**
### **Source Files**
- `src/compress.cpp`: Implements file compression using `zlib`.
- `src/decompress.cpp`: Implements file decompression using `zlib`.
- `src/transfer.cpp`: Implements mock file transfer by copying files.
- `src/main.cpp`: Integrates all components and orchestrates the flow.

### **Header Files**
- `include/compress.h`: Declares the compression function.
- `include/decompress.h`: Declares the decompression function.
- `include/transfer.h`: Declares the file transfer function.

---

## **Limitations**
1. File sizes are limited only by system resources (e.g., available memory and disk space).
2. The file transfer is simulated and does not use actual SSH communication.

---

## **Future Improvements**
1. Integrate real SSH functionality using the **libssh** library.
2. Add multithreading for faster compression and decompression of large files.
3. Provide support for real-time file transfer progress monitoring.

---

## **References**
- **zlib Documentation**: [https://zlib.net](https://zlib.net)
- **C++ File I/O**: [cplusplus.com](https://cplusplus.com/reference/fstream/)
- **Makefiles**: [GNU Make Manual](https://www.gnu.org/software/make/manual/)

---

## **Contributors**
- **JP Godara**: Project Creator and Developer.
