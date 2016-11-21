#include <iostream>
#include <string>
#include <stdlib.h>

#include "public.h"

std::string& remove_space(std::string& s){
  int begin = 0;
  begin = s.find(' ', 0);
  while(begin != -1){
    s.replace(begin, 1, "");
    begin = s.find(' ', begin);
  }
  return s;
}

int DeCodeHandle(const std::string &pStr, std::string &oStr){
  unsigned char P28[17]; // last bit for c style string
  unsigned long int A, B, C, D, P18;
  unsigned long int EAX, EBX, ECX, EDX;
  unsigned char P5C, P64, P6C;

  A = strtol(pStr.substr(0, 2).c_str(), NULL, 16);
  A = A | strtol(pStr.substr(2, 2).c_str(), NULL, 16)<<8;
  A = A | strtol(pStr.substr(4, 2).c_str(), NULL, 16)<<16;
  A = A | strtol(pStr.substr(6, 2).c_str(), NULL, 16)<<24;

  B = strtol(pStr.substr(8, 2).c_str(), NULL, 16);
  B = B | strtol(pStr.substr(10, 2).c_str(), NULL, 16)<<8;
  B = B | strtol(pStr.substr(12, 2).c_str(), NULL, 16)<<16;
  B = B | strtol(pStr.substr(14, 2).c_str(), NULL, 16)<<24;

  C = strtol(pStr.substr(16, 2).c_str(), NULL, 16);
  C = C | strtol(pStr.substr(18, 2).c_str(), NULL, 16)<<8;
  C = C | strtol(pStr.substr(20, 2).c_str(), NULL, 16)<<16;
  C = C | strtol(pStr.substr(22, 2).c_str(), NULL, 16)<<24;

  D = strtol(pStr.substr(24, 2).c_str(), NULL, 16);
  D = D | strtol(pStr.substr(26, 2).c_str(), NULL, 16)<<8;
  D = D | strtol(pStr.substr(28, 2).c_str(), NULL, 16)<<16;
  D = D | strtol(pStr.substr(30, 2).c_str(), NULL, 16)<<24;
/*
  std::cout << std::hex;
  std::cout << A << std::endl;
  std::cout << B << std::endl;
  std::cout << C << std::endl;
  std::cout << D << std::endl;
  std::cout << std::endl;
*/
  A = A ^ 0xBADEC2CC;
  B = B ^ 0x65BCED39;
  C = C ^ 0xCCE7EA98;
  D = D ^ 0x41F77B95;
/*
  std::cout << std::hex;
  std::cout << A << std::endl;
  std::cout << B << std::endl;
  std::cout << C << std::endl;
  std::cout << D << std::endl;
  std::cout << std::endl;
*/
  P18 = 4;

  for(int i = 0; i < 9; ++i){
    P28[0] = A & 0xFF;
    P28[1] = (A>>8) & 0xFF;
    P28[2] = (A>>16) & 0xFF;
    P28[3] = (A>>24) & 0xFF;
    P28[4] = B & 0xFF;
    P28[5] = (B>>8) & 0xFF;
    P28[6] = (B>>16) & 0xFF;
    P28[7] = (B>>24) & 0xFF;
    P28[8] = C & 0xFF;
    P28[9] = (C>>8) & 0xFF;
    P28[10] = (C>>16) & 0xFF;
    P28[11] = (C>>24) & 0xFF;
    P28[12] = D & 0xFF;
    P28[13] = (D>>8) & 0xFF;
    P28[14] = (D>>16) & 0xFF;
    P28[15] = (D>>24) & 0xFF;
/*
    std::cout << std::dec;
    for(int j = 0; j < 16; ++j){
      std::cout << (int)P28[j] << std::endl;
    }
*/
    P5C = P28[13];
    P64 = P28[10];
    A = BASE124[P28[7]] ^ BASE108[P64] ^ BASEEC[P5C] ^ BASED0[P28[0]] ^ BASE198[P18];

    P5C = P28[1];
    P64 = P28[14];
    P6C = P28[11];
    B = BASE198[P18 + 1] ^ BASE124[P6C] ^ BASE108[P64] ^ BASEEC[P5C] ^ BASED0[P28[4]];

    P5C = P28[5];
    P64 = P28[2];
    P6C = P28[15];
    C = BASE198[P18 + 2] ^ BASE124[P6C] ^ BASE108[P64] ^ BASEEC[P5C] ^ BASED0[P28[8]];

    P5C = P28[9];
    P64 = P28[6];
    P6C = P28[3];
    D = BASE198[P18 + 3] ^ BASE124[P6C] ^ BASE108[P64] ^ BASEEC[P5C] ^ BASED0[P28[12]];

    P18 = P18 + 4;
/*
    std::cout << std::hex;
    std::cout << A << std::endl;
    std::cout << B << std::endl;
    std::cout << C << std::endl;
    std::cout << D << std::endl;
    std::cout << std::endl;
*/
  }
/*
  std::cout << std::hex;
  std::cout << A << std::endl;
  std::cout << B << std::endl;
  std::cout << C << std::endl;
  std::cout << D << std::endl;
*/
  P28[0] = A & 0xFF;
  P28[1] = (A>>8) & 0xFF;
  P28[2] = (A>>16) & 0xFF;
  P28[3] = (A>>24) & 0xFF;
  P28[4] = B & 0xFF;
  P28[5] = (B>>8) & 0xFF;
  P28[6] = (B>>16) & 0xFF;
  P28[7] = (B>>24) & 0xFF;
  P28[8] = C & 0xFF;
  P28[9] = (C>>8) & 0xFF;
  P28[10] = (C>>16) & 0xFF;
  P28[11] = (C>>24) & 0xFF;
  P28[12] = D & 0xFF;
  P28[13] = (D>>8) & 0xFF;
  P28[14] = (D>>16) & 0xFF;
  P28[15] = (D>>24) & 0xFF;

  P5C = P28[13];
  P64 = P28[10];

  ECX = BASE140[P64];
  EDX = BASE140[P28[0]];
  ECX = ECX & 0xFF0000;
  EDX = EDX & 0xFF;
  ECX = ECX ^ EDX;
  EDX = BASE140[P28[7]];
  EDX = EDX & 0xFF000000;
  ECX = ECX ^ EDX;
  EAX = BASE140[P5C];
  EAX = EAX & 0xFF00;
  ECX = ECX ^ EAX;
  ECX = ECX ^ BASE198[P18];
  A = ECX;

  P5C = P28[1];
  P64 = P28[14];
  P6C = P28[11];

  EDX = BASE140[P64];
  ECX = BASE140[P28[4]];
  EDX = EDX & 0xFF0000;
  ECX = ECX & 0xFF;
  EDX = EDX ^ ECX;
  ECX = BASE140[P6C];
  ECX = ECX & 0xFF000000;
  EDX = EDX ^ ECX;
  EAX = BASE140[P5C];
  EAX = EAX & 0xFF00;
  EBX = BASE198[P18 + 1];
  EDX = EDX ^ EAX;
  EDX = EDX ^ EBX;
  B = EDX;

  P5C = P28[5];
  P64 = P28[2];
  P6C = P28[15];

  ECX = BASE140[P64];
  EDX = BASE140[P28[8]];
  ECX = ECX & 0xFF0000;
  EDX = EDX & 0xFF;
  ECX = ECX ^ EDX;
  EDX = BASE140[P6C];
  EDX = EDX & 0xFF000000;
  ECX = ECX ^ EDX;
  EAX = BASE140[P5C];
  EAX = EAX & 0xFF00;
  EBX = BASE198[P18 + 2];
  ECX = ECX ^ EAX;
  ECX = ECX ^ EBX;
  C = ECX;

  P5C = P28[9];
  P64 = P28[6];
  P6C = P28[3];

  EDX = BASE140[P64];
  ECX = BASE140[P28[12]];
  EDX = EDX & 0xFF0000;
  ECX = ECX & 0xFF;
  EDX = EDX ^ ECX;
  ECX = BASE140[P6C];
  ECX = ECX & 0xFF000000;
  EDX = EDX ^ ECX;
  EAX = BASE140[P5C];
  EAX = EAX & 0xFF00;
  EBX = BASE198[P18 + 3];
  EDX = EDX ^ EAX;
  EDX = EDX ^ EBX;
  D = EDX;

  P28[0] = A & 0xFF;
  P28[1] = (A>>8) & 0xFF;
  P28[2] = (A>>16) & 0xFF;
  P28[3] = (A>>24) & 0xFF;
  P28[4] = B & 0xFF;
  P28[5] = (B>>8) & 0xFF;
  P28[6] = (B>>16) & 0xFF;
  P28[7] = (B>>24) & 0xFF;
  P28[8] = C & 0xFF;
  P28[9] = (C>>8) & 0xFF;
  P28[10] = (C>>16) & 0xFF;
  P28[11] = (C>>24) & 0xFF;
  P28[12] = D & 0xFF;
  P28[13] = (D>>8) & 0xFF;
  P28[14] = (D>>16) & 0xFF;
  P28[15] = (D>>24) & 0xFF;

  P28[16] = '\0'; // hack for c style string
  const char *resultStr = (const char *)P28;
/*
  std::cout << std::hex;
  for(int i = 0; i < 16; ++i){
    std::cout << (int)P28[i];
  }
  std::cout << std::endl;
*/
  oStr = resultStr;

  return 0;
}

