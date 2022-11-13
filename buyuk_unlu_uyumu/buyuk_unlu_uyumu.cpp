#include <iostream>

using namespace std;

int getStringSize(char* word) {
    int string_size = 0;
    while (*word != '\0') {
        string_size++;
        word++;
    }
    return string_size;
}


bool stringCompare(char* word, const char* character_array,int string_size, int char_arr_size) {

    for (int i = 0; i < string_size; i++) {
        for (int j = 0; j < char_arr_size; j++) {
            if (word[i] == character_array[j])
                return false;
        }
    }
    return true;
}

bool buyukUnluUyumu(char* word){
    const char kalin_harfler[] = "aýou";
    const char ince_harfler[] = "eiöü";

    int string_size = getStringSize(word);
    bool result = false;
    int j = 0;

    for (int i = 0; i < string_size; i++) {
        for(int j = 0; j < 4 ; j++)              // 4 = kalin_harfler, ince_harfler dizisi boyutu
           if (word[i] == kalin_harfler[j]) {
               result = stringCompare(word, ince_harfler, string_size, 4);
               break;
           }
           else if (word[i] == ince_harfler[j]) {
               result = stringCompare(word, kalin_harfler, string_size, 4);
               break;
           }
    }

    return result;
}

int main()
{
    char word[] = "üzengi";
    bool result = buyukUnluUyumu(word);
    if (result == true) {
        cout << word << " buyuk unlu uyumuna uyar";
    }
    else {
        cout << word << " buyuk unlu uyumuna uymaz";
    }
    
    return 0;
}

