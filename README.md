# LFSR_photomagicProject 
description: The purose /goal of this assignment was to write a program to read three
arguments from the commandline. Most of the code arer simililar to part a except the
(PhotoMagic.cpp)main.cpp whci accepts the command line :
% PhotoMagic input-file.png output-file.png 1011011000110110
What I Accomplished: Parse arguments from shell to main,
Load image to memory Encode it with transform function
Open two dialog to display original and encoded image and
Save encoded image to disk.
For the extra credit: i used simple_hash function to generate functions.
Key Algorithm:I designed a hash function to convert any key-chain to 16-bit unsigned int So, i
can use the hash result for FibLFSR's seed.
What I learned working in this project and some Challenges: this was one of the project I
enjoyed working on. Learning the Transform function how it work was very interesting. I didn’t
have any issue. But I did spend some time reading the documentations and examples.
