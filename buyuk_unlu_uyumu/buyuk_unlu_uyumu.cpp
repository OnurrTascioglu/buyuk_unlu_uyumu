#include <iostream>
#include <locale.h> 

int getStringSize(wchar_t* word) {
    int string_size = 0;
    while (*word != '\0') {
        string_size++;
        word++;
    }
    return string_size;
}


bool stringCompare(wchar_t* word, const wchar_t* character_array, int string_size, int char_arr_size) {
    for (int i = 0; i < string_size; i++) {
        for (int j = 0; j < char_arr_size; j++) {
            if (int(word[i]) == int(character_array[j])) {
                return false;
            }
        }
    }
    return true;
}

bool vowelHarmony(wchar_t* word) {
    const wchar_t bold_vowels[] = L"aýou";   // I 
    const wchar_t thin_vowels[] = L"eiöü";

    int string_size = getStringSize(word);
    bool result = false;
    int j = 0;

    for (int i = 0; i < string_size; i++) {
        for (int j = 0; j < 4; j++)              // 4 = kalin_harfler, ince_harfler dizisi boyutu
            if (word[i] == bold_vowels[j]) {
                result = stringCompare(word, thin_vowels, string_size, 4);
                return result;
            }
            else if (word[i] == thin_vowels[j]) {
                result = stringCompare(word, bold_vowels, string_size, 4);
                return result;
            }
    }

    return result;
}

int main()
{
    setlocale(LC_ALL, "Turkish");
    wchar_t word[] = L"kýrlangýç";

    bool result = vowelHarmony(word);
    if (result == true) {
        std::cout << " buyuk unlu uyumuna uyar";
    }
    else {
        std::cout << " buyuk unlu uyumuna uymaz";
    }
     
    return 0;
}

