#include<iostream>
#include<string>

using namespace std;

int main()
{
    string str1 = "UTM Skudai";
    int len = str1.length(); // tak declare pon takpe
    cout << "str1: " << str1 << endl;
    cout << "len (str1.length): " <<str1.length() <<endl;

    str1 = "UTM ";
    string str2 = "Skudai ";
    
    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;

    str1.append(str2);
    cout << "str1.append(str2): " << str1 << endl;

    str2.append(str1);
    cout << "str2.append(str1): " << str2 << endl;

    string str3 = "Skudai";
    string str4("UTM JOHOR"); // str4 has “UTM Johor”
    // insert str3 into str4 starting at position 4
    str4.insert(6, str3); // str4 becomes “UTM Skudai Johor”
    cout << "str4: " << str4 << endl;

    string name = "UTM Sanjugan Bangsa";
    string sub = name.substr(4,9);
    cout << "sub: " << sub << endl;

    sub = name.substr(3,15);
    cout << "sub: " << sub << endl;

    system("pause");
    return 0;
}
