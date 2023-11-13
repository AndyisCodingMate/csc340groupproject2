//This file is for documentation purposes only. It will be ignored by the compiler.
//Our Teaching Assistant will manually grade this file.

//Please make sure that you include the entire content of this file as comments.

/* Design Doc: communicate your thought process in English.
 
0. List of members who contributed to the implementation of this project:
   Andy Poon
   Tina Chou

 
1. Describe your algorithm for the sentenceSplitter( ) function in pseudocode.
    First, separate the paragraphs and store in vector of strings.
    In each paragraph, we use std::min(.find() case for . , ! ? :) for the position or index of the next puncutation. 
    We will set that index as a flag. Check if the next index is a closing quotation, if yes, we move the flag by one index.
    Substring the beginning of the string all the way to flag, erase the substring part in the original string.
    Repeat the code until the string is empty.      

2. Describe your algorithm for the wordpairMapping( ) function in pseudocode.
    
 

*/