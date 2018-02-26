# RLE_multi_stage
this code apply Compression into multi stage for html text files  

stages are first as the nature of text only have char lower and upper case and special char < > / all have the 8th bit " 0 "
so the first stage remove the 8th bit, 
second stage apply RLE with two bits dealling wit zeros, 
third stage appllying RLE on the last step with 3 bits as the number of contugoues zeros become alitle bit more.

the final stage collecting all together converting the binary string to opposite char to reduce the size by eighth factor.

compression stages separated into multi function,
decompression also separated into multi function.

the final compressed file is "compressed.txt",
the decompressed original file is "decompress.txt".

compression ratio is 92.5%
