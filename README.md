# cpp_shared_object_2

This is the first application that I decided to write by combining:
- Windows Subsystem for Linux, using Ubuntu as the distribution
- A shared library written in C++
- Python script leveraging the C++ shared library

It's a follow-up to the tool I've been working on for the past several weeks, where I leverage one or more languages to process a large data set. And by large, I mean several hundred megabytes in size.

In this case, I use this NYC Yellow cab dataset from Kaggle: https://www.kaggle.com/taylornoren/nyc-yellow-cab-trip-data-201703

This tool uses a binary file produced by a previous project that I created, which converts a large CSV into a less large binary file with an adjusted format.

I use this new adjusted binary format in this shared libary (.so) file, and then leverage that .so file with a Python script.

By doing this, I can hand off the processing from Python to C++ and speed up the processing a bit. 

With this run, I achieved just over 3 seconds with processing the 200+ MB binary file (which was converted/compressed from the 800+MB CSV file).

This is around the same speed I achieved with pure C++ parsing the CSV directly (~3 seconds), but is considerably slower than when I had C++ parse the binary file after doing the preprocessing (~0.15 seconds).

I didn't document the exact times, but here is a list of the fastest times I observed in general for each of my implementations so far. Each implementation counted the number of records that matched a certain condition.

1. C++ parsing a binary file: ~0.15 seconds
2. C++ parsing a CSV file: ~3 seconds
3. Python + C++ shared library: ~3 seconds
3. Go parsing a CSV file: ~3 seconds
4. Cython parsing a CSV file: ~8 seconds
5. Python parsing a CSV file: ~11 seconds

These were also across different operating systems too (Windows, Lubuntu VM, and Windows Subsystem for Linux). So eventually, I'll do an official benchmark with all of these versions to get the fastest one.

