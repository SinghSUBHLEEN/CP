#include<iostream>
#include<string.h>

using namespace std;

int main(){

    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    string sentence;
    int i, charCount = 0, wordCount = 1;

    cout<<"Please enter the sentence: ";
    getline(cin, sentence);

    for(i=0; i<sentence.size(); i++){
        if(sentence[i]!=' ') charCount++;
        else wordCount++;
    }

    cout<<endl<<"The number of characters is: "<<charCount;
    cout<<endl<<"The number of words is: "<<wordCount;
    cout<<endl<<"The average word length is: "<<((double)charCount/wordCount);

    return 0;
}