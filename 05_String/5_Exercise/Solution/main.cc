#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "exercise.h"

int main()
{
    auto iffile = std::ifstream{};
    iffile.open("text.txt", std::ios::in);

    auto content = std::string{};
    iffile >> content;
    iffile.close();

    auto data = ByteArray(8, 0xAA);
    auto key = ByteArray(8, 0xFF);
    const auto cipher_text = hex_vector_xor(data, key);

    for (std::size_t i = 0; i < cipher_text.size(); ++i)
    {
        std::cout << "Cipher[" << i << "] = " << cipher_text[i] << std::endl;
    }
    std::cout << std::endl;

    ByteArray message = hex_vector_xor(cipher_text, key);

    for (std::size_t i = 0; i < message.size(); ++i)
    {
        std::cout << "Message[" << i << "] = " << message[i] << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
