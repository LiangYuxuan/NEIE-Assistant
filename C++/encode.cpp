#include <iostream>
#include <string>

#include "public.h"

std::string& trim(std::string &s){
    if(s.empty()){
        return s;
    }
    s.erase(0, s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}

int EnCodeHandle(const std::string &pStr, std::string &oStr){
  unsigned char P28[16];
  unsigned long int A, B, C, D, P18;
  unsigned long int EAX, EBX, ECX, EDX;
  unsigned char P5C, P64, P6C;

  for(int i = 0; i < 16; ++i){
    P28[i] = 0;
  }

  for(int i = 0; i < pStr.length(); ++i){
    P28[i] = ((int)pStr[i]);
  }

  A = (P28[3]<<24) | (P28[2]<<16) | (P28[1]<<8) | (P28[0]);
  B = (P28[7]<<24) | (P28[6]<<16) | (P28[5]<<8) | (P28[4]);
  C = (P28[11]<<24) | (P28[10]<<16) | (P28[9]<<8) | (P28[8]);
  D = (P28[15]<<24) | (P28[14]<<16) | (P28[13]<<8) | (P28[12]);

  A = A ^ 0x63573231;
  B = B ^ 0x36737751;
  C = C ^ 0x7464596D;
  D = D ^ 0x34334E43;
/*
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
    P5C = P28[5];
    P64 = P28[10];
    A = BASE98[P28[15]] ^ BASE7C[P64] ^ BASE60[P5C] ^ BASE44[P28[0]] ^ BASE17C[P18];

    P5C = P28[9];
    P64 = P28[14];
    P6C = P28[3];
    B = BASE17C[P18 + 1] ^ BASE98[P6C] ^ BASE7C[P64] ^ BASE60[P5C] ^ BASE44[P28[4]];

    P5C = P28[13];
    P64 = P28[2];
    P6C = P28[7];
    C = BASE17C[P18 + 2] ^ BASE98[P6C] ^ BASE7C[P64] ^ BASE60[P5C] ^ BASE44[P28[8]];

    P5C = P28[1];
    P64 = P28[6];
    P6C = P28[11];
    D = BASE17C[P18 + 3] ^ BASE98[P6C] ^ BASE7C[P64] ^ BASE60[P5C] ^ BASE44[P28[12]];

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

  P5C = P28[5];
  P64 = P28[10];

  ECX = BASEB4[P64];
  EDX = BASEB4[P28[0]];
  ECX = ECX & 0xFF0000;
  EDX = EDX & 0xFF;
  ECX = ECX ^ EDX;
  EDX = BASEB4[P28[15]];
  EDX = EDX & 0xFF000000;
  ECX = ECX ^ EDX;
  EAX = BASEB4[P5C];
  EAX = EAX & 0xFF00;
  ECX = ECX ^ EAX;
  ECX = ECX ^ BASE17C[P18];
  A = ECX;

  P5C = P28[9];
  P64 = P28[14];
  P6C = P28[3];

  EDX = BASEB4[P64];
  ECX = BASEB4[P28[4]];
  EDX = EDX & 0xFF0000;
  ECX = ECX & 0xFF;
  EDX = EDX ^ ECX;
  ECX = BASEB4[P6C];
  ECX = ECX & 0xFF000000;
  EDX = EDX ^ ECX;
  EAX = BASEB4[P5C];
  EAX = EAX & 0xFF00;
  EBX = BASE17C[P18 + 1];
  EDX = EDX ^ EAX;
  EDX = EDX ^ EBX;
  B = EDX;

  P5C = P28[13];
  P64 = P28[2];
  P6C = P28[7];

  ECX = BASEB4[P64];
  EDX = BASEB4[P28[8]];
  ECX = ECX & 0xFF0000;
  EDX = EDX & 0xFF;
  ECX = ECX ^ EDX;
  EDX = BASEB4[P6C];
  EDX = EDX & 0xFF000000;
  ECX = ECX ^ EDX;
  EAX = BASEB4[P5C];
  EAX = EAX & 0xFF00;
  EBX = BASE17C[P18 + 2];
  ECX = ECX ^ EAX;
  ECX = ECX ^ EBX;
  C = ECX;

  P5C = P28[1];
  P64 = P28[6];
  P6C = P28[11];

  EDX = BASEB4[P64];
  ECX = BASEB4[P28[12]];
  EDX = EDX & 0xFF0000;
  ECX = ECX & 0xFF;
  EDX = EDX ^ ECX;
  ECX = BASEB4[P6C];
  ECX = ECX & 0xFF000000;
  EDX = EDX ^ ECX;
  EAX = BASEB4[P5C];
  EAX = EAX & 0xFF00;
  EBX = BASE17C[P18 + 3];
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

  oStr = "";
  for(int i = 0; i < 16; ++i){
    char tmp[3];
    sprintf(tmp, "%X", P28[i]);
    std::string agent = tmp;
    if(agent.length() == 1){
      oStr.append("0");
    }
    oStr.append(agent);
  }

  return 0;
}

int EnCode(const std::string& pStr, std::string& oStr){
  std::string tmp = pStr;
  trim(tmp);

  oStr = "";
  std::string input, output;
  for(int i = 0; i < tmp.length(); i += 16){
    if(i != 0){
      oStr.append(" ");
    }
    input = tmp.substr(i, 16);
    output = "";
    EnCodeHandle(input, output);
    oStr.append(output);
  }

  return 0;
}

// for python call
extern "C"
const char* python(const char input[]) {
  std::string pStr = input, oStr = "";
  EnCode(pStr, oStr);
  return oStr.c_str();
}

int main(int argc, char const *argv[]) {
  if(argc >= 2){
    std::string pStr, oStr;
    for(int i = 1; i < argc; ++i){
      pStr = argv[i];
      oStr = "";
      EnCode(pStr, oStr); // EnCode returns 0
      std::cout << oStr << std::endl;
    }
  }
  else{
    std::cout << "usage: encode [text] ..." << std::endl;
    std::cout << "Options and arguments:" << std::endl;
    std::cout << "text ...   : text to encode" << std::endl;
  }
  return 0;
}
