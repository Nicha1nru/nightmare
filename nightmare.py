import ctypes
import sys
import os

def overwrite_folder(folder_path, size_in_bytes):
    # Load the shared library
    lib = ctypes.CDLL('/home/niggachainailayer2/c/nightmare/c/overwrite.so')  # Ensure this path is correct
    lib.overwrite.argtypes = [ctypes.c_char_p, ctypes.c_size_t]
    lib.overwrite.restype = None

    folder_path_ctypes = ctypes.c_char_p(folder_path.encode('utf-8'))

    # Call the C function
    lib.overwrite(folder_path_ctypes, size_in_bytes)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nightmare <path_to_folder>")
        sys.exit(1)

    folder_path = sys.argv[1]

    if not os.path.isdir(folder_path):
        print(f"The provided path is not a directory: {folder_path}")
        sys.exit(1)

    print(f"Overwriting everything in the folder: {folder_path}")
    overwrite_folder(folder_path, 1024)  # Size in bytes to overwrite each file