int DeCode(const std::string& pStr, std::string& oStr){
  std::string tmp = pStr;
  remove_space(tmp);

  // check length
  if(tmp.length() % 32 != 0){
    return 1;
  }

  oStr = "";
  std::string input, output;
  for(int i = 0; i < tmp.length(); i += 32){
    input = tmp.substr(i, 32);
    output = "";
    DeCodeHandle(input, output);
    oStr.append(output);
  }

  return 0;
}

// for python call
extern "C"
const char* python(const char input[]){
  std::string pStr = input, oStr = "";
  char *output;
  DeCode(pStr, oStr);
  output = (char *)malloc((strlen(oStr.c_str()) + 1) * sizeof(char));
  strcpy(output, oStr.c_str());
  return output;
}

int main(int argc, char const *argv[]) {
  if(argc >= 2 && strcmp(argv[1], "--help") != 0 && strcmp(argv[1], "-h")){
    std::string pStr, oStr;
    for(int i = 1; i < argc; ++i){
      pStr = argv[i];
      oStr = "";
      if(DeCode(pStr, oStr) == 0){
        std::cout << oStr;
      }
      else{
        std::cout << std::endl << "The string \"" << pStr << "\" decode failed." << std::endl;
      }
    }
    std::cout << std::endl;
  }
  else{
    std::cout << "usage: decode [(-h | --help)] [text] ..." << std::endl;
    std::cout << "Options and arguments:" << std::endl;
    std::cout << "-h, --help : print this help message and exit" << std::endl;
    std::cout << "text ...   : text to decode" << std::endl;
  }
  return 0;
}
