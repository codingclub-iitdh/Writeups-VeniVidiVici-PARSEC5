#include <iostream>
#include <string>
#include <cstdint>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <ctime>

#define SHIFT 10
#define CHARSET_SIZE 26 // Only letters A-Z

using namespace std;

// Base32 encoding table (used for encoding 5-bit groups)
const char EncodingTable[33] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";

// Function to encode a string in Base32
std::string base32_encode(
    const std::vector<uint8_t>& data,
    bool omitPadding
) {
    std::ostringstream output;
    size_t bits = 0;
    uint32_t buffer = 0;
    for (auto datum : data) {
        buffer <<= 8;
        buffer += (uint32_t)datum;
        bits += 8;
        while (bits >= 5) {
            output << EncodingTable[(buffer >> (bits - 5)) & 0x3f];
            buffer &= ~(0x1f << (bits - 5));
            bits -= 5;
        }
    }
    
    // Padding logic for Base32 encoding
    if ((data.size() % 5) == 1) {
        buffer <<= 2;
        output << EncodingTable[buffer & 0x1f];
        if (!omitPadding) {
            output << "======";
        }
    } else if ((data.size() % 5) == 2) {
        buffer <<= 4;
        output << EncodingTable[buffer & 0x1f];
        if (!omitPadding) {
            output << "====";
        }
    } else if ((data.size() % 5) == 3) {
        buffer <<= 1;
        output << EncodingTable[buffer & 0x1f];
        if (!omitPadding) {
            output << "===";
        }
    } else if ((data.size() % 5) == 4) {
        buffer <<= 3;
        output << EncodingTable[buffer & 0x1f];
        if (!omitPadding) {
            output << '=';
        }
    }

    return output.str();
}

// Function to print the mapping
void print_mapping(const unordered_map<char, char>& mapping) {
    cout << "Character Mapping:" << endl;
    for (const auto& pair : mapping) {
        cout << pair.first << " -> " << pair.second << endl;
    }
}

// Function to encode a string with substitution and Base32
void encode(const string& input, string& output, unordered_map<char, char>& mapping) {
    int len = input.length();
    string temp(len, ' ');

    // Apply substitution encoding
    for (int i = 0; i < len; i++) {
        if (isalpha(input[i])) {
            temp[i] = mapping[input[i]];  // Substitute alphabet characters
        } else {
            temp[i] = input[i]; // Non-alphabet characters remain unchanged
        }
    }

    // Rotate the string by SHIFT characters
    output.resize(len);
    for (int i = 0; i < len; i++) {
        output[(i + SHIFT) % len] = temp[i];
    }

    // Convert the string to a vector of uint8_t for Base32 encoding
    vector<uint8_t> encoded_data(output.begin(), output.end());

    // Apply Base32 encoding to the rotated string
    output = base32_encode(encoded_data, false);  // false to include padding
}

int main() {
    srand(time(0));
    
    // Mapping for uppercase and lowercase letters (corrected duplication)
    unordered_map<char, char> mapping = {
        {'A', 'M'}, {'B', 'Q'}, {'C', 'X'}, {'D', 'T'}, {'E', 'O'}, {'F', 'J'}, {'G', 'Y'}, {'H', 'N'}, {'I', 'P'}, {'J', 'Z'},
        {'K', 'B'}, {'L', 'S'}, {'M', 'V'}, {'N', 'D'}, {'O', 'F'}, {'P', 'W'}, {'Q', 'C'}, {'R', 'K'}, {'S', 'E'}, {'T', 'A'},
        {'U', 'L'}, {'V', 'H'}, {'W', 'U'}, {'X', 'G'}, {'Y', 'R'}, {'Z', 'I'},
        {'a', 'm'}, {'b', 'q'}, {'c', 'x'}, {'d', 't'}, {'e', 'o'}, {'f', 'j'}, {'g', 'y'}, {'h', 'n'}, {'i', 'p'}, {'j', 'z'},
        {'k', 'b'}, {'l', 's'}, {'m', 'v'}, {'n', 'd'}, {'o', 'f'}, {'p', 'w'}, {'q', 'c'}, {'r', 'k'}, {'s', 'e'}, {'t', 'a'},
        {'u', 'l'}, {'v', 'h'}, {'w', 'u'}, {'x', 'g'}, {'y', 'r'}, {'z', 'i'}
    };
    
    // Print the character mapping
//    print_mapping(mapping);
    string flag;
    encode("parsec{sample_flag}",flag,mapping);
    cout<<flag<<"\n";
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    
    string encoded;
    encode(input, encoded, mapping);
    
    cout << "Encoded string: " << encoded << endl;
    
    return 0;
}
