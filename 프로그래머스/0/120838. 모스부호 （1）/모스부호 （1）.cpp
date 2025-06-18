#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
/*
letter를 영어 소문자로 바꾼 문자열 return
공백을 기준
*/
string solution(string letter) {
    string answer = "";
    map<string, char>morse = {
        {".-", 'a'},   {"-...", 'b'}, {"-.-.", 'c'}, {"-..", 'd'},  {".", 'e'},
        {"..-.", 'f'}, {"--.", 'g'},  {"....", 'h'}, {"..", 'i'},   {".---", 'j'},
        {"-.-", 'k'},  {".-..", 'l'}, {"--", 'm'},   {"-.", 'n'},   {"---", 'o'},
        {".--.", 'p'}, {"--.-", 'q'}, {".-.", 'r'},  {"...", 's'},  {"-", 't'},
        {"..-", 'u'},  {"...-", 'v'}, {".--", 'w'},  {"-..-", 'x'}, {"-.--", 'y'},
        {"--..", 'z'}
    }; 
    
    stringstream ss(letter);
    vector<string> words;
    string word;
    while(getline(ss, word, ' ')){
        if(morse.find(word) != morse.end()){
           answer =  answer + morse[word];
        }
    }
    
    
    return answer;
}