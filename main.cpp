#include <iostream>


void encryptCaesar(char *str, uint8_t key) {
    // магическое число 96 это используемый, в этой функции, диапазон символов по таблице ACSII, от 32-го символа до 127-го.
    int i = 0;
    uint8_t tmp;
    if (key >= 96)
        key = key %
              96; // Если ключ смещения больше 95 берем остаток от деления на 96 и попадаем в начало диапазона символов.
    while (str[i] != '\0') {
        tmp = str[i] + key;
        if (tmp > 127) tmp = (str[i] + key) - 96; // Если вышли за диапазон, смещаемся в начало.
        str[i] = tmp;
        i++;
    }
}

void decryptCeasar(char *str, uint8_t key) {
    int i = 0;
    uint8_t tmp;
    if (key >= 96) key = key % 96;
    while (str[i] != '\0') {
        tmp = str[i] - key;
        if (tmp < 32) tmp = (str[i] - key) + 96;
        str[i] = tmp;
        i++;
    }
}


void encryptPermutation(char *str, int cols) {
    char res[128] = "";
    int length = 0, c = 0, k = 0;
    while (str[length] != 0) length++;
    int rows = (length % cols == 0) ? length / cols : length / cols + 1;
    for (int i = 0; i < cols; ++i) {
        c = i;
        for (int j = 0; j < rows; ++j) {
            res[k] = str[c];
            k++;
            c += cols;
        }
    }
    for (int i = 0; i < cols * rows; ++i) {
        if (res[i] == '\0') str[i] = 35;
        else str[i] = res[i];
    }
}

void decryptPermutation(char *str, int cols){
    char res[128] = "";
    int length = 0, c = 0, k = 0;
    while (str[length] != 0) length++;
    int rows = (length % cols == 0) ? length / cols : length / cols + 1;
    for (int i = 0; i < rows; ++i) {
        c = i;
        for (int j = 0; j < cols; ++j) {
            res[k] = str[c];
            k++;
            c += rows;
        }
    }
    for (int i = 0; i < cols * rows; ++i) {
        if (res[i] == 35) str[i] = '\0';
        else str[i] = res[i];
    }
}

int main() {
    char str[128] = "Hello world! We are the champions!";
    std::cout << "original message = " << str << std::endl;
    encryptCaesar(str, 120);
    std::cout << "encrypt message(Ceasar) = " << str << std::endl;
    decryptCeasar(str, 120);
    std::cout << "decrypt message(Ceasar) = " << str << std::endl << std::endl << std::endl;

    std::cout << "original message = " << str << std::endl;
    encryptPermutation(str, 5);
    std::cout << "encrypt message(Permutation) = " << str << std::endl;
    decryptPermutation(str, 5);
    std::cout << "decrypt message(Permutation) = " << str << std::endl;

    return 0;
}
