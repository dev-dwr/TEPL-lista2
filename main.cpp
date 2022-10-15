#include <iostream>
#include "main.h"

class CTable {
private:
    std::string s_name;
    int *array;
    int tableSize;
public:
    CTable() {
        s_name = DEFAULT_S_NAME;
        std::cout << "bezp: " + s_name << std::endl;
        array = new int[DEFAULT_ARRAY_LENGTH];
    }

    CTable(std::string sName, int iTableLen) {
        if (sName.empty()) {
            std::cout << "enter non empty string" << std::endl;
            return;
        }
        if (iTableLen < 0) {
            std::cout << "table size must be positive" << std::endl;
            return;
        }
        tableSize = iTableLen;
        s_name = sName;
        std::cout << "parameter: " + s_name << std::endl;
        array = new int[iTableLen];
    }

    CTable(const CTable &pcOther) { // kopiujacy
        s_name = pcOther.s_name + "_copy";
        tableSize = pcOther.tableSize;
        std::cout << "copy: " + s_name << std::endl;
        array = pcOther.array;
    }

//    ~CTable() {
//        std::cout << "usuwam: " + s_name << std::endl;
//    }

    void setName(std::string sName) {
        if (sName.empty()) {
            std::cout << "enter non empty string" << std::endl;
            return;
        }
        s_name = sName;
    }

    bool bSetNewSize(int iTableLen) {
        if (iTableLen < 0) {
            std::cout << "we did not changed array size, reason: negative num" << std::endl;
            return false;
        }
        array = new int[iTableLen];
        tableSize = iTableLen;
        std::cout << "we changed array size bSetNewSize: " << iTableLen << std::endl;
        return true;
    }

    CTable *pcClone() {
        CTable *clone;
        clone = new CTable(s_name, tableSize);
        return clone;
    }


    void operator=(const CTable &pcOther) {
        array = pcOther.array;
        tableSize = pcOther.tableSize;
        std::cout << "we changed array size : " << tableSize << std::endl;
    }

    void vSetValueAt(int iOffset, int iNewVal) {
        array[iOffset] = iNewVal;
    }

    void vPrint() {
        for (int i = 0; i < tableSize; i++) {
            std::cout << array[i] << std::ends;
        }
    }

    CTable operator+(const CTable &pcOther1) {
        int newSize = pcOther1.tableSize + tableSize;
        int newArr[newSize];
        for(int i = 0; i< newSize; i++){
            if(i < tableSize){
                newArr[i] = array[i];
            }else{
                newArr[i] = pcOther1.array[i-tableSize];
            }
        }
        array = newArr;
        return CTable();
    }

};

int main() {

    CTable c_tab_0, c_tab_1;
    c_tab_0.bSetNewSize(6);
    c_tab_1.bSetNewSize(4);
    // z deknstruktorem program zaincjalizowal obiekty zmienil size tablicy i usunal obiekty  // bez deknstruktora program nie usunal obiektow po zakonsczeniu
    //initialize c_tab_1 table
    c_tab_1.vSetValueAt(0, 51);
    c_tab_1.vSetValueAt(1, 52);
    c_tab_1.vSetValueAt(2, 53);
    c_tab_1.vSetValueAt(3, 54);

    c_tab_0.vSetValueAt(0, 1);
    c_tab_0.vSetValueAt(1, 2);
    c_tab_0.vSetValueAt(2, 3);
    c_tab_0.vSetValueAt(3, 4);
    c_tab_0.vSetValueAt(4, 5);
    c_tab_0.vSetValueAt(5, 6);

    c_tab_0 = c_tab_1;
    c_tab_1.vSetValueAt(2, 123);
    c_tab_0.vPrint();
    std::cout << "\n" << std::endl;
    c_tab_1.vPrint();

    CTable c_tab_res;
    c_tab_0+c_tab_1;


    return 0;
}
