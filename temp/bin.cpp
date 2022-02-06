#include <iostream>
#include <string>
using namespace std;

string getPadding(int num) {
    string padding = "";
    while(num--) padding += '0';
    return padding;
}
string decToBin(int dec) {
    string bin = "";
    
    while(dec != 0) {
        bin = to_string(dec % 2) + bin;
        dec /= 2;
    }

    return bin;
}

string addBin(string bin1, string bin2) {
    string res = "", tmp;
    int i, j;
    bool ups = false;

    if(bin1.length() < bin2.length()){
        tmp = bin1;
        bin1 = bin2;
        bin2 = tmp;
    }
    
    if(bin2.length() == 0)  return bin1;

    for(i = bin2.length() - 1; 0 <= i; i--) {
        j = i + bin1.length() - bin2.length();

        if(ups){
            if(bin1[j] == '0' && bin2[i] == '0') {
                res = '1' + res;
                ups = false;
            }
            else if(bin1[j] == '1' && bin2[i] == '1') res = '1' + res;
            else {
                res = '0' + res;
                ups = true;
            }
        }
        else {
            if(bin1[j] == '0' && bin2[i] == '0') res = '0' + res;
            else if(bin1[j] == '1' && bin2[i] == '1') {
                res = '0' + res;
                ups = true;
            }
            else res = '1' + res;
        }
    }

    for(j--; 0 <= j; j--) {
        if(ups) {
            if(bin1[j] == '0') {
                res = '1' + res;
                ups = false;
            }
            if(bin1[j] == '1') res = '0' + res;
        }
        else {
            if(bin1[j] == '0') res = '0' + res;
            else res = '1' + res;
        }
    }

    if(ups) res = '1' + res;

    return res;
}

string mulBin(string bin1, string bin2) {
    string res = "", tmp;

    if(bin1.length() < bin2.length()){
        tmp = bin1;
        bin1 = bin2;
        bin2 = tmp;
    }

    for(int i = bin2.length() - 1; 0 <= i; i--) {
        int padding = bin2.length() - 1 - i;
        if(bin2[i] == '1') 
            res = addBin(res, bin1 + getPadding(padding));
    }
    
    return res;
}

int main() {
    cout << decToBin(1e9) << '\n';
    cout << addBin("111", "1001") << '\n';
    cout << mulBin("111011100110101100101000000000", "111011100110101100101000000000") << '\n';
    return 0;
}

112211221111221122111122112211112211221111221122111122112211
1152921504606846975