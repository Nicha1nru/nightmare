# Nightmare

This program overwrites all data in a folder.

# How it works
nightmare <path_to_folder>

#How to install

First clone this repository. Then change the "lib = ctypes.CDLL('/home/niggachainailayer2/c/nightmare/c/overwrite.so')  # Ensure this path is correct" line to where overwrite.so is stored on your system.
And then run the following commands:

touch /usr/local/bin/nightmare
chmod +x /usr/local/bin/nightmare

nano /usr/local/bin/nightmare

Put this in the file:
#!/bin/bash
python3 /path/to/nightmare.py "$1"

Now enter the following command:
chmod +x /usr/local/bin/nightmare
