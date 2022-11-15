#include <iostream>


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

bool vowelHarmony(char* word){
    const char bold_vowels[] = "aýou";
    const char thin_vowels[] = "eiöü";

    int string_size = getStringSize(word);
    bool result = false;
    int j = 0;

    for (int i = 0; i < string_size; i++) {
        for(int j = 0; j < 4 ; j++)              // 4 = kalin_harfler, ince_harfler dizisi boyutu
           if (word[i] == bold_vowels[j]) {
               result = stringCompare(word, thin_vowels, string_size, 4);
               break;
           }
           else if (word[i] == thin_vowels[j]) {
               result = stringCompare(word, bold_vowels, string_size, 4);
               break;
           }
    }

    return result;
}

int main()
{
    char word[] = "kýrlangýç";     // kelime ç harfi içeriyorsa bazý derleyicilerde sonuç hatalý olabiliyor.
    bool result = vowelHarmony(word);
    if (result == true) {
        std::cout << word << " buyuk unlu uyumuna uyar";
    }
    else {
        std::cout << word << " buyuk unlu uyumuna uymaz";
    }
    
    return 0;
}

